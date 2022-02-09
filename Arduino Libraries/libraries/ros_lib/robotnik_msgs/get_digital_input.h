#ifndef _ROS_SERVICE_get_digital_input_h
#define _ROS_SERVICE_get_digital_input_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char GET_DIGITAL_INPUT[] = "robotnik_msgs/get_digital_input";

  class get_digital_inputRequest : public ros::Msg
  {
    public:
      typedef int8_t _input_type;
      _input_type input;

    get_digital_inputRequest():
      input(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_input;
      u_input.real = this->input;
      *(outbuffer + offset + 0) = (u_input.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->input);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_input;
      u_input.base = 0;
      u_input.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->input = u_input.real;
      offset += sizeof(this->input);
     return offset;
    }

    const char * getType(){ return GET_DIGITAL_INPUT; };
    const char * getMD5(){ return "1491ea77b99fb7b24d088237597e6386"; };

  };

  class get_digital_inputResponse : public ros::Msg
  {
    public:
      typedef bool _value_type;
      _value_type value;

    get_digital_inputResponse():
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

    const char * getType(){ return GET_DIGITAL_INPUT; };
    const char * getMD5(){ return "e431d687bf4b2c65fbd94b12ae0cb5d9"; };

  };

  class get_digital_input {
    public:
    typedef get_digital_inputRequest Request;
    typedef get_digital_inputResponse Response;
  };

}
#endif
