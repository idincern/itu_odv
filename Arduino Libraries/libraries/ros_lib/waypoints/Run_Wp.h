#ifndef _ROS_SERVICE_Run_Wp_h
#define _ROS_SERVICE_Run_Wp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace waypoints
{

static const char RUN_WP[] = "waypoints/Run_Wp";

  class Run_WpRequest : public ros::Msg
  {
    public:
      typedef const char* _wp_name_type;
      _wp_name_type wp_name;
      typedef const char* _gr_name_type;
      _gr_name_type gr_name;
      typedef bool _loop_type;
      _loop_type loop;
      typedef int16_t _index_type;
      _index_type index;

    Run_WpRequest():
      wp_name(""),
      gr_name(""),
      loop(0),
      index(0)
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
      uint32_t length_gr_name = strlen(this->gr_name);
      varToArr(outbuffer + offset, length_gr_name);
      offset += 4;
      memcpy(outbuffer + offset, this->gr_name, length_gr_name);
      offset += length_gr_name;
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.real = this->loop;
      *(outbuffer + offset + 0) = (u_loop.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->loop);
      union {
        int16_t real;
        uint16_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_index.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->index);
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
      uint32_t length_gr_name;
      arrToVar(length_gr_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_gr_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_gr_name-1]=0;
      this->gr_name = (char *)(inbuffer + offset-1);
      offset += length_gr_name;
      union {
        bool real;
        uint8_t base;
      } u_loop;
      u_loop.base = 0;
      u_loop.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->loop = u_loop.real;
      offset += sizeof(this->loop);
      union {
        int16_t real;
        uint16_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_index.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->index = u_index.real;
      offset += sizeof(this->index);
     return offset;
    }

    const char * getType(){ return RUN_WP; };
    const char * getMD5(){ return "604bad90bb13db0cba7fd20abed2fc30"; };

  };

  class Run_WpResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;

    Run_WpResponse():
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

    const char * getType(){ return RUN_WP; };
    const char * getMD5(){ return "358e233cde0c8a8bcfea4ce193f8fc15"; };

  };

  class Run_Wp {
    public:
    typedef Run_WpRequest Request;
    typedef Run_WpResponse Response;
  };

}
#endif
