#ifndef _ROS_SERVICE_DiscoverMasters_h
#define _ROS_SERVICE_DiscoverMasters_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "multimaster_msgs_fkie/ROSMaster.h"

namespace multimaster_msgs_fkie
{

static const char DISCOVERMASTERS[] = "multimaster_msgs_fkie/DiscoverMasters";

  class DiscoverMastersRequest : public ros::Msg
  {
    public:

    DiscoverMastersRequest()
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

    const char * getType(){ return DISCOVERMASTERS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class DiscoverMastersResponse : public ros::Msg
  {
    public:
      uint32_t masters_length;
      typedef multimaster_msgs_fkie::ROSMaster _masters_type;
      _masters_type st_masters;
      _masters_type * masters;

    DiscoverMastersResponse():
      masters_length(0), masters(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->masters_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->masters_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->masters_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->masters_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->masters_length);
      for( uint32_t i = 0; i < masters_length; i++){
      offset += this->masters[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t masters_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      masters_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      masters_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      masters_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->masters_length);
      if(masters_lengthT > masters_length)
        this->masters = (multimaster_msgs_fkie::ROSMaster*)realloc(this->masters, masters_lengthT * sizeof(multimaster_msgs_fkie::ROSMaster));
      masters_length = masters_lengthT;
      for( uint32_t i = 0; i < masters_length; i++){
      offset += this->st_masters.deserialize(inbuffer + offset);
        memcpy( &(this->masters[i]), &(this->st_masters), sizeof(multimaster_msgs_fkie::ROSMaster));
      }
     return offset;
    }

    const char * getType(){ return DISCOVERMASTERS; };
    const char * getMD5(){ return "bc7525cc24dd3b880f044a2cdfb95aad"; };

  };

  class DiscoverMasters {
    public:
    typedef DiscoverMastersRequest Request;
    typedef DiscoverMastersResponse Response;
  };

}
#endif
