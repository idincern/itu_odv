#ifndef _ROS_robotnik_msgs_encoders_h
#define _ROS_robotnik_msgs_encoders_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class encoders : public ros::Msg
  {
    public:
      uint32_t type_length;
      typedef char* _type_type;
      _type_type st_type;
      _type_type * type;
      uint32_t counts_length;
      typedef int32_t _counts_type;
      _counts_type st_counts;
      _counts_type * counts;
      uint32_t vel_length;
      typedef int32_t _vel_type;
      _vel_type st_vel;
      _vel_type * vel;

    encoders():
      type_length(0), type(NULL),
      counts_length(0), counts(NULL),
      vel_length(0), vel(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->type_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->type_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->type_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->type_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type_length);
      for( uint32_t i = 0; i < type_length; i++){
      uint32_t length_typei = strlen(this->type[i]);
      varToArr(outbuffer + offset, length_typei);
      offset += 4;
      memcpy(outbuffer + offset, this->type[i], length_typei);
      offset += length_typei;
      }
      *(outbuffer + offset + 0) = (this->counts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->counts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->counts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->counts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->counts_length);
      for( uint32_t i = 0; i < counts_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_countsi;
      u_countsi.real = this->counts[i];
      *(outbuffer + offset + 0) = (u_countsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_countsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_countsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_countsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->counts[i]);
      }
      *(outbuffer + offset + 0) = (this->vel_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vel_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vel_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vel_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel_length);
      for( uint32_t i = 0; i < vel_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_veli;
      u_veli.real = this->vel[i];
      *(outbuffer + offset + 0) = (u_veli.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_veli.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_veli.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_veli.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t type_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      type_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->type_length);
      if(type_lengthT > type_length)
        this->type = (char**)realloc(this->type, type_lengthT * sizeof(char*));
      type_length = type_lengthT;
      for( uint32_t i = 0; i < type_length; i++){
      uint32_t length_st_type;
      arrToVar(length_st_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_type-1]=0;
      this->st_type = (char *)(inbuffer + offset-1);
      offset += length_st_type;
        memcpy( &(this->type[i]), &(this->st_type), sizeof(char*));
      }
      uint32_t counts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      counts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      counts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      counts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->counts_length);
      if(counts_lengthT > counts_length)
        this->counts = (int32_t*)realloc(this->counts, counts_lengthT * sizeof(int32_t));
      counts_length = counts_lengthT;
      for( uint32_t i = 0; i < counts_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_counts;
      u_st_counts.base = 0;
      u_st_counts.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_counts.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_counts.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_counts.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_counts = u_st_counts.real;
      offset += sizeof(this->st_counts);
        memcpy( &(this->counts[i]), &(this->st_counts), sizeof(int32_t));
      }
      uint32_t vel_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vel_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vel_length);
      if(vel_lengthT > vel_length)
        this->vel = (int32_t*)realloc(this->vel, vel_lengthT * sizeof(int32_t));
      vel_length = vel_lengthT;
      for( uint32_t i = 0; i < vel_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_vel;
      u_st_vel.base = 0;
      u_st_vel.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_vel.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_vel.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_vel.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_vel = u_st_vel.real;
      offset += sizeof(this->st_vel);
        memcpy( &(this->vel[i]), &(this->st_vel), sizeof(int32_t));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/encoders"; };
    const char * getMD5(){ return "b5def35e667417de284b17ffe2083938"; };

  };

}
#endif