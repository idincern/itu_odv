#ifndef _ROS_arm_navigation_msgs_AllowedCollisionMatrix_h
#define _ROS_arm_navigation_msgs_AllowedCollisionMatrix_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/AllowedCollisionEntry.h"

namespace arm_navigation_msgs
{

  class AllowedCollisionMatrix : public ros::Msg
  {
    public:
      uint32_t link_names_length;
      typedef char* _link_names_type;
      _link_names_type st_link_names;
      _link_names_type * link_names;
      uint32_t entries_length;
      typedef arm_navigation_msgs::AllowedCollisionEntry _entries_type;
      _entries_type st_entries;
      _entries_type * entries;

    AllowedCollisionMatrix():
      link_names_length(0), link_names(NULL),
      entries_length(0), entries(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->link_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_names_length);
      for( uint32_t i = 0; i < link_names_length; i++){
      uint32_t length_link_namesi = strlen(this->link_names[i]);
      varToArr(outbuffer + offset, length_link_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->link_names[i], length_link_namesi);
      offset += length_link_namesi;
      }
      *(outbuffer + offset + 0) = (this->entries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->entries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->entries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->entries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->entries_length);
      for( uint32_t i = 0; i < entries_length; i++){
      offset += this->entries[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t link_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->link_names_length);
      if(link_names_lengthT > link_names_length)
        this->link_names = (char**)realloc(this->link_names, link_names_lengthT * sizeof(char*));
      link_names_length = link_names_lengthT;
      for( uint32_t i = 0; i < link_names_length; i++){
      uint32_t length_st_link_names;
      arrToVar(length_st_link_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_link_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_link_names-1]=0;
      this->st_link_names = (char *)(inbuffer + offset-1);
      offset += length_st_link_names;
        memcpy( &(this->link_names[i]), &(this->st_link_names), sizeof(char*));
      }
      uint32_t entries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      entries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->entries_length);
      if(entries_lengthT > entries_length)
        this->entries = (arm_navigation_msgs::AllowedCollisionEntry*)realloc(this->entries, entries_lengthT * sizeof(arm_navigation_msgs::AllowedCollisionEntry));
      entries_length = entries_lengthT;
      for( uint32_t i = 0; i < entries_length; i++){
      offset += this->st_entries.deserialize(inbuffer + offset);
        memcpy( &(this->entries[i]), &(this->st_entries), sizeof(arm_navigation_msgs::AllowedCollisionEntry));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/AllowedCollisionMatrix"; };
    const char * getMD5(){ return "c5785d58d2d0b6270738f65222dbec5d"; };

  };

}
#endif