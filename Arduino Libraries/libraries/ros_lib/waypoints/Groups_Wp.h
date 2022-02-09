#ifndef _ROS_SERVICE_Groups_Wp_h
#define _ROS_SERVICE_Groups_Wp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace waypoints
{

static const char GROUPS_WP[] = "waypoints/Groups_Wp";

  class Groups_WpRequest : public ros::Msg
  {
    public:
      typedef const char* _option_type;
      _option_type option;
      typedef const char* _group_name_type;
      _group_name_type group_name;

    Groups_WpRequest():
      option(""),
      group_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_option = strlen(this->option);
      varToArr(outbuffer + offset, length_option);
      offset += 4;
      memcpy(outbuffer + offset, this->option, length_option);
      offset += length_option;
      uint32_t length_group_name = strlen(this->group_name);
      varToArr(outbuffer + offset, length_group_name);
      offset += 4;
      memcpy(outbuffer + offset, this->group_name, length_group_name);
      offset += length_group_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_option;
      arrToVar(length_option, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_option; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_option-1]=0;
      this->option = (char *)(inbuffer + offset-1);
      offset += length_option;
      uint32_t length_group_name;
      arrToVar(length_group_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group_name-1]=0;
      this->group_name = (char *)(inbuffer + offset-1);
      offset += length_group_name;
     return offset;
    }

    const char * getType(){ return GROUPS_WP; };
    const char * getMD5(){ return "9f302dec009f435cabadb389876ca3e8"; };

  };

  class Groups_WpResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    Groups_WpResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    const char * getType(){ return GROUPS_WP; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class Groups_Wp {
    public:
    typedef Groups_WpRequest Request;
    typedef Groups_WpResponse Response;
  };

}
#endif
