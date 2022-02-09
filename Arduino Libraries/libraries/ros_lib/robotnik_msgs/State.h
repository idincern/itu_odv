#ifndef _ROS_robotnik_msgs_State_h
#define _ROS_robotnik_msgs_State_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class State : public ros::Msg
  {
    public:
      typedef int32_t _state_type;
      _state_type state;
      typedef float _desired_freq_type;
      _desired_freq_type desired_freq;
      typedef float _real_freq_type;
      _real_freq_type real_freq;
      typedef const char* _state_description_type;
      _state_description_type state_description;
      enum { INIT_STATE =  100 };
      enum { STANDBY_STATE =  200 };
      enum { READY_STATE =  300 };
      enum { EMERGENCY_STATE =  400 };
      enum { FAILURE_STATE =  500 };
      enum { SHUTDOWN_STATE =  600 };
      enum { UNKOWN_STATE =  700 };

    State():
      state(0),
      desired_freq(0),
      real_freq(0),
      state_description("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.real = this->state;
      *(outbuffer + offset + 0) = (u_state.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_state.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_state.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_state.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state);
      union {
        float real;
        uint32_t base;
      } u_desired_freq;
      u_desired_freq.real = this->desired_freq;
      *(outbuffer + offset + 0) = (u_desired_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_desired_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_desired_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_desired_freq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->desired_freq);
      union {
        float real;
        uint32_t base;
      } u_real_freq;
      u_real_freq.real = this->real_freq;
      *(outbuffer + offset + 0) = (u_real_freq.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_real_freq.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_real_freq.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_real_freq.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->real_freq);
      uint32_t length_state_description = strlen(this->state_description);
      varToArr(outbuffer + offset, length_state_description);
      offset += 4;
      memcpy(outbuffer + offset, this->state_description, length_state_description);
      offset += length_state_description;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_state;
      u_state.base = 0;
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_state.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->state = u_state.real;
      offset += sizeof(this->state);
      union {
        float real;
        uint32_t base;
      } u_desired_freq;
      u_desired_freq.base = 0;
      u_desired_freq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_desired_freq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_desired_freq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_desired_freq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->desired_freq = u_desired_freq.real;
      offset += sizeof(this->desired_freq);
      union {
        float real;
        uint32_t base;
      } u_real_freq;
      u_real_freq.base = 0;
      u_real_freq.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_real_freq.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_real_freq.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_real_freq.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->real_freq = u_real_freq.real;
      offset += sizeof(this->real_freq);
      uint32_t length_state_description;
      arrToVar(length_state_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_state_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_state_description-1]=0;
      this->state_description = (char *)(inbuffer + offset-1);
      offset += length_state_description;
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/State"; };
    const char * getMD5(){ return "b3a486e7c5d573e5d1475cd7c02a518b"; };

  };

}
#endif