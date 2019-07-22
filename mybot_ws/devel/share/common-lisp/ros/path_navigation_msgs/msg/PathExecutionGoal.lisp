; Auto-generated. Do not edit!


(cl:in-package path_navigation_msgs-msg)


;//! \htmlinclude PathExecutionGoal.msg.html

(cl:defclass <PathExecutionGoal> (roslisp-msg-protocol:ros-message)
  ((path
    :reader path
    :initarg :path
    :type nav_msgs-msg:Path
    :initform (cl:make-instance 'nav_msgs-msg:Path))
   (id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0))
)

(cl:defclass PathExecutionGoal (<PathExecutionGoal>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PathExecutionGoal>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PathExecutionGoal)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name path_navigation_msgs-msg:<PathExecutionGoal> is deprecated: use path_navigation_msgs-msg:PathExecutionGoal instead.")))

(cl:ensure-generic-function 'path-val :lambda-list '(m))
(cl:defmethod path-val ((m <PathExecutionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_navigation_msgs-msg:path-val is deprecated.  Use path_navigation_msgs-msg:path instead.")
  (path m))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <PathExecutionGoal>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader path_navigation_msgs-msg:id-val is deprecated.  Use path_navigation_msgs-msg:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PathExecutionGoal>) ostream)
  "Serializes a message object of type '<PathExecutionGoal>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'path) ostream)
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PathExecutionGoal>) istream)
  "Deserializes a message object of type '<PathExecutionGoal>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'path) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PathExecutionGoal>)))
  "Returns string type for a message object of type '<PathExecutionGoal>"
  "path_navigation_msgs/PathExecutionGoal")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PathExecutionGoal)))
  "Returns string type for a message object of type 'PathExecutionGoal"
  "path_navigation_msgs/PathExecutionGoal")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PathExecutionGoal>)))
  "Returns md5sum for a message object of type '<PathExecutionGoal>"
  "cce59c5d0f6e0e63b18c43b102c3189f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PathExecutionGoal)))
  "Returns md5sum for a message object of type 'PathExecutionGoal"
  "cce59c5d0f6e0e63b18c43b102c3189f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PathExecutionGoal>)))
  "Returns full string definition for message of type '<PathExecutionGoal>"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# the path~%nav_msgs/Path path~%~%# (optional) an identifier for this path.~%int32 id~%~%~%================================================================================~%MSG: nav_msgs/Path~%#An array of poses that represents a Path for a robot to follow~%Header header~%geometry_msgs/PoseStamped[] poses~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PathExecutionGoal)))
  "Returns full string definition for message of type 'PathExecutionGoal"
  (cl:format cl:nil "# ====== DO NOT MODIFY! AUTOGENERATED FROM AN ACTION DEFINITION ======~%# the path~%nav_msgs/Path path~%~%# (optional) an identifier for this path.~%int32 id~%~%~%================================================================================~%MSG: nav_msgs/Path~%#An array of poses that represents a Path for a robot to follow~%Header header~%geometry_msgs/PoseStamped[] poses~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/PoseStamped~%# A Pose with reference coordinate frame and timestamp~%Header header~%Pose pose~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PathExecutionGoal>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'path))
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PathExecutionGoal>))
  "Converts a ROS message object to a list"
  (cl:list 'PathExecutionGoal
    (cl:cons ':path (path msg))
    (cl:cons ':id (id msg))
))
