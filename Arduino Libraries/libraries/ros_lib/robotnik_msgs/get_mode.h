#ifndef _ROS_SERVICE_get_mode_h
#define _ROS_SERVICE_get_mode_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char GET_MODE[] = "robotnik_msgs/get_mode";

  class get_modeRequest : public ros::Msg
  {
    public:

    get_modeRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return GET_MODE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class get_modeResponse : public ros::Msg
  {
    public:
      typedef int8_t _mode_type;
      _mode_type mode;

    get_modeResponse():
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

    const char * getType(){ return GET_MODE; };
    const char * getMD5(){ return "418c02483a8ca57215fb7b31c5c87234"; };

  };

  class get_mode {
    public:
    typedef get_modeRequest Request;
    typedef get_modeResponse Response;
  };

}
#endif
