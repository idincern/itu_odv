#ifndef _ROS_arm_navigation_msgs_MoveArmFeedback_h
#define _ROS_arm_navigation_msgs_MoveArmFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"

namespace arm_navigation_msgs
{

  class MoveArmFeedback : public ros::Msg
  {
    public:
      typedef const char* _state_type;
      _state_type state;
      typedef ros::Duration _time_to_completion_type;
      _time_to_completion_type time_to_completion;

    MoveArmFeedback():
      state(""),
      time_to_completion()
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
      *(outbuffer + offset + 0) = (this->time_to_completion.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_to_completion.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_to_completion.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_to_completion.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_to_completion.sec);
      *(outbuffer + offset + 0) = (this->time_to_completion.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_to_completion.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_to_completion.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_to_completion.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_to_completion.nsec);
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
      this->time_to_completion.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_to_completion.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_to_completion.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_to_completion.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_to_completion.sec);
      this->time_to_completion.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->time_to_completion.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_to_completion.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_to_completion.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_to_completion.nsec);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MoveArmFeedback"; };
    const char * getMD5(){ return "321f3feadd0d5c1b7d7135738e673560"; };

  };

}
#endif