#ifndef _ROS_SERVICE_GetRobotTrajectoryValidity_h
#define _ROS_SERVICE_GetRobotTrajectoryValidity_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/RobotState.h"
#include "arm_navigation_msgs/Constraints.h"
#include "arm_navigation_msgs/RobotTrajectory.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"

namespace arm_navigation_msgs
{

static const char GETROBOTTRAJECTORYVALIDITY[] = "arm_navigation_msgs/GetRobotTrajectoryValidity";

  class GetRobotTrajectoryValidityRequest : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::RobotTrajectory _trajectory_type;
      _trajectory_type trajectory;
      typedef arm_navigation_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;
      typedef bool _check_collisions_type;
      _check_collisions_type check_collisions;
      typedef bool _check_path_constraints_type;
      _check_path_constraints_type check_path_constraints;
      typedef bool _check_goal_constraints_type;
      _check_goal_constraints_type check_goal_constraints;
      typedef bool _check_joint_limits_type;
      _check_joint_limits_type check_joint_limits;
      typedef bool _check_full_trajectory_type;
      _check_full_trajectory_type check_full_trajectory;
      typedef arm_navigation_msgs::Constraints _path_constraints_type;
      _path_constraints_type path_constraints;
      typedef arm_navigation_msgs::Constraints _goal_constraints_type;
      _goal_constraints_type goal_constraints;

    GetRobotTrajectoryValidityRequest():
      trajectory(),
      robot_state(),
      check_collisions(0),
      check_path_constraints(0),
      check_goal_constraints(0),
      check_joint_limits(0),
      check_full_trajectory(0),
      path_constraints(),
      goal_constraints()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->robot_state.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_check_collisions;
      u_check_collisions.real = this->check_collisions;
      *(outbuffer + offset + 0) = (u_check_collisions.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_collisions);
      union {
        bool real;
        uint8_t base;
      } u_check_path_constraints;
      u_check_path_constraints.real = this->check_path_constraints;
      *(outbuffer + offset + 0) = (u_check_path_constraints.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_path_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_goal_constraints;
      u_check_goal_constraints.real = this->check_goal_constraints;
      *(outbuffer + offset + 0) = (u_check_goal_constraints.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_goal_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_joint_limits;
      u_check_joint_limits.real = this->check_joint_limits;
      *(outbuffer + offset + 0) = (u_check_joint_limits.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_joint_limits);
      union {
        bool real;
        uint8_t base;
      } u_check_full_trajectory;
      u_check_full_trajectory.real = this->check_full_trajectory;
      *(outbuffer + offset + 0) = (u_check_full_trajectory.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->check_full_trajectory);
      offset += this->path_constraints.serialize(outbuffer + offset);
      offset += this->goal_constraints.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->robot_state.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_check_collisions;
      u_check_collisions.base = 0;
      u_check_collisions.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_collisions = u_check_collisions.real;
      offset += sizeof(this->check_collisions);
      union {
        bool real;
        uint8_t base;
      } u_check_path_constraints;
      u_check_path_constraints.base = 0;
      u_check_path_constraints.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_path_constraints = u_check_path_constraints.real;
      offset += sizeof(this->check_path_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_goal_constraints;
      u_check_goal_constraints.base = 0;
      u_check_goal_constraints.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_goal_constraints = u_check_goal_constraints.real;
      offset += sizeof(this->check_goal_constraints);
      union {
        bool real;
        uint8_t base;
      } u_check_joint_limits;
      u_check_joint_limits.base = 0;
      u_check_joint_limits.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_joint_limits = u_check_joint_limits.real;
      offset += sizeof(this->check_joint_limits);
      union {
        bool real;
        uint8_t base;
      } u_check_full_trajectory;
      u_check_full_trajectory.base = 0;
      u_check_full_trajectory.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->check_full_trajectory = u_check_full_trajectory.real;
      offset += sizeof(this->check_full_trajectory);
      offset += this->path_constraints.deserialize(inbuffer + offset);
      offset += this->goal_constraints.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETROBOTTRAJECTORYVALIDITY; };
    const char * getMD5(){ return "6787c778fd53c95edad17e0ce5be9347"; };

  };

  class GetRobotTrajectoryValidityResponse : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::ArmNavigationErrorCodes _error_code_type;
      _error_code_type error_code;
      uint32_t trajectory_error_codes_length;
      typedef arm_navigation_msgs::ArmNavigationErrorCodes _trajectory_error_codes_type;
      _trajectory_error_codes_type st_trajectory_error_codes;
      _trajectory_error_codes_type * trajectory_error_codes;

    GetRobotTrajectoryValidityResponse():
      error_code(),
      trajectory_error_codes_length(0), trajectory_error_codes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->trajectory_error_codes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->trajectory_error_codes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->trajectory_error_codes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->trajectory_error_codes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->trajectory_error_codes_length);
      for( uint32_t i = 0; i < trajectory_error_codes_length; i++){
      offset += this->trajectory_error_codes[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
      uint32_t trajectory_error_codes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      trajectory_error_codes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      trajectory_error_codes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      trajectory_error_codes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->trajectory_error_codes_length);
      if(trajectory_error_codes_lengthT > trajectory_error_codes_length)
        this->trajectory_error_codes = (arm_navigation_msgs::ArmNavigationErrorCodes*)realloc(this->trajectory_error_codes, trajectory_error_codes_lengthT * sizeof(arm_navigation_msgs::ArmNavigationErrorCodes));
      trajectory_error_codes_length = trajectory_error_codes_lengthT;
      for( uint32_t i = 0; i < trajectory_error_codes_length; i++){
      offset += this->st_trajectory_error_codes.deserialize(inbuffer + offset);
        memcpy( &(this->trajectory_error_codes[i]), &(this->st_trajectory_error_codes), sizeof(arm_navigation_msgs::ArmNavigationErrorCodes));
      }
     return offset;
    }

    const char * getType(){ return GETROBOTTRAJECTORYVALIDITY; };
    const char * getMD5(){ return "6316c11e993d068a87f32bc2109e7658"; };

  };

  class GetRobotTrajectoryValidity {
    public:
    typedef GetRobotTrajectoryValidityRequest Request;
    typedef GetRobotTrajectoryValidityResponse Response;
  };

}
#endif
