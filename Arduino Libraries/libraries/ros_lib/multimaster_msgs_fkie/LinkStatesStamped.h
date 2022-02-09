#ifndef _ROS_multimaster_msgs_fkie_LinkStatesStamped_h
#define _ROS_multimaster_msgs_fkie_LinkStatesStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "multimaster_msgs_fkie/LinkState.h"

namespace multimaster_msgs_fkie
{

  class LinkStatesStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t links_length;
      typedef multimaster_msgs_fkie::LinkState _links_type;
      _links_type st_links;
      _links_type * links;

    LinkStatesStamped():
      header(),
      links_length(0), links(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->links_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->links_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->links_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->links_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->links_length);
      for( uint32_t i = 0; i < links_length; i++){
      offset += this->links[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t links_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      links_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      links_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      links_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->links_length);
      if(links_lengthT > links_length)
        this->links = (multimaster_msgs_fkie::LinkState*)realloc(this->links, links_lengthT * sizeof(multimaster_msgs_fkie::LinkState));
      links_length = links_lengthT;
      for( uint32_t i = 0; i < links_length; i++){
      offset += this->st_links.deserialize(inbuffer + offset);
        memcpy( &(this->links[i]), &(this->st_links), sizeof(multimaster_msgs_fkie::LinkState));
      }
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/LinkStatesStamped"; };
    const char * getMD5(){ return "b7c41a46488485ec6593097b0cabe904"; };

  };

}
#endif