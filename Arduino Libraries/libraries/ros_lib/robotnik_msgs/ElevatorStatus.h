#ifndef _ROS_robotnik_msgs_ElevatorStatus_h
#define _ROS_robotnik_msgs_ElevatorStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class ElevatorStatus : public ros::Msg
  {
    public:
      typedef const char* _state_type;
      _state_type state;
      typedef const char* _position_type;
      _position_type position;
      enum { RAISING = raising };
      enum { LOWERING = lowering };
      enum { IDLE = idle };
      enum { ERROR_G_IO = error_getting_io };
      enum { ERROR_S_IO = error_setting_io };
      enum { ERROR_TIMEOUT = error_timeout_in_action };
      enum { UP = up };
      enum { DOWN = down };
      enum { UNKNOWN = unknown };

    ElevatorStatus():
      state(""),
      position("")
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
      uint32_t length_position = strlen(this->position);
      varToArr(outbuffer + offset, length_position);
      offset += 4;
      memcpy(outbuffer + offset, this->position, length_position);
      offset += length_position;
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
      uint32_t length_position;
      arrToVar(length_position, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_position; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_position-1]=0;
      this->position = (char *)(inbuffer + offset-1);
      offset += length_position;
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/ElevatorStatus"; };
    const char * getMD5(){ return "9becbfc724554c6c51b8c09125fe90d4"; };

  };

}
#endif