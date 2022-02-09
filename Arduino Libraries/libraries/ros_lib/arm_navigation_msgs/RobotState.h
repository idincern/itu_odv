#ifndef _ROS_arm_navigation_msgs_RobotState_h
#define _ROS_arm_navigation_msgs_RobotState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/JointState.h"
#include "arm_navigation_msgs/MultiDOFJointState.h"

namespace arm_navigation_msgs
{

  class RobotState : public ros::Msg
  {
    public:
      typedef sensor_msgs::JointState _joint_state_type;
      _joint_state_type joint_state;
      typedef arm_navigation_msgs::MultiDOFJointState _multi_dof_joint_state_type;
      _multi_dof_joint_state_type multi_dof_joint_state;

    RobotState():
      joint_state(),
      multi_dof_joint_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->joint_state.serialize(outbuffer + offset);
      offset += this->multi_dof_joint_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->joint_state.deserialize(inbuffer + offset);
      offset += this->multi_dof_joint_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/RobotState"; };
    const char * getMD5(){ return "970d46b2ca41b9686adbdaeb592d97a7"; };

  };

}
#endif