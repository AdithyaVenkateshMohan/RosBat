#/usr/bin/python
# script is written to test the sonar_gen with testing points
import sonar_gen
from matplotlib import pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import axes3d, Axes3D #<-- Note the capitalization! 
from datetime import datetime



import random
import math
from pprint import pprint

def random_on_sphere_points(r,num):
	points = []
	for i in range(0,num):
		z =  random.uniform(-r,r) 
		phi = random.uniform(0,2*math.pi)
		x = math.sqrt(r**2 - z**2)*math.cos(phi)
		y = math.sqrt(r**2 - z**2)*math.sin(phi)
		points.append([x,y,z])
	return points

# convex from observer
def regular_on_sphere_points(r, num , conditions = None):
	points = np.array([])
	#Break out if zero points
	if num==0:
		return points

	a = 4.0 * math.pi*(r**2.0 / num)
	d = math.sqrt(a)
	m_theta = int(round(math.pi / d))
	d_theta = math.pi / m_theta
	d_phi = a / d_theta

	for m in range(0,m_theta):
		theta = math.pi * (m + 0.5) / m_theta
		m_phi = int(round(2.0 * math.pi * math.sin(theta) / d_phi))
		for n in range(0,m_phi):
			phi = 2.0 * math.pi * n / m_phi
			if(n == 0 and m ==0):
				points = np.array([[r,phi,theta]])
			else:			
				points = np.append(points,np.array([[r,phi,theta]]), axis =0)
	return points


def convfromXYZtoPolar(X, Y , Z , angleunit = "deg"):
    R = np.power(np.power(X,2) + np.power(Y,2) + np.power(Z,2) , 1/2)
    SHi = np.arctan(Y/X)
    THeta = np.arccos(Z/R)

    if angleunit == "deg":
        SHi = np.degrees(SHi)
        THeta = 90 - np.degrees(THeta)

    return R , SHi , THeta


def generate_points_plane(boundingBox , centre , distance , resolution , cord = "polar"):
    # getting the width and length of the plane to be generated
    l = boundingBox[0]
    b = boundingBox[1]
    # getting the relative postions with respect to the emitter
    # this centre point on the plane is considered to in line of the emitter intially 
    # it's then translated according to cx , cy
    

    cx = centre[0]
    cy = centre[1]
    # distance 
    assert(distance >0)
    d = distance
    #resolution vr hr 
    vr = resolution[0]
    hr = resolution[1]
    print("no of points to be generated", (l/hr * b/vr))
    elev = 0
    i = vr
    j = hr
    points = np.array([[d ,0 , 0]])
    if (cord == "polar"):
        while i <= b/2:
            while j <= l/2:

                az = math.degrees(math.atan2(j,d))
                points = np.append(points ,[[d , az , elev], [d , -az , elev]], axis =0) # [d , az , -elev]  [d , -az , -elev]
                j+=hr
            i+=vr
            j=hr
            elev = math.degrees(math.atan2(i,d))
            #print(elev)
            d = d / math.cos(math.radians(elev))
            points = np.append(points, [[d , 0 , elev]], axis =0) #, [d , 0 , -elev]
    else:
        while i <= b/2:
            while j <= l/2:
                points = np.append(points,[[d , -j, -i] , [d , j, -i] , [d , -j, i], [d , j, i]], axis = 0)
                j+=hr
            
            i+=vr
            j=hr
            points = np.append(points, [[d , 0 , i] , [d , 0 , -i]], axis =0) #, [d , 0 , -elev]




    return points


#TestingCon ={"Dist":[1,5.1,.1], "Ele":[-math.pi/2,math.pi/2,math.pi/180], "Azi":[-math.pi/3,math.pi/3,math.pi/180]}
def testingSonar_SinglePtDrill(TestingCon = {"Dist":[1,5.1,.1], "Ele":[-90,90,1], "Azi":[-90,90,1]}):
    d , a , e  = sonar_gen.test_echo_genration_SinglePt(TestingCon)
    print(d[:,0] , d[:,1] , d)
    if d.size:
        plt.figure(1)
        plt.title("\t -----Single Point Test---- \n the energy variations with Distance")
        plt.xlabel("Distance")
        plt.ylabel("Energy")
        plt.plot(d[:,1], d[:,0])
    
    if a.size:
        plt.figure(2)
        plt.title('\t -----Single Point Test---- \n the energy variations with Azimuth')
        plt.xlabel('Azimuth')
        plt.ylabel('Energy')
        plt.plot(a[:,1], a[:,0])
    
    if e.size:
        plt.figure(3)
        plt.title('\t -----Single Point Test---- \n the energy variations with Elevation')
        plt.xlabel('Elevation')
        plt.ylabel('Energy')
        plt.plot(e[:,1], e[:,0])

    plt.show() 

def showSample_wall3d(distance = 5):
    print("Evenly distributed points")
    regular_surf_points = generate_points_plane([2,2], [2,2], 4 ,[0.1,0.1])
    regular_surf_points2 = generate_points_plane([2,2], [2,2], distance ,[0.2,0.4] , cord = "cart")
    print("generated sphere points",regular_surf_points, np.shape(regular_surf_points))

    fig = plt.figure(1)
    fig2 = plt.figure(2)
    fig3 = plt.figure(3)
    axp = fig3.add_subplot(122, projection = "polar")
    axp2 = fig3.add_subplot(121, projection = "polar")

    ax = Axes3D(fig)
    ax2 = Axes3D(fig2)

    #ax3 = Axes3D(axp)

    R = regular_surf_points[:,0]
    PHI = np.radians(regular_surf_points[:,2])
    THETA = np.radians(regular_surf_points[:,1])


    X2 = regular_surf_points2[:,0]
    Y2 = regular_surf_points2[:,1]
    Z2 = regular_surf_points2[:,2]
    R2, Shi , The = convfromXYZtoPolar(X2 , Y2 ,Z2 , angleunit= "deg")

    print("point out structure", PHI.shape, THETA.shape)
    X = R * np.sin(PHI) * np.cos(THETA)
    Y = R * np.sin(PHI) * np.sin(THETA)
    Z = R * np.cos(PHI)

    # X2 = R2 * np.sin(PHI2) * np.cos(THETA2)
    # Y2 = R2 * np.sin(PHI2) * np.sin(THETA2)
    # Z2 = R2 * np.cos(PHI2)

    print(X.shape , Y2.shape , Z.shape)

    # Plot the surface.
    ax.scatter(X, Y, Z, cmap=plt.cm.YlGnBu_r)

    ax2.scatter(X2, Y2, Z2, cmap=plt.cm.YlGnBu_r)
    print(R2 , Shi , The )
    
    axp.scatter(np.radians(Shi), R2)
    axp2.scatter(np.radians(The), R2)

    ax2.scatter(0, 0, 0, c = 'r' , marker = 'D')

    # Tweak the limits and add latex math labels.
    ax.set_xlabel(r'$\phi_\mathrm{real}$')
    ax.set_ylabel(r'$\phi_\mathrm{im}$')
    ax.set_zlabel(r'$V(\phi)$')

    plt.show()



    energy = sonar_gen.MultiPt_Test_echo_generation(R2, Shi , The )
    print("the energy of the test convex sphere echo is ", energy)

 #this is where the resolution vs energy test takes place
def testingSonar_SpacialResolutionvsEnergy():
    energyWnum = np.array([])
    Num = np.array([])
    Results = np.empty((0,), dtype=[('energy', 'f4'),('numberpoints','f4')] )
    condition = [0.01 , 0.5]
    mul = 0.0003
    c = condition[0]
    while c <= condition[1]:
        regular_surf_points = generate_points_plane([2,2], [2,2], 2 ,[c,c] , cord = "cart")
        c+=mul
        X2 = regular_surf_points[:,0]
        Y2 = regular_surf_points[:,1]
        Z2 = regular_surf_points[:,2]
        R2, Shi , The = convfromXYZtoPolar(X2 , Y2 ,Z2 , angleunit= "deg")
        Num = np.append(Num , np.shape(regular_surf_points)[0])
        N = np.shape(regular_surf_points)[0]
        energy = sonar_gen.MultiPt_Test_echo_generation(R2, Shi, The )
        print("numer of points given",  N , "energy of the sonar",energy)
        energyWnum = np.append(energyWnum , energy)
        energytbs = np.array([(energy , N)] , dtype=[('energy', 'f4'),('numberpoints','f4')])
        Results = np.append(Results,energytbs)
    
    fig2 = plt.figure(2)
    plt.title("energy varx with input resolution")
    plt.xlabel("num of points")
    plt.ylabel("energy")
    plt.plot(Num, energyWnum)
    plt.show()
    #Results = energyWnum
    print(Results.shape)
    save_numpyarray(Results, name = "EnergyVsPts",type = "csv", FMT=['%f','%f'], HEADER = "energy, number of points")



def save_numpyarray(array , path = r"/home/adithya/Documents/rosBots/binResults/", name = "SamplePoints" , type = "bin" , FMT = ['%f', '%f', '%f'], HEADER = "R,Azimuth, Elevations" , commentOnData =""):
    now = datetime.now()
    dt_string = now.strftime("%d-%m-%Y--%H:%M:%S")
    if type == "bin":
        np.save(path+name+dt_string+".npy", array)
        print("given array is saved in "+ path + name)
    else:
        if type =='csv':
            np.savetxt(path+name+dt_string+".csv", array , delimiter=',', fmt = FMT , header=HEADER, comments= commentOnData)
        else:
            print("Errorrrrrrrrr in save")
               










if __name__ == "__main__":
    #testingSonar_SinglePtDrill()
    showSample_wall3d()
    showSample_wall3d(distance = 6)
    showSample_wall3d(distance= 3)
    
    #testingSonar_SpacialResolutionvsEnergy()
    

   
    

