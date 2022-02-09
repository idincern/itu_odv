#ifndef _ROS_SERVICE_SetElevator_h
#define _ROS_SERVICE_SetElevator_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/ElevatorAction.h"

namespace robotnik_msgs
{

static const char SETELEVATOR[] = "robotnik_msgs/SetElevator";

  class SetElevatorRequest : public ros::Msg
  {
    public:
      typedef robotnik_msgs::ElevatorAction _action_type;
      _action_type action;

    SetElevatorRequest():
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

    const char * getType(){ return SETELEVATOR; };
    const char * getMD5(){ return "ba01edad69e94d31f2469c9b6db50a0e"; };

  };

  class SetElevatorResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    SetElevatorResponse():
      ret(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ret;
      u_ret.real = this->ret;
      *(outbuffer + offset + 0) = (u_ret.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ret);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ret;
      u_ret.base = 0;
      u_ret.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ret = u_ret.real;
      offset += sizeof(this->ret);
     return offset;
    }

    const char * getType(){ return SETELEVATOR; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class SetElevator {
    public:
    typedef SetElevatorRequest Request;
    typedef SetElevatorResponse Response;
  };

}
#endif
