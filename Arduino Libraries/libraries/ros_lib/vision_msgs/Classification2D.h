#ifndef _ROS_vision_msgs_Classification2D_h
#define _ROS_vision_msgs_Classification2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "vision_msgs/ObjectHypothesis.h"
#include "sensor_msgs/Image.h"

namespace vision_msgs
{

  class Classification2D : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t results_length;
      typedef vision_msgs::ObjectHypothesis _results_type;
      _results_type st_results;
      _results_type * results;
      typedef sensor_msgs::Image _source_img_type;
      _source_img_type source_img;

    Classification2D():
      header(),
      results_length(0), results(NULL),
      source_img()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->results_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->results_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->results_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->results_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->results_length);
      for( uint32_t i = 0; i < results_length; i++){
      offset += this->results[i].serialize(outbuffer + offset);
      }
      offset += this->source_img.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t results_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      results_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->results_length);
      if(results_lengthT > results_length)
        this->results = (vision_msgs::ObjectHypothesis*)realloc(this->results, results_lengthT * sizeof(vision_msgs::ObjectHypothesis));
      results_length = results_lengthT;
      for( uint32_t i = 0; i < results_length; i++){
      offset += this->st_results.deserialize(inbuffer + offset);
        memcpy( &(this->results[i]), &(this->st_results), sizeof(vision_msgs::ObjectHypothesis));
      }
      offset += this->source_img.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "vision_msgs/Classification2D"; };
    const char * getMD5(){ return "b23d0855d0f41568e09106615351255f"; };

  };

}
#endif