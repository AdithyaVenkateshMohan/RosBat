// Generated by gencpp from file path_navigation_msgs/TransformPathExecutionActionGoal.msg
// DO NOT EDIT!


#ifndef PATH_NAVIGATION_MSGS_MESSAGE_TRANSFORMPATHEXECUTIONACTIONGOAL_H
#define PATH_NAVIGATION_MSGS_MESSAGE_TRANSFORMPATHEXECUTIONACTIONGOAL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <actionlib_msgs/GoalID.h>
#include <path_navigation_msgs/TransformPathExecutionGoal.h>

namespace path_navigation_msgs
{
template <class ContainerAllocator>
struct TransformPathExecutionActionGoal_
{
  typedef TransformPathExecutionActionGoal_<ContainerAllocator> Type;

  TransformPathExecutionActionGoal_()
    : header()
    , goal_id()
    , goal()  {
    }
  TransformPathExecutionActionGoal_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , goal_id(_alloc)
    , goal(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::actionlib_msgs::GoalID_<ContainerAllocator>  _goal_id_type;
  _goal_id_type goal_id;

   typedef  ::path_navigation_msgs::TransformPathExecutionGoal_<ContainerAllocator>  _goal_type;
  _goal_type goal;





  typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> const> ConstPtr;

}; // struct TransformPathExecutionActionGoal_

typedef ::path_navigation_msgs::TransformPathExecutionActionGoal_<std::allocator<void> > TransformPathExecutionActionGoal;

typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionActionGoal > TransformPathExecutionActionGoalPtr;
typedef boost::shared_ptr< ::path_navigation_msgs::TransformPathExecutionActionGoal const> TransformPathExecutionActionGoalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace path_navigation_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/kinetic/share/trajectory_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'control_msgs': ['/opt/ros/kinetic/share/control_msgs/cmake/../msg'], 'path_navigation_msgs': ['/home/adithya/Ros_practice/DiffDriveRobot/FromScarRobot/mybot_ws/devel/share/path_navigation_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f079496ab3986808d6711b0673b28cb2";
  }

  static const char* value(const ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf079496ab3986808ULL;
  static const uint64_t static_value2 = 0xd6711b0673b28cb2ULL;
};

template<class ContainerAllocator>
struct DataType< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "path_navigation_msgs/TransformPathExecutionActionGoal";
  }

  static const char* value(const ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
\n\
Header header\n\
actionlib_msgs/GoalID goal_id\n\
TransformPathExecutionGoal goal\n\
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
MSG: actionlib_msgs/GoalID\n\
# The stamp should store the time at which this goal was requested.\n\
# It is used by an action server when it tries to preempt all\n\
# goals that were requested before a certain time\n\
time stamp\n\
\n\
# The id provides a way to associate feedback and\n\
# result message with specific goal requests. The id\n\
# specified must be unique.\n\
string id\n\
\n\
\n\
================================================================================\n\
MSG: path_navigation_msgs/TransformPathExecutionGoal\n\
# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======\n\
# Execute a series of geometry_msgs/Transform points instead of\n\
# using a nav_msgs/Path.\n\
 \n\
Header header\n\
\n\
geometry_msgs/Transform[] transforms\n\
\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Transform\n\
# This represents the transform between two coordinate frames in free space.\n\
\n\
Vector3 translation\n\
Quaternion rotation\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
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

  static const char* value(const ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.goal_id);
      stream.next(m.goal);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TransformPathExecutionActionGoal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::path_navigation_msgs::TransformPathExecutionActionGoal_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "goal_id: ";
    s << std::endl;
    Printer< ::actionlib_msgs::GoalID_<ContainerAllocator> >::stream(s, indent + "  ", v.goal_id);
    s << indent << "goal: ";
    s << std::endl;
    Printer< ::path_navigation_msgs::TransformPathExecutionGoal_<ContainerAllocator> >::stream(s, indent + "  ", v.goal);
  }
};

} // namespace message_operations
} // namespace ros

#endif // PATH_NAVIGATION_MSGS_MESSAGE_TRANSFORMPATHEXECUTIONACTIONGOAL_H