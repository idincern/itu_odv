#ifndef _ROS_arm_navigation_msgs_JointTrajectoryWithLimits_h
#define _ROS_arm_navigation_msgs_JointTrajectoryWithLimits_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "arm_navigation_msgs/JointLimits.h"

namespace arm_navigation_msgs
{

  class JointTrajectoryWithLimits : public ros::Msg
  {
    public:
      typedef trajectory_msgs::JointTrajectory _trajectory_type;
      _trajectory_type trajectory;
      uint32_t limits_length;
      typedef arm_navigation_msgs::JointLimits _limits_type;
      _limits_type st_limits;
      _limits_type * limits;

    JointTrajectoryWithLimits():
      trajectory(),
      limits_length(0), limits(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->limits_length);
      for( uint32_t i = 0; i < limits_length; i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      uint32_t limits_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      limits_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->limits_length);
      if(limits_lengthT > limits_length)
        this->limits = (arm_navigation_msgs::JointLimits*)realloc(this->limits, limits_lengthT * sizeof(arm_navigation_msgs::JointLimits));
      limits_length = limits_lengthT;
      for( uint32_t i = 0; i < limits_length; i++){
      offset += this->st_limits.deserialize(inbuffer + offset);
        memcpy( &(this->limits[i]), &(this->st_limits), sizeof(arm_navigation_msgs::JointLimits));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/JointTrajectoryWithLimits"; };
    const char * getMD5(){ return "895b19c6fb0a363348299884c7a90c9d"; };

  };

}
#endif