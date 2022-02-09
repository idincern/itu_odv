#ifndef _ROS_robotnik_msgs_inputs_outputs_h
#define _ROS_robotnik_msgs_inputs_outputs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class inputs_outputs : public ros::Msg
  {
    public:
      uint32_t digital_inputs_length;
      typedef bool _digital_inputs_type;
      _digital_inputs_type st_digital_inputs;
      _digital_inputs_type * digital_inputs;
      uint32_t digital_outputs_length;
      typedef bool _digital_outputs_type;
      _digital_outputs_type st_digital_outputs;
      _digital_outputs_type * digital_outputs;
      uint32_t analog_inputs_length;
      typedef float _analog_inputs_type;
      _analog_inputs_type st_analog_inputs;
      _analog_inputs_type * analog_inputs;
      uint32_t analog_outputs_length;
      typedef float _analog_outputs_type;
      _analog_outputs_type st_analog_outputs;
      _analog_outputs_type * analog_outputs;

    inputs_outputs():
      digital_inputs_length(0), digital_inputs(NULL),
      digital_outputs_length(0), digital_outputs(NULL),
      analog_inputs_length(0), analog_inputs(NULL),
      analog_outputs_length(0), analog_outputs(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->digital_inputs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->digital_inputs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->digital_inputs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->digital_inputs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->digital_inputs_length);
      for( uint32_t i = 0; i < digital_inputs_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_digital_inputsi;
      u_digital_inputsi.real = this->digital_inputs[i];
      *(outbuffer + offset + 0) = (u_digital_inputsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_inputs[i]);
      }
      *(outbuffer + offset + 0) = (this->digital_outputs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->digital_outputs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->digital_outputs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->digital_outputs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->digital_outputs_length);
      for( uint32_t i = 0; i < digital_outputs_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_digital_outputsi;
      u_digital_outputsi.real = this->digital_outputs[i];
      *(outbuffer + offset + 0) = (u_digital_outputsi.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->digital_outputs[i]);
      }
      *(outbuffer + offset + 0) = (this->analog_inputs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->analog_inputs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->analog_inputs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->analog_inputs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analog_inputs_length);
      for( uint32_t i = 0; i < analog_inputs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_analog_inputsi;
      u_analog_inputsi.real = this->analog_inputs[i];
      *(outbuffer + offset + 0) = (u_analog_inputsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_analog_inputsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_analog_inputsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_analog_inputsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analog_inputs[i]);
      }
      *(outbuffer + offset + 0) = (this->analog_outputs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->analog_outputs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->analog_outputs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->analog_outputs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analog_outputs_length);
      for( uint32_t i = 0; i < analog_outputs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_analog_outputsi;
      u_analog_outputsi.real = this->analog_outputs[i];
      *(outbuffer + offset + 0) = (u_analog_outputsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_analog_outputsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_analog_outputsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_analog_outputsi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->analog_outputs[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t digital_inputs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      digital_inputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      digital_inputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      digital_inputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->digital_inputs_length);
      if(digital_inputs_lengthT > digital_inputs_length)
        this->digital_inputs = (bool*)realloc(this->digital_inputs, digital_inputs_lengthT * sizeof(bool));
      digital_inputs_length = digital_inputs_lengthT;
      for( uint32_t i = 0; i < digital_inputs_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_digital_inputs;
      u_st_digital_inputs.base = 0;
      u_st_digital_inputs.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_digital_inputs = u_st_digital_inputs.real;
      offset += sizeof(this->st_digital_inputs);
        memcpy( &(this->digital_inputs[i]), &(this->st_digital_inputs), sizeof(bool));
      }
      uint32_t digital_outputs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      digital_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      digital_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      digital_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->digital_outputs_length);
      if(digital_outputs_lengthT > digital_outputs_length)
        this->digital_outputs = (bool*)realloc(this->digital_outputs, digital_outputs_lengthT * sizeof(bool));
      digital_outputs_length = digital_outputs_lengthT;
      for( uint32_t i = 0; i < digital_outputs_length; i++){
      union {
        bool real;
        uint8_t base;
      } u_st_digital_outputs;
      u_st_digital_outputs.base = 0;
      u_st_digital_outputs.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_digital_outputs = u_st_digital_outputs.real;
      offset += sizeof(this->st_digital_outputs);
        memcpy( &(this->digital_outputs[i]), &(this->st_digital_outputs), sizeof(bool));
      }
      uint32_t analog_inputs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      analog_inputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      analog_inputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      analog_inputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->analog_inputs_length);
      if(analog_inputs_lengthT > analog_inputs_length)
        this->analog_inputs = (float*)realloc(this->analog_inputs, analog_inputs_lengthT * sizeof(float));
      analog_inputs_length = analog_inputs_lengthT;
      for( uint32_t i = 0; i < analog_inputs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_analog_inputs;
      u_st_analog_inputs.base = 0;
      u_st_analog_inputs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_analog_inputs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_analog_inputs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_analog_inputs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_analog_inputs = u_st_analog_inputs.real;
      offset += sizeof(this->st_analog_inputs);
        memcpy( &(this->analog_inputs[i]), &(this->st_analog_inputs), sizeof(float));
      }
      uint32_t analog_outputs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      analog_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      analog_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      analog_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->analog_outputs_length);
      if(analog_outputs_lengthT > analog_outputs_length)
        this->analog_outputs = (float*)realloc(this->analog_outputs, analog_outputs_lengthT * sizeof(float));
      analog_outputs_length = analog_outputs_lengthT;
      for( uint32_t i = 0; i < analog_outputs_length; i++){
      union {
        float real;
        uint32_t base;
      } u_st_analog_outputs;
      u_st_analog_outputs.base = 0;
      u_st_analog_outputs.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_analog_outputs.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_analog_outputs.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_analog_outputs.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_analog_outputs = u_st_analog_outputs.real;
      offset += sizeof(this->st_analog_outputs);
        memcpy( &(this->analog_outputs[i]), &(this->st_analog_outputs), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/inputs_outputs"; };
    const char * getMD5(){ return "219be75bd56b8ebdca0dfa526c3803be"; };

  };

}
#endif