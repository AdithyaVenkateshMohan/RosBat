import rospy 
import pcl 
from sensor_msgs.msg import PointCloud 
from geometry_msgs.msg import Point 
from datetime import datetime

import sensor_msgs.point_cloud2 as pc2


import numpy
from matplotlib import pyplot
from scipy.interpolate import interp1d
import library

import math



def echo_gen_Direct(distances , azimuths , elevations , sample_frequency = 125000):
    emission_level = 100
    emission_duration = 0.0025
    emission_frequency = 40000
    emitter_radius = 0.005
    absorption_coefficient = 1.318  # http://www.sengpielaudio.com/calculator-air.htm
    reflection_strength = -40
    speed_of_sound = 340

    emission_samples = int(sample_frequency * emission_duration)
    emission_time = numpy.linspace(0, emission_duration, emission_samples)
    emission = numpy.sin(2 * numpy.pi * emission_frequency * emission_time)
    window = library.signal_ramp(emission_samples, 10)
    emission = emission * window

    piston, degrees = library.pistonmodel(emission_frequency, radius=emitter_radius)
    piston = 10 * numpy.log10(piston)
    piston_function = interp1d(degrees, piston)

    # pyplot.figure()
    # pyplot.plot(degrees, piston)

    # %%
    # Get excentricities and echo delays

    excentricities = library.gca(azimuths, elevations, 0, 0)
    # @causing errors is this too  long for 
    delays = 2 * distances / speed_of_sound

    # %%
    # Calculate path losses
    loss_directionality = piston_function(excentricities)
    loss_attenuation = - 2 * distances * absorption_coefficient
    loss_spreading = -40 * numpy.log10(distances)

    echoes = emission_level + reflection_strength + loss_directionality + loss_attenuation + loss_spreading
    echoes_pa = library.db2pa(echoes)
    echoes_pa[echoes < 0] = 0

    # %%
    # Make impulse response

    impulse_time, impulse_response = library.make_impulse_response(delays, echoes_pa, emission_duration, sample_frequency)

    # pyplot.figure()
    # pyplot.plot(impulse_time, impulse_response)

    # %%
    # Make echo sequence
    echo_sequence = numpy.convolve(emission, impulse_response, mode='same')

    return echo_sequence, impulse_time

def echo_total_energycalulation(echo):
    return numpy.sum(numpy.power(echo,2))

# not yet defined 
def echo_time_window_energycalulation(echo , time_window , sample_frequency = 125000):
    Sample_frequency = sample_frequency
    window_size = int(time_window * Sample_frequency)
    windowed_energy = numpy.array([])
    echo = numpy.power(echo,2)
    for i in range(len(echo)):
        if window_size+ i < len(echo)-1:
            single_window = numpy.sum(echo[i:i+window_size])
        else:
            single_window = numpy.sum(echo[i:len(echo)])

        windowed_energy = numpy.append(windowed_energy, single_window)
    return windowed_energy

def save_numpyarray(array , path = r"/home/adithya/Documents/rosBots/binResults/", name = "SamplePoints" , type = "bin" , FMT = ['%f', '%f', '%f'], HEADER = ["R", "Azimuth", "Elevations"] , commentOnData =""):
    now = datetime.now()
    dt_string = now.strftime("%d-%m-%Y--%H:%M:%S")
    if type == "bin":
        numpy.save(path+name+dt_string+".npy", array)
        print("given array is saved in "+ path + name)
    else:
        if type =='csv':
            numpy.savetxt(path+name+dt_string+".csv", array , delimiter=',', fmt = FMT , header=HEADER, comments= commentOnData)
        else:
            print("Errorrrrrrrrr in save")