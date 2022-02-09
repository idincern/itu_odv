#ifndef _ROS_robotnik_msgs_QueryAlarm_h
#define _ROS_robotnik_msgs_QueryAlarm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class QueryAlarm : public ros::Msg
  {
    public:
      typedef int32_t _alm_id_type;
      _alm_id_type alm_id;
      typedef const char* _alm_component_type;
      _alm_component_type alm_component;
      typedef const char* _alm_type_type;
      _alm_type_type alm_type;
      typedef const char* _alm_group_type;
      _alm_group_type alm_group;
      typedef const char* _alm_description_type;
      _alm_description_type alm_description;
      typedef const char* _alm_start_time_type;
      _alm_start_time_type alm_start_time;
      typedef const char* _alm_end_time_type;
      _alm_end_time_type alm_end_time;

    QueryAlarm():
      alm_id(0),
      alm_component(""),
      alm_type(""),
      alm_group(""),
      alm_description(""),
      alm_start_time(""),
      alm_end_time("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_alm_id;
      u_alm_id.real = this->alm_id;
      *(outbuffer + offset + 0) = (u_alm_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_alm_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_alm_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_alm_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alm_id);
      uint32_t length_alm_component = strlen(this->alm_component);
      varToArr(outbuffer + offset, length_alm_component);
      offset += 4;
      memcpy(outbuffer + offset, this->alm_component, length_alm_component);
      offset += length_alm_component;
      uint32_t length_alm_type = strlen(this->alm_type);
      varToArr(outbuffer + offset, length_alm_type);
      offset += 4;
      memcpy(outbuffer + offset, this->alm_type, length_alm_type);
      offset += length_alm_type;
      uint32_t length_alm_group = strlen(this->alm_group);
      varToArr(outbuffer + offset, length_alm_group);
      offset += 4;
      memcpy(outbuffer + offset, this->alm_group, length_alm_group);
      offset += length_alm_group;
      uint32_t length_alm_description = strlen(this->alm_description);
      varToArr(outbuffer + offset, length_alm_description);
      offset += 4;
      memcpy(outbuffer + offset, this->alm_description, length_alm_description);
      offset += length_alm_description;
      uint32_t length_alm_start_time = strlen(this->alm_start_time);
      varToArr(outbuffer + offset, length_alm_start_time);
      offset += 4;
      memcpy(outbuffer + offset, this->alm_start_time, length_alm_start_time);
      offset += length_alm_start_time;
      uint32_t length_alm_end_time = strlen(this->alm_end_time);
      varToArr(outbuffer + offset, length_alm_end_time);
      offset += 4;
      memcpy(outbuffer + offset, this->alm_end_time, length_alm_end_time);
      offset += length_alm_end_time;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_alm_id;
      u_alm_id.base = 0;
      u_alm_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_alm_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_alm_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_alm_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->alm_id = u_alm_id.real;
      offset += sizeof(this->alm_id);
      uint32_t length_alm_component;
      arrToVar(length_alm_component, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_alm_component; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_alm_component-1]=0;
      this->alm_component = (char *)(inbuffer + offset-1);
      offset += length_alm_component;
      uint32_t length_alm_type;
      arrToVar(length_alm_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_alm_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_alm_type-1]=0;
      this->alm_type = (char *)(inbuffer + offset-1);
      offset += length_alm_type;
      uint32_t length_alm_group;
      arrToVar(length_alm_group, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_alm_group; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_alm_group-1]=0;
      this->alm_group = (char *)(inbuffer + offset-1);
      offset += length_alm_group;
      uint32_t length_alm_description;
      arrToVar(length_alm_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_alm_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_alm_description-1]=0;
      this->alm_description = (char *)(inbuffer + offset-1);
      offset += length_alm_description;
      uint32_t length_alm_start_time;
      arrToVar(length_alm_start_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_alm_start_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_alm_start_time-1]=0;
      this->alm_start_time = (char *)(inbuffer + offset-1);
      offset += length_alm_start_time;
      uint32_t length_alm_end_time;
      arrToVar(length_alm_end_time, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_alm_end_time; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_alm_end_time-1]=0;
      this->alm_end_time = (char *)(inbuffer + offset-1);
      offset += length_alm_end_time;
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/QueryAlarm"; };
    const char * getMD5(){ return "f3c7e9979cb91a050b98067ffb98adff"; };

  };

}
#endif