#ifndef _ROS_robotnik_msgs_alarmmonitor_h
#define _ROS_robotnik_msgs_alarmmonitor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class alarmmonitor : public ros::Msg
  {
    public:
      typedef const char* _type_type;
      _type_type type;
      typedef int32_t _display_type;
      _display_type display;
      typedef const char* _component_type;
      _component_type component;
      typedef bool _hmi_type;
      _hmi_type hmi;
      typedef const char* _group_type;
      _group_type group;
      typedef const char* _text_type;
      _text_type text;
      typedef uint64_t _seconds_active_type;
      _seconds_active_type seconds_active;

    alarmmonitor():
      type(""),
      display(0),
      component(""),
      hmi(0),
      group(""),
      text(""),
      seconds_active(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      union {
        int32_t real;
        uint32_t base;
      } u_display;
      u_display.real = this->display;
      *(outbuffer + offset + 0) = (u_display.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_display.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_display.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_display.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->display);
      uint32_t length_component = strlen(this->component);
      varToArr(outbuffer + offset, length_component);
      offset += 4;
      memcpy(outbuffer + offset, this->component, length_component);
      offset += length_component;
      union {
        bool real;
        uint8_t base;
      } u_hmi;
      u_hmi.real = this->hmi;
      *(outbuffer + offset + 0) = (u_hmi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->hmi);
      uint32_t length_group = strlen(this->group);
      varToArr(outbuffer + offset, length_group);
      offset += 4;
      memcpy(outbuffer + offset, this->group, length_group);
      offset += length_group;
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      *(outbuffer + offset + 0) = (this->seconds_active >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->seconds_active >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->seconds_active >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->seconds_active >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->seconds_active >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->seconds_active >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->seconds_active >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->seconds_active >> (8 * 7)) & 0xFF;
      offset += sizeof(this->seconds_active);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      union {
        int32_t real;
        uint32_t base;
      } u_display;
      u_display.base = 0;
      u_display.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_display.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_display.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_display.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->display = u_display.real;
      offset += sizeof(this->display);
      uint32_t length_component;
      arrToVar(length_component, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_component; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_component-1]=0;
      this->component = (char *)(inbuffer + offset-1);
      offset += length_component;
      union {
        bool real;
        uint8_t base;
      } u_hmi;
      u_hmi.base = 0;
      u_hmi.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->hmi = u_hmi.real;
      offset += sizeof(this->hmi);
      uint32_t length_group;
      arrToVar(length_group, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_group; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_group-1]=0;
      this->group = (char *)(inbuffer + offset-1);
      offset += length_group;
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
      this->seconds_active =  ((uint64_t) (*(inbuffer + offset)));
      this->seconds_active |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->seconds_active |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->seconds_active |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->seconds_active |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->seconds_active |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->seconds_active |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->seconds_active |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->seconds_active);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/alarmmonitor"; };
    const char * getMD5(){ return "bb3d91213f2300b7fc9bb9063b1a7b1e"; };

  };

}
#endif