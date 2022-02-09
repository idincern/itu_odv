#ifndef _ROS_SERVICE_set_modbus_register_h
#define _ROS_SERVICE_set_modbus_register_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char SET_MODBUS_REGISTER[] = "robotnik_msgs/set_modbus_register";

  class set_modbus_registerRequest : public ros::Msg
  {
    public:
      typedef int32_t _address_type;
      _address_type address;
      typedef uint16_t _value_type;
      _value_type value;

    set_modbus_registerRequest():
      address(0),
      value(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_address;
      u_address.real = this->address;
      *(outbuffer + offset + 0) = (u_address.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_address.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_address.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_address.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->address);
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_address;
      u_address.base = 0;
      u_address.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_address.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_address.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_address.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->address = u_address.real;
      offset += sizeof(this->address);
      this->value =  ((uint16_t) (*(inbuffer + offset)));
      this->value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return SET_MODBUS_REGISTER; };
    const char * getMD5(){ return "f6a5f26f6d6b4cf2de96262413c766f1"; };

  };

  class set_modbus_registerResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    set_modbus_registerResponse():
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

    const char * getType(){ return SET_MODBUS_REGISTER; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class set_modbus_register {
    public:
    typedef set_modbus_registerRequest Request;
    typedef set_modbus_registerResponse Response;
  };

}
#endif
