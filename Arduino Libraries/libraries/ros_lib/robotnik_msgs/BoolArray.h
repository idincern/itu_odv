#ifndef _ROS_robotnik_msgs_BoolArray_h
#define _ROS_robotnik_msgs_BoolArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class BoolArray : public ros::Msg
  {
    public:
      uint32_t data_length;
      typedef bool _data_type;
      _data_type st_data;
      _data_type * data;

    BoolArray():
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_datai;
      u_datai.real = this->data[i];
      *(outbuffer + offset + 0) = (u_datai.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (bool*)realloc(this->data, data_lengthT * sizeof(bool));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_data;
      u_st_data.base = 0;
      u_st_data.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_data = u_st_data.real;
      offset += sizeof(this->st_data);
        memcpy( &(this->data[i]), &(this->st_data), sizeof(bool));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/BoolArray"; };
    const char * getMD5(){ return "403a16d9294b908e45c67a6f3c3a5b27"; };

  };

}
#endif