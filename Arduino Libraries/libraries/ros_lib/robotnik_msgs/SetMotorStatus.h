#ifndef _ROS_SERVICE_SetMotorStatus_h
#define _ROS_SERVICE_SetMotorStatus_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char SETMOTORSTATUS[] = "robotnik_msgs/SetMotorStatus";

  class SetMotorStatusRequest : public ros::Msg
  {
    public:
      typedef int8_t _status_type;
      _status_type status;

    SetMotorStatusRequest():
      status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.real = this->status;
      *(outbuffer + offset + 0) = (u_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_status;
      u_status.base = 0;
      u_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->status = u_status.real;
      offset += sizeof(this->status);
     return offset;
    }

    const char * getType(){ return SETMOTORSTATUS; };
    const char * getMD5(){ return "581cc55c12abfc219e446416014f6d0e"; };

  };

  class SetMotorStatusResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    SetMotorStatusResponse():
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

    const char * getType(){ return SETMOTORSTATUS; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class SetMotorStatus {
    public:
    typedef SetMotorStatusRequest Request;
    typedef SetMotorStatusResponse Response;
  };

}
#endif
