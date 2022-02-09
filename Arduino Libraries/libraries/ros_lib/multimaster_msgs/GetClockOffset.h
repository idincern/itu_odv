#ifndef _ROS_SERVICE_GetClockOffset_h
#define _ROS_SERVICE_GetClockOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "multimaster_msgs/ClockOffset.h"

namespace multimaster_msgs
{

static const char GETCLOCKOFFSET[] = "multimaster_msgs/GetClockOffset";

  class GetClockOffsetRequest : public ros::Msg
  {
    public:

    GetClockOffsetRequest()
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

    const char * getType(){ return GETCLOCKOFFSET; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetClockOffsetResponse : public ros::Msg
  {
    public:
      typedef multimaster_msgs::ClockOffset _clock_offset_type;
      _clock_offset_type clock_offset;

    GetClockOffsetResponse():
      clock_offset()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->clock_offset.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->clock_offset.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return GETCLOCKOFFSET; };
    const char * getMD5(){ return "35b033f8a955f6b4023ec3e1b61808c6"; };

  };

  class GetClockOffset {
    public:
    typedef GetClockOffsetRequest Request;
    typedef GetClockOffsetResponse Response;
  };

}
#endif
