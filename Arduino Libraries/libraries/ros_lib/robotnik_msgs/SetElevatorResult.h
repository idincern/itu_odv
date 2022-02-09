#ifndef _ROS_robotnik_msgs_SetElevatorResult_h
#define _ROS_robotnik_msgs_SetElevatorResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/ElevatorStatus.h"

namespace robotnik_msgs
{

  class SetElevatorResult : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;
      typedef robotnik_msgs::ElevatorStatus _status_type;
      _status_type status;

    SetElevatorResult():
      result(0),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/SetElevatorResult"; };
    const char * getMD5(){ return "12d6ac7f551fad5a4ed42918932433e0"; };

  };

}
#endif