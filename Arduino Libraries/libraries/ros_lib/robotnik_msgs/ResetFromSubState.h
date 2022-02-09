#ifndef _ROS_SERVICE_ResetFromSubState_h
#define _ROS_SERVICE_ResetFromSubState_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char RESETFROMSUBSTATE[] = "robotnik_msgs/ResetFromSubState";

  class ResetFromSubStateRequest : public ros::Msg
  {
    public:
      typedef int32_t _subState_type;
      _subState_type subState;

    ResetFromSubStateRequest():
      subState(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_subState;
      u_subState.real = this->subState;
      *(outbuffer + offset + 0) = (u_subState.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_subState.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_subState.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_subState.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subState);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_subState;
      u_subState.base = 0;
      u_subState.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_subState.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_subState.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_subState.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->subState = u_subState.real;
      offset += sizeof(this->subState);
     return offset;
    }

    const char * getType(){ return RESETFROMSUBSTATE; };
    const char * getMD5(){ return "a5b79633cee30f5c84879c01bef7033a"; };

  };

  class ResetFromSubStateResponse : public ros::Msg
  {
    public:
      typedef int32_t _currentSubState_type;
      _currentSubState_type currentSubState;
      typedef bool _success_type;
      _success_type success;
      typedef const char* _msg_type;
      _msg_type msg;

    ResetFromSubStateResponse():
      currentSubState(0),
      success(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_currentSubState;
      u_currentSubState.real = this->currentSubState;
      *(outbuffer + offset + 0) = (u_currentSubState.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_currentSubState.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_currentSubState.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_currentSubState.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->currentSubState);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_currentSubState;
      u_currentSubState.base = 0;
      u_currentSubState.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_currentSubState.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_currentSubState.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_currentSubState.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->currentSubState = u_currentSubState.real;
      offset += sizeof(this->currentSubState);
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return RESETFROMSUBSTATE; };
    const char * getMD5(){ return "29ac8b3c219a9c9ea312264e17cdc11f"; };

  };

  class ResetFromSubState {
    public:
    typedef ResetFromSubStateRequest Request;
    typedef ResetFromSubStateResponse Response;
  };

}
#endif
