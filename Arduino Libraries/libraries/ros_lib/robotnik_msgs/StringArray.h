#ifndef _ROS_robotnik_msgs_StringArray_h
#define _ROS_robotnik_msgs_StringArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class StringArray : public ros::Msg
  {
    public:
      uint32_t text_length;
      typedef char* _text_type;
      _text_type st_text;
      _text_type * text;

    StringArray():
      text_length(0), text(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->text_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->text_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->text_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->text_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->text_length);
      for( uint32_t i = 0; i < text_length; i++){
      uint32_t length_texti = strlen(this->text[i]);
      varToArr(outbuffer + offset, length_texti);
      offset += 4;
      memcpy(outbuffer + offset, this->text[i], length_texti);
      offset += length_texti;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t text_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      text_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      text_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      text_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->text_length);
      if(text_lengthT > text_length)
        this->text = (char**)realloc(this->text, text_lengthT * sizeof(char*));
      text_length = text_lengthT;
      for( uint32_t i = 0; i < text_length; i++){
      uint32_t length_st_text;
      arrToVar(length_st_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_text-1]=0;
      this->st_text = (char *)(inbuffer + offset-1);
      offset += length_st_text;
        memcpy( &(this->text[i]), &(this->st_text), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/StringArray"; };
    const char * getMD5(){ return "da62ad767a4dbff3a3ce44939e6c55e8"; };

  };

}
#endif