#ifndef _ROS_SERVICE_GetRobotState_h
#define _ROS_SERVICE_GetRobotState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/RobotState.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"

namespace arm_navigation_msgs
{

static const char GETROBOTSTATE[] = "arm_navigation_msgs/GetRobotState";

  class GetRobotStateRequest : public ros::Msg
  {
    public:

    GetRobotStateRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GETROBOTSTATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetRobotStateResponse : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;
      typedef arm_navigation_msgs::ArmNavigationErrorCodes _error_code_type;
      _error_code_type error_code;

    GetRobotStateResponse():
      robot_state(),
      error_code()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_state.serialize(outbuffer + offset);
      offset += this->error_code.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_state.deserialize(inbuffer + offset);
      offset += this->error_code.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETROBOTSTATE; };
    const char * getMD5(){ return "9799d82a26586bf3963962b7c3038f40"; };

  };

  class GetRobotState {
    public:
    typedef GetRobotStateRequest Request;
    typedef GetRobotStateResponse Response;
  };

}
#endif
