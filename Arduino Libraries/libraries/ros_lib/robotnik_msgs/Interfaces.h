#ifndef _ROS_robotnik_msgs_Interfaces_h
#define _ROS_robotnik_msgs_Interfaces_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/Data.h"

namespace robotnik_msgs
{

  class Interfaces : public ros::Msg
  {
    public:
      typedef robotnik_msgs::Data _total_type;
      _total_type total;
      uint32_t interfaces_length;
      typedef robotnik_msgs::Data _interfaces_type;
      _interfaces_type st_interfaces;
      _interfaces_type * interfaces;

    Interfaces():
      total(),
      interfaces_length(0), interfaces(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->total.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->interfaces_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->interfaces_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->interfaces_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->interfaces_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->interfaces_length);
      for( uint32_t i = 0; i < interfaces_length; i++){
      offset += this->interfaces[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->total.deserialize(inbuffer + offset);
      uint32_t interfaces_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      interfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      interfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      interfaces_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->interfaces_length);
      if(interfaces_lengthT > interfaces_length)
        this->interfaces = (robotnik_msgs::Data*)realloc(this->interfaces, interfaces_lengthT * sizeof(robotnik_msgs::Data));
      interfaces_length = interfaces_lengthT;
      for( uint32_t i = 0; i < interfaces_length; i++){
      offset += this->st_interfaces.deserialize(inbuffer + offset);
        memcpy( &(this->interfaces[i]), &(this->st_interfaces), sizeof(robotnik_msgs::Data));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/Interfaces"; };
    const char * getMD5(){ return "2cae798f4cdadfdb2326b84ac55dc3ea"; };

  };

}
#endif