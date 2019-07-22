// Generated by gencpp from file path_navigation_msgs/TransformPathExecutionResult.msg
// DO NOT EDIT!


#ifndef PATH_NAVIGATION_MSGS_MESSAGE_TRANSFORMPATHEXECUTIONRESULT_H
#define PATH_NAVIGATION_MSGS_MESSAGE_TRANSFORMPATHEXECUTIONRESULT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/PoseWithCovarianceStamped.h>

namespace path_navigation_msgs
{
template <class ContainerAllocator>
struct TransformPathExecutionResult_
{
  typedef TransformPathExecutionResult_<ContainerAllocator> Type;

  TransformPathExecutionResult_()
    : finalpose()  {
    }
  TransformPathExecutionResult_(const ContainerAllocator& _alloc)
    : finalpose(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator>  _finalpose_type;
  _finalpose_type finalpose;





  typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> const> ConstPtr;

}; // struct TransformPathExecutionResult_

typedef ::path_navigation_msgs::TransformPathExecutionResult_<std::allocator<void> > TransformPathExecutionResult;

typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionResult > TransformPathExecutionResultPtr;
typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionResult const> TransformPathExecutionResultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace path_navigation_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'control_msgs': ['/opt/ros/kinetic/share/control_msgs/cmake/../msg'], 'path_navigation_msgs': ['/home/adithya/Ros_practice/DiffDriveRobot/FromScarRobot/mybot_ws/devel/share/path_navigation_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6de191de1f3cf450e599cc31709760e6";
  }

  static const char* value(const ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6de191de1f3cf450ULL;
  static const uint64_t static_value2 = 0xe599cc31709760e6ULL;
};

template<class ContainerAllocator>
struct DataType< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "path_navigation_msgs/TransformPathExecutionResult";
  }

  static const char* value(const ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
# The actual end pose when the robot has finished navigating.\n\
geometry_msgs/PoseWithCovarianceStamped finalpose\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovarianceStamped\n\
# This expresses an estimated pose with a reference coordinate frame and timestamp\n\
\n\
Header header\n\
PoseWithCovariance pose\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/PoseWithCovariance\n\
# This represents a pose in free space with uncertainty.\n\
\n\
Pose pose\n\
\n\
# Row-major representation of the 6x6 covariance matrix\n\
# The orientation parameters use a fixed-axis representation.\n\
# In order, the parameters are:\n\
# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n\
float64[36] covariance\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Pose\n\
# A representation of pose in free space, composed of position and orientation. \n\
Point position\n\
Quaternion orientation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Quaternion\n\
# This represents an orientation in free space in quaternion form.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
float64 w\n\
";
  }

  static const char* value(const ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.finalpose);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TransformPathExecutionResult_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::path_navigation_msgs::TransformPathExecutionResult_<ContainerAllocator>& v)
  {
    s << indent << "finalpose: ";
    s << std::endl;
    Printer< ::geometry_msgs::PoseWithCovarianceStamped_<ContainerAllocator> >::stream(s, indent + "  ", v.finalpose);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PATH_NAVIGATION_MSGS_MESSAGE_TRANSFORMPATHEXECUTIONRESULT_H
