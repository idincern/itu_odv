#ifndef _ROS_SERVICE_Delete_Wp_h
#define _ROS_SERVICE_Delete_Wp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace waypoints
{

static const char DELETE_WP[] = "waypoints/Delete_Wp";

  class Delete_WpRequest : public ros::Msg
  {
    public:
      typedef const char* _wp_name_type;
      _wp_name_type wp_name;

    Delete_WpRequest():
      wp_name("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_wp_name = strlen(this->wp_name);
      varToArr(outbuffer + offset, length_wp_name);
      offset += 4;
      memcpy(outbuffer + offset, this->wp_name, length_wp_name);
      offset += length_wp_name;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_wp_name;
      arrToVar(length_wp_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_wp_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_wp_name-1]=0;
      this->wp_name = (char *)(inbuffer + offset-1);
      offset += length_wp_name;
     return offset;
    }

    const char * getType(){ return DELETE_WP; };
    const char * getMD5(){ return "a284afe871109adda1de76fc331e5a94"; };

  };

  class Delete_WpResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    Delete_WpResponse():
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

    const char * getType(){ return DELETE_WP; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class Delete_Wp {
    public:
    typedef Delete_WpRequest Request;
    typedef Delete_WpResponse Response;
  };

}
#endif
