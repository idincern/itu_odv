#ifndef _ROS_SERVICE_set_float_value_h
#define _ROS_SERVICE_set_float_value_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/String.h"

namespace robotnik_msgs
{

static const char SET_FLOAT_VALUE[] = "robotnik_msgs/set_float_value";

  class set_float_valueRequest : public ros::Msg
  {
    public:
      typedef float _value_type;
      _value_type value;

    set_float_valueRequest():
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.real = this->value;
      *(outbuffer + offset + 0) = (u_value.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_value.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_value.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_value.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_value;
      u_value.base = 0;
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_value.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->value = u_value.real;
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return SET_FLOAT_VALUE; };
    const char * getMD5(){ return "0aca93dcf6d857f0e5a0dc6be1eaa9fb"; };

  };

  class set_float_valueResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;
      typedef std_msgs::String _errorMessage_type;
      _errorMessage_type errorMessage;

    set_float_valueResponse():
      ret(0),
      errorMessage()
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
      offset += this->errorMessage.serialize(outbuffer + offset);
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
      offset += this->errorMessage.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return SET_FLOAT_VALUE; };
    const char * getMD5(){ return "b607fdf6f13faab17a8c316347e7f65b"; };

  };

  class set_float_value {
    public:
    typedef set_float_valueRequest Request;
    typedef set_float_valueResponse Response;
  };

}
#endif
