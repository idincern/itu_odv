#ifndef _ROS_robotnik_msgs_named_inputs_outputs_h
#define _ROS_robotnik_msgs_named_inputs_outputs_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/named_input_output.h"

namespace robotnik_msgs
{

  class named_inputs_outputs : public ros::Msg
  {
    public:
      uint32_t digital_inputs_length;
      typedef robotnik_msgs::named_input_output _digital_inputs_type;
      _digital_inputs_type st_digital_inputs;
      _digital_inputs_type * digital_inputs;
      uint32_t digital_outputs_length;
      typedef robotnik_msgs::named_input_output _digital_outputs_type;
      _digital_outputs_type st_digital_outputs;
      _digital_outputs_type * digital_outputs;

    named_inputs_outputs():
      digital_inputs_length(0), digital_inputs(NULL),
      digital_outputs_length(0), digital_outputs(NULL)
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
      offset += this->digital_inputs[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->digital_outputs_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->digital_outputs_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->digital_outputs_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->digital_outputs_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->digital_outputs_length);
      for( uint32_t i = 0; i < digital_outputs_length; i++){
      offset += this->digital_outputs[i].serialize(outbuffer + offset);
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
        this->digital_inputs = (robotnik_msgs::named_input_output*)realloc(this->digital_inputs, digital_inputs_lengthT * sizeof(robotnik_msgs::named_input_output));
      digital_inputs_length = digital_inputs_lengthT;
      for( uint32_t i = 0; i < digital_inputs_length; i++){
      offset += this->st_digital_inputs.deserialize(inbuffer + offset);
        memcpy( &(this->digital_inputs[i]), &(this->st_digital_inputs), sizeof(robotnik_msgs::named_input_output));
      }
      uint32_t digital_outputs_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      digital_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      digital_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      digital_outputs_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->digital_outputs_length);
      if(digital_outputs_lengthT > digital_outputs_length)
        this->digital_outputs = (robotnik_msgs::named_input_output*)realloc(this->digital_outputs, digital_outputs_lengthT * sizeof(robotnik_msgs::named_input_output));
      digital_outputs_length = digital_outputs_lengthT;
      for( uint32_t i = 0; i < digital_outputs_length; i++){
      offset += this->st_digital_outputs.deserialize(inbuffer + offset);
        memcpy( &(this->digital_outputs[i]), &(this->st_digital_outputs), sizeof(robotnik_msgs::named_input_output));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/named_inputs_outputs"; };
    const char * getMD5(){ return "e3301c19a16019595490fc28259868bd"; };

  };

}
#endif