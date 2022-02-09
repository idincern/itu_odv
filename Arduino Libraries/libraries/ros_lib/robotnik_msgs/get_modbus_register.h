#ifndef _ROS_SERVICE_get_modbus_register_h
#define _ROS_SERVICE_get_modbus_register_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char GET_MODBUS_REGISTER[] = "robotnik_msgs/get_modbus_register";

  class get_modbus_registerRequest : public ros::Msg
  {
    public:
      typedef int32_t _address_type;
      _address_type address;

    get_modbus_registerRequest():
      address(0)
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
     return offset;
    }

    const char * getType(){ return GET_MODBUS_REGISTER; };
    const char * getMD5(){ return "dff3ccdc45e0333e4e8a2e8d7bdf4f6a"; };

  };

  class get_modbus_registerResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;
      typedef uint16_t _value_type;
      _value_type value;

    get_modbus_registerResponse():
      ret(0),
      value(0)
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
      *(outbuffer + offset + 0) = (this->value >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value);
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
      this->value =  ((uint16_t) (*(inbuffer + offset)));
      this->value |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->value);
     return offset;
    }

    const char * getType(){ return GET_MODBUS_REGISTER; };
    const char * getMD5(){ return "538660b29f52203f8c773272f9bff3df"; };

  };

  class get_modbus_register {
    public:
    typedef get_modbus_registerRequest Request;
    typedef get_modbus_registerResponse Response;
  };

}
#endif
