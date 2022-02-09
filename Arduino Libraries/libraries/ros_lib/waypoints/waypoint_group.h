#ifndef _ROS_waypoints_waypoint_group_h
#define _ROS_waypoints_waypoint_group_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace waypoints
{

  class waypoint_group : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      uint32_t wp_list_length;
      typedef char* _wp_list_type;
      _wp_list_type st_wp_list;
      _wp_list_type * wp_list;

    waypoint_group():
      name(""),
      wp_list_length(0), wp_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      *(outbuffer + offset + 0) = (this->wp_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->wp_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->wp_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->wp_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->wp_list_length);
      for( uint32_t i = 0; i < wp_list_length; i++){
      uint32_t length_wp_listi = strlen(this->wp_list[i]);
      varToArr(outbuffer + offset, length_wp_listi);
      offset += 4;
      memcpy(outbuffer + offset, this->wp_list[i], length_wp_listi);
      offset += length_wp_listi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t wp_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      wp_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      wp_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      wp_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->wp_list_length);
      if(wp_list_lengthT > wp_list_length)
        this->wp_list = (char**)realloc(this->wp_list, wp_list_lengthT * sizeof(char*));
      wp_list_length = wp_list_lengthT;
      for( uint32_t i = 0; i < wp_list_length; i++){
      uint32_t length_st_wp_list;
      arrToVar(length_st_wp_list, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_wp_list; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_wp_list-1]=0;
      this->st_wp_list = (char *)(inbuffer + offset-1);
      offset += length_st_wp_list;
        memcpy( &(this->wp_list[i]), &(this->st_wp_list), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "waypoints/waypoint_group"; };
    const char * getMD5(){ return "c03d3488d6139e5ffcdaeff205e40b93"; };

  };

}
#endif