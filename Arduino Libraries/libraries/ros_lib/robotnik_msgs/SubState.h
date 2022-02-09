#ifndef _ROS_robotnik_msgs_SubState_h
#define _ROS_robotnik_msgs_SubState_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class SubState : public ros::Msg
  {
    public:
      typedef int32_t _substate_type;
      _substate_type substate;
      typedef const char* _substate_description_type;
      _substate_description_type substate_description;
      typedef const char* _msg_type;
      _msg_type msg;

    SubState():
      substate(0),
      substate_description(""),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_substate;
      u_substate.real = this->substate;
      *(outbuffer + offset + 0) = (u_substate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_substate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_substate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_substate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->substate);
      uint32_t length_substate_description = strlen(this->substate_description);
      varToArr(outbuffer + offset, length_substate_description);
      offset += 4;
      memcpy(outbuffer + offset, this->substate_description, length_substate_description);
      offset += length_substate_description;
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
      } u_substate;
      u_substate.base = 0;
      u_substate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_substate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_substate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_substate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->substate = u_substate.real;
      offset += sizeof(this->substate);
      uint32_t length_substate_description;
      arrToVar(length_substate_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_substate_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_substate_description-1]=0;
      this->substate_description = (char *)(inbuffer + offset-1);
      offset += length_substate_description;
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

    const char * getType(){ return "robotnik_msgs/SubState"; };
    const char * getMD5(){ return "d67ef59716a56f2892e9ebccd174a9e5"; };

  };

}
#endif