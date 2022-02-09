#ifndef _ROS_vision_msgs_VisionInfo_h
#define _ROS_vision_msgs_VisionInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace vision_msgs
{

  class VisionInfo : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _method_type;
      _method_type method;
      typedef const char* _database_location_type;
      _database_location_type database_location;
      typedef int32_t _database_version_type;
      _database_version_type database_version;

    VisionInfo():
      header(),
      method(""),
      database_location(""),
      database_version(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_method = strlen(this->method);
      varToArr(outbuffer + offset, length_method);
      offset += 4;
      memcpy(outbuffer + offset, this->method, length_method);
      offset += length_method;
      uint32_t length_database_location = strlen(this->database_location);
      varToArr(outbuffer + offset, length_database_location);
      offset += 4;
      memcpy(outbuffer + offset, this->database_location, length_database_location);
      offset += length_database_location;
      union {
        int32_t real;
        uint32_t base;
      } u_database_version;
      u_database_version.real = this->database_version;
      *(outbuffer + offset + 0) = (u_database_version.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_database_version.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_database_version.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_database_version.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->database_version);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_method;
      arrToVar(length_method, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_method; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_method-1]=0;
      this->method = (char *)(inbuffer + offset-1);
      offset += length_method;
      uint32_t length_database_location;
      arrToVar(length_database_location, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_database_location; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_database_location-1]=0;
      this->database_location = (char *)(inbuffer + offset-1);
      offset += length_database_location;
      union {
        int32_t real;
        uint32_t base;
      } u_database_version;
      u_database_version.base = 0;
      u_database_version.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_database_version.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_database_version.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_database_version.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->database_version = u_database_version.real;
      offset += sizeof(this->database_version);
     return offset;
    }

    const char * getType(){ return "vision_msgs/VisionInfo"; };
    const char * getMD5(){ return "eee36f8dc558754ceb4ef619179d8b34"; };

  };

}
#endif