#ifndef _ROS_multimaster_msgs_ClockOffset_h
#define _ROS_multimaster_msgs_ClockOffset_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace multimaster_msgs
{

  class ClockOffset : public ros::Msg
  {
    public:
      typedef ros::Duration _offset_type;
      _offset_type offset;

    ClockOffset():
      offset()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->offset.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset.sec);
      *(outbuffer + offset + 0) = (this->offset.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->offset.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->offset.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->offset.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->offset.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->offset.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->offset.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->offset.sec);
      this->offset.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->offset.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->offset.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->offset.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->offset.nsec);
     return offset;
    }

    const char * getType(){ return "multimaster_msgs/ClockOffset"; };
    const char * getMD5(){ return "485c4c76e694b808a31cd95e1e289acc"; };

  };

}
#endif