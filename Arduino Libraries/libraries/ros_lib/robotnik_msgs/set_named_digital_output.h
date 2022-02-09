#ifndef _ROS_SERVICE_set_named_digital_output_h
#define _ROS_SERVICE_set_named_digital_output_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char SET_NAMED_DIGITAL_OUTPUT[] = "robotnik_msgs/set_named_digital_output";

  class set_named_digital_outputRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _value_type;
      _value_type value;

    set_named_digital_outputRequest():
      name(""),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
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
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
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

    const char * getType(){ return SET_NAMED_DIGITAL_OUTPUT; };
    const char * getMD5(){ return "23f05028c1a699fb83e22401228c3a9e"; };

  };

  class set_named_digital_outputResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    set_named_digital_outputResponse():
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

    const char * getType(){ return SET_NAMED_DIGITAL_OUTPUT; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class set_named_digital_output {
    public:
    typedef set_named_digital_outputRequest Request;
    typedef set_named_digital_outputResponse Response;
  };

}
#endif
