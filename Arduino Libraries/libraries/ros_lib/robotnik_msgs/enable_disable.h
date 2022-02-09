#ifndef _ROS_SERVICE_enable_disable_h
#define _ROS_SERVICE_enable_disable_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char ENABLE_DISABLE[] = "robotnik_msgs/enable_disable";

  class enable_disableRequest : public ros::Msg
  {
    public:
      typedef bool _value_type;
      _value_type value;

    enable_disableRequest():
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return ENABLE_DISABLE; };
    const char * getMD5(){ return "e431d687bf4b2c65fbd94b12ae0cb5d9"; };

  };

  class enable_disableResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    enable_disableResponse():
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

    const char * getType(){ return ENABLE_DISABLE; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class enable_disable {
    public:
    typedef enable_disableRequest Request;
    typedef enable_disableResponse Response;
  };

}
#endif
