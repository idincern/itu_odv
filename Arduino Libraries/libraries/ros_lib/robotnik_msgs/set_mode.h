#ifndef _ROS_SERVICE_set_mode_h
#define _ROS_SERVICE_set_mode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char SET_MODE[] = "robotnik_msgs/set_mode";

  class set_modeRequest : public ros::Msg
  {
    public:
      typedef int8_t _mode_type;
      _mode_type mode;

    set_modeRequest():
      mode(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
     return offset;
    }

    const char * getType(){ return SET_MODE; };
    const char * getMD5(){ return "418c02483a8ca57215fb7b31c5c87234"; };

  };

  class set_modeResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    set_modeResponse():
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

    const char * getType(){ return SET_MODE; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class set_mode {
    public:
    typedef set_modeRequest Request;
    typedef set_modeResponse Response;
  };

}
#endif
