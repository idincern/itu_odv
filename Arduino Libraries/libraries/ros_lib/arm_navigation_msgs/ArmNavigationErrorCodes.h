#ifndef _ROS_arm_navigation_msgs_ArmNavigationErrorCodes_h
#define _ROS_arm_navigation_msgs_ArmNavigationErrorCodes_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_navigation_msgs
{

  class ArmNavigationErrorCodes : public ros::Msg
  {
    public:
      typedef int32_t _val_type;
      _val_type val;
      enum { PLANNING_FAILED = -1 };
      enum { SUCCESS = 1 };
      enum { TIMED_OUT = -2 };
      enum { START_STATE_IN_COLLISION = -3 };
      enum { START_STATE_VIOLATES_PATH_CONSTRAINTS = -4 };
      enum { GOAL_IN_COLLISION = -5 };
      enum { GOAL_VIOLATES_PATH_CONSTRAINTS = -6 };
      enum { INVALID_ROBOT_STATE = -7 };
      enum { INCOMPLETE_ROBOT_STATE = -8 };
      enum { INVALID_PLANNER_ID = -9 };
      enum { INVALID_NUM_PLANNING_ATTEMPTS = -10 };
      enum { INVALID_ALLOWED_PLANNING_TIME = -11 };
      enum { INVALID_GROUP_NAME = -12 };
      enum { INVALID_GOAL_JOINT_CONSTRAINTS = -13 };
      enum { INVALID_GOAL_POSITION_CONSTRAINTS = -14 };
      enum { INVALID_GOAL_ORIENTATION_CONSTRAINTS = -15 };
      enum { INVALID_PATH_JOINT_CONSTRAINTS = -16 };
      enum { INVALID_PATH_POSITION_CONSTRAINTS = -17 };
      enum { INVALID_PATH_ORIENTATION_CONSTRAINTS = -18 };
      enum { INVALID_TRAJECTORY = -19 };
      enum { INVALID_INDEX = -20 };
      enum { JOINT_LIMITS_VIOLATED = -21 };
      enum { PATH_CONSTRAINTS_VIOLATED = -22 };
      enum { COLLISION_CONSTRAINTS_VIOLATED = -23 };
      enum { GOAL_CONSTRAINTS_VIOLATED = -24 };
      enum { JOINTS_NOT_MOVING = -25 };
      enum { TRAJECTORY_CONTROLLER_FAILED = -26 };
      enum { FRAME_TRANSFORM_FAILURE = -27 };
      enum { COLLISION_CHECKING_UNAVAILABLE = -28 };
      enum { ROBOT_STATE_STALE = -29 };
      enum { SENSOR_INFO_STALE = -30 };
      enum { NO_IK_SOLUTION = -31 };
      enum { INVALID_LINK_NAME = -32 };
      enum { IK_LINK_IN_COLLISION = -33 };
      enum { NO_FK_SOLUTION = -34 };
      enum { KINEMATICS_STATE_IN_COLLISION = -35 };
      enum { INVALID_TIMEOUT = -36 };

    ArmNavigationErrorCodes():
      val(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_val;
      u_val.real = this->val;
      *(outbuffer + offset + 0) = (u_val.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_val.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_val.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_val.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->val);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_val;
      u_val.base = 0;
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_val.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->val = u_val.real;
      offset += sizeof(this->val);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/ArmNavigationErrorCodes"; };
    const char * getMD5(){ return "5acf26755415e1ec18a6d523028f204d"; };

  };

}
#endif