#ifndef _ROS_SERVICE_Wp_2_Group_h
#define _ROS_SERVICE_Wp_2_Group_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace waypoints
{

static const char WP_2_GROUP[] = "waypoints/Wp_2_Group";

  class Wp_2_GroupRequest : public ros::Msg
  {
    public:
      typedef const char* _option_type;
      _option_type option;
      typedef const char* _group_name_type;
      _group_name_type group_name;
      typedef const char* _wp_name_type;
      _wp_name_type wp_name;
      typedef int16_t _pos_type;
      _pos_type pos;

    Wp_2_GroupRequest():
      option(""),
      group_name(""),
      wp_name(""),
      pos(0)
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
      uint32_t length_wp_name = strlen(this->wp_name);
      varToArr(outbuffer + offset, length_wp_name);
      offset += 4;
      memcpy(outbuffer + offset, this->wp_name, length_wp_name);
      offset += length_wp_name;
      union {
        int16_t real;
        uint16_t base;
      } u_pos;
      u_pos.real = this->pos;
      *(outbuffer + offset + 0) = (u_pos.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pos.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->pos);
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
      uint32_t length_wp_name;
      arrToVar(length_wp_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_wp_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_wp_name-1]=0;
      this->wp_name = (char *)(inbuffer + offset-1);
      offset += length_wp_name;
      union {
        int16_t real;
        uint16_t base;
      } u_pos;
      u_pos.base = 0;
      u_pos.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pos.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->pos = u_pos.real;
      offset += sizeof(this->pos);
     return offset;
    }

    const char * getType(){ return WP_2_GROUP; };
    const char * getMD5(){ return "b14aac128bcd34eb39cbfe1ba82dbe55"; };

  };

  class Wp_2_GroupResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    Wp_2_GroupResponse():
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

    const char * getType(){ return WP_2_GROUP; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class Wp_2_Group {
    public:
    typedef Wp_2_GroupRequest Request;
    typedef Wp_2_GroupResponse Response;
  };

}
#endif
