#ifndef _ROS_robotnik_msgs_Registers_h
#define _ROS_robotnik_msgs_Registers_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/Register.h"

namespace robotnik_msgs
{

  class Registers : public ros::Msg
  {
    public:
      uint32_t registers_length;
      typedef robotnik_msgs::Register _registers_type;
      _registers_type st_registers;
      _registers_type * registers;

    Registers():
      registers_length(0), registers(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->registers_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->registers_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->registers_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->registers_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->registers_length);
      for( uint32_t i = 0; i < registers_length; i++){
      offset += this->registers[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t registers_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      registers_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      registers_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      registers_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->registers_length);
      if(registers_lengthT > registers_length)
        this->registers = (robotnik_msgs::Register*)realloc(this->registers, registers_lengthT * sizeof(robotnik_msgs::Register));
      registers_length = registers_lengthT;
      for( uint32_t i = 0; i < registers_length; i++){
      offset += this->st_registers.deserialize(inbuffer + offset);
        memcpy( &(this->registers[i]), &(this->st_registers), sizeof(robotnik_msgs::Register));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/Registers"; };
    const char * getMD5(){ return "12d8645a7a01078095f8477105240cef"; };

  };

}
#endif