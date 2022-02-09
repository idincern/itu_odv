#ifndef _ROS_SERVICE_FilterJointTrajectoryWithConstraints_h
#define _ROS_SERVICE_FilterJointTrajectoryWithConstraints_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/Constraints.h"
#include "ros/duration.h"
#include "trajectory_msgs/JointTrajectory.h"
#include "arm_navigation_msgs/JointLimits.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"
#include "arm_navigation_msgs/RobotState.h"

namespace arm_navigation_msgs
{

static const char FILTERJOINTTRAJECTORYWITHCONSTRAINTS[] = "arm_navigation_msgs/FilterJointTrajectoryWithConstraints";

  class FilterJointTrajectoryWithConstraintsRequest : public ros::Msg
  {
    public:
      typedef trajectory_msgs::JointTrajectory _trajectory_type;
      _trajectory_type trajectory;
      typedef const char* _group_name_type;
      _group_name_type group_name;
      uint32_t limits_length;
      typedef arm_navigation_msgs::JointLimits _limits_type;
      _limits_type st_limits;
      _limits_type * limits;
      typedef arm_navigation_msgs::RobotState _start_state_type;
      _start_state_type start_state;
      typedef arm_navigation_msgs::Constraints _path_constraints_type;
      _path_constraints_type path_constraints;
      typedef arm_navigation_msgs::Constraints _goal_constraints_type;
      _goal_constraints_type goal_constraints;
      typedef ros::Duration _allowed_time_type;
      _allowed_time_type allowed_time;

    FilterJointTrajectoryWithConstraintsRequest():
      trajectory(),
      group_name(""),
      limits_length(0), limits(NULL),
      start_state(),
      path_constraints(),
      goal_constraints(),
      allowed_time()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      *(outbuffer + offset + 0) = (this->limits_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->limits_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->limits_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->limits_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->limits_length);
      for( uint32_t i = 0; i < limits_length; i++){
      offset += this->limits[i].serialize(outbuffer + offset);
      }
      offset += this->start_state.serialize(outbuffer + offset);
      offset += this->path_constraints.serialize(outbuffer + offset);
      offset += this->goal_constraints.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->allowed_time.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_time.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_time.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_time.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_time.sec);
      *(outbuffer + offset + 0) = (this->allowed_time.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_time.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_time.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_time.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_time.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
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
      offset += this->start_state.deserialize(inbuffer + offset);
      offset += this->path_constraints.deserialize(inbuffer + offset);
      offset += this->goal_constraints.deserialize(inbuffer + offset);
      this->allowed_time.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_time.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_time.sec);
      this->allowed_time.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->allowed_time.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->allowed_time.nsec);
     return offset;
    }

    const char * getType(){ return FILTERJOINTTRAJECTORYWITHCONSTRAINTS; };
    const char * getMD5(){ return "4761ee5c109ab0a44849d5f9f4ff055c"; };

  };

  class FilterJointTrajectoryWithConstraintsResponse : public ros::Msg
  {
    public:
      typedef trajectory_msgs::JointTrajectory _trajectory_type;
      _trajectory_type trajectory;
      typedef arm_navigation_msgs::ArmNavigationErrorCodes _error_code_type;
      _error_code_type error_code;

    FilterJointTrajectoryWithConstraintsResponse():
      trajectory(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return FILTERJOINTTRAJECTORYWITHCONSTRAINTS; };
    const char * getMD5(){ return "b07a38e3291ec1857951df2bfd71735e"; };

  };

  class FilterJointTrajectoryWithConstraints {
    public:
    typedef FilterJointTrajectoryWithConstraintsRequest Request;
    typedef FilterJointTrajectoryWithConstraintsResponse Response;
  };

}
#endif
