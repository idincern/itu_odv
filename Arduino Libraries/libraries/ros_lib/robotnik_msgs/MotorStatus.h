#ifndef _ROS_robotnik_msgs_MotorStatus_h
#define _ROS_robotnik_msgs_MotorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class MotorStatus : public ros::Msg
  {
    public:
      typedef const char* _state_type;
      _state_type state;
      typedef const char* _status_type;
      _status_type status;
      typedef const char* _communicationstatus_type;
      _communicationstatus_type communicationstatus;
      typedef const char* _statusword_type;
      _statusword_type statusword;
      typedef const char* _driveflags_type;
      _driveflags_type driveflags;
      uint32_t activestatusword_length;
      typedef char* _activestatusword_type;
      _activestatusword_type st_activestatusword;
      _activestatusword_type * activestatusword;
      uint32_t activedriveflags_length;
      typedef char* _activedriveflags_type;
      _activedriveflags_type st_activedriveflags;
      _activedriveflags_type * activedriveflags;
      typedef int32_t _digitaloutputs_type;
      _digitaloutputs_type digitaloutputs;
      typedef int32_t _digitalinputs_type;
      _digitalinputs_type digitalinputs;
      typedef float _averagecurrent_type;
      _averagecurrent_type averagecurrent;
      uint32_t analoginputs_length;
      typedef float _analoginputs_type;
      _analoginputs_type st_analoginputs;
      _analoginputs_type * analoginputs;

    MotorStatus():
      state(""),
      status(""),
      communicationstatus(""),
      statusword(""),
      driveflags(""),
      activestatusword_length(0), activestatusword(NULL),
      activedriveflags_length(0), activedriveflags(NULL),
      digitaloutputs(0),
      digitalinputs(0),
      averagecurrent(0),
      analoginputs_length(0), analoginputs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_state = strlen(this->state);
      varToArr(outbuffer + offset, length_state);
      offset += 4;
      memcpy(outbuffer + offset, this->state, length_state);
      offset += length_state;
      uint32_t length_status = strlen(this->status);
      varToArr(outbuffer + offset, length_status);
      offset += 4;
      memcpy(outbuffer + offset, this->status, length_status);
      offset += length_status;
      uint32_t length_communicationstatus = strlen(this->communicationstatus);
      varToArr(outbuffer + offset, length_communicationstatus);
      offset += 4;
      memcpy(outbuffer + offset, this->communicationstatus, length_communicationstatus);
      offset += length_communicationstatus;
      uint32_t length_statusword = strlen(this->statusword);
      varToArr(outbuffer + offset, length_statusword);
      offset += 4;
      memcpy(outbuffer + offset, this->statusword, length_statusword);
      offset += length_statusword;
      uint32_t length_driveflags = strlen(this->driveflags);
      varToArr(outbuffer + offset, length_driveflags);
      offset += 4;
      memcpy(outbuffer + offset, this->driveflags, length_driveflags);
      offset += length_driveflags;
      *(outbuffer + offset + 0) = (this->activestatusword_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->activestatusword_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->activestatusword_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->activestatusword_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->activestatusword_length);
      for( uint32_t i = 0; i < activestatusword_length; i++){
      uint32_t length_activestatuswordi = strlen(this->activestatusword[i]);
      varToArr(outbuffer + offset, length_activestatuswordi);
      offset += 4;
      memcpy(outbuffer + offset, this->activestatusword[i], length_activestatuswordi);
      offset += length_activestatuswordi;
      }
      *(outbuffer + offset + 0) = (this->activedriveflags_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->activedriveflags_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->activedriveflags_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->activedriveflags_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->activedriveflags_length);
      for( uint32_t i = 0; i < activedriveflags_length; i++){
      uint32_t length_activedriveflagsi = strlen(this->activedriveflags[i]);
      varToArr(outbuffer + offset, length_activedriveflagsi);
      offset += 4;
      memcpy(outbuffer + offset, this->activedriveflags[i], length_activedriveflagsi);
      offset += length_activedriveflagsi;
      }
      union {
        int32_t real;
        uint32_t base;
      } u_digitaloutputs;
      u_digitaloutputs.real = this->digitaloutputs;
      *(outbuffer + offset + 0) = (u_digitaloutputs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_digitaloutputs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_digitaloutputs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_digitaloutputs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->digitaloutputs);
      union {
        int32_t real;
        uint32_t base;
      } u_digitalinputs;
      u_digitalinputs.real = this->digitalinputs;
      *(outbuffer + offset + 0) = (u_digitalinputs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_digitalinputs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_digitalinputs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_digitalinputs.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->digitalinputs);
      union {
        float real;
        uint32_t base;
      } u_averagecurrent;
      u_averagecurrent.real = this->averagecurrent;
      *(outbuffer + offset + 0) = (u_averagecurrent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_averagecurrent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_averagecurrent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_averagecurrent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->averagecurrent);
      *(outbuffer + offset + 0) = (this->analoginputs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->analoginputs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->analoginputs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->analoginputs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analoginputs_length);
      for( uint32_t i = 0; i < analoginputs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_analoginputsi;
      u_analoginputsi.real = this->analoginputs[i];
      *(outbuffer + offset + 0) = (u_analoginputsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_analoginputsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_analoginputsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_analoginputsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analoginputs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_state;
      arrToVar(length_state, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state-1]=0;
      this->state = (char *)(inbuffer + offset-1);
      offset += length_state;
      uint32_t length_status;
      arrToVar(length_status, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_status; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_status-1]=0;
      this->status = (char *)(inbuffer + offset-1);
      offset += length_status;
      uint32_t length_communicationstatus;
      arrToVar(length_communicationstatus, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_communicationstatus; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_communicationstatus-1]=0;
      this->communicationstatus = (char *)(inbuffer + offset-1);
      offset += length_communicationstatus;
      uint32_t length_statusword;
      arrToVar(length_statusword, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_statusword; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_statusword-1]=0;
      this->statusword = (char *)(inbuffer + offset-1);
      offset += length_statusword;
      uint32_t length_driveflags;
      arrToVar(length_driveflags, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_driveflags; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_driveflags-1]=0;
      this->driveflags = (char *)(inbuffer + offset-1);
      offset += length_driveflags;
      uint32_t activestatusword_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      activestatusword_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      activestatusword_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      activestatusword_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->activestatusword_length);
      if(activestatusword_lengthT > activestatusword_length)
        this->activestatusword = (char**)realloc(this->activestatusword, activestatusword_lengthT * sizeof(char*));
      activestatusword_length = activestatusword_lengthT;
      for( uint32_t i = 0; i < activestatusword_length; i++){
      uint32_t length_st_activestatusword;
      arrToVar(length_st_activestatusword, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_activestatusword; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_activestatusword-1]=0;
      this->st_activestatusword = (char *)(inbuffer + offset-1);
      offset += length_st_activestatusword;
        memcpy( &(this->activestatusword[i]), &(this->st_activestatusword), sizeof(char*));
      }
      uint32_t activedriveflags_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      activedriveflags_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      activedriveflags_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      activedriveflags_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->activedriveflags_length);
      if(activedriveflags_lengthT > activedriveflags_length)
        this->activedriveflags = (char**)realloc(this->activedriveflags, activedriveflags_lengthT * sizeof(char*));
      activedriveflags_length = activedriveflags_lengthT;
      for( uint32_t i = 0; i < activedriveflags_length; i++){
      uint32_t length_st_activedriveflags;
      arrToVar(length_st_activedriveflags, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_activedriveflags; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_activedriveflags-1]=0;
      this->st_activedriveflags = (char *)(inbuffer + offset-1);
      offset += length_st_activedriveflags;
        memcpy( &(this->activedriveflags[i]), &(this->st_activedriveflags), sizeof(char*));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_digitaloutputs;
      u_digitaloutputs.base = 0;
      u_digitaloutputs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_digitaloutputs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_digitaloutputs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_digitaloutputs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->digitaloutputs = u_digitaloutputs.real;
      offset += sizeof(this->digitaloutputs);
      union {
        int32_t real;
        uint32_t base;
      } u_digitalinputs;
      u_digitalinputs.base = 0;
      u_digitalinputs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_digitalinputs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_digitalinputs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_digitalinputs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->digitalinputs = u_digitalinputs.real;
      offset += sizeof(this->digitalinputs);
      union {
        float real;
        uint32_t base;
      } u_averagecurrent;
      u_averagecurrent.base = 0;
      u_averagecurrent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_averagecurrent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_averagecurrent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_averagecurrent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->averagecurrent = u_averagecurrent.real;
      offset += sizeof(this->averagecurrent);
      uint32_t analoginputs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      analoginputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      analoginputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      analoginputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->analoginputs_length);
      if(analoginputs_lengthT > analoginputs_length)
        this->analoginputs = (float*)realloc(this->analoginputs, analoginputs_lengthT * sizeof(float));
      analoginputs_length = analoginputs_lengthT;
      for( uint32_t i = 0; i < analoginputs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_analoginputs;
      u_st_analoginputs.base = 0;
      u_st_analoginputs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_analoginputs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_analoginputs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_analoginputs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_analoginputs = u_st_analoginputs.real;
      offset += sizeof(this->st_analoginputs);
        memcpy( &(this->analoginputs[i]), &(this->st_analoginputs), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/MotorStatus"; };
    const char * getMD5(){ return "bee7a4674a1d69703bedee2437db3d94"; };

  };

}
#endif