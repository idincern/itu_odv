#ifndef _ROS_robotnik_msgs_SetElevatorGoal_h
#define _ROS_robotnik_msgs_SetElevatorGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/ElevatorAction.h"

namespace robotnik_msgs
{

  class SetElevatorGoal : public ros::Msg
  {
    public:
      typedef robotnik_msgs::ElevatorAction _action_type;
      _action_type action;

    SetElevatorGoal():
      action()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/SetElevatorGoal"; };
    const char * getMD5(){ return "ba01edad69e94d31f2469c9b6db50a0e"; };

  };

}
#endif