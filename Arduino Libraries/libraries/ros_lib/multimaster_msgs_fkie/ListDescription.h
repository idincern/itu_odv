#ifndef _ROS_SERVICE_ListDescription_h
#define _ROS_SERVICE_ListDescription_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "multimaster_msgs_fkie/Capability.h"

namespace multimaster_msgs_fkie
{

static const char LISTDESCRIPTION[] = "multimaster_msgs_fkie/ListDescription";

  class ListDescriptionRequest : public ros::Msg
  {
    public:

    ListDescriptionRequest()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return LISTDESCRIPTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ListDescriptionResponse : public ros::Msg
  {
    public:
      typedef const char* _robot_name_type;
      _robot_name_type robot_name;
      typedef const char* _robot_type_type;
      _robot_type_type robot_type;
      uint32_t robot_images_length;
      typedef char* _robot_images_type;
      _robot_images_type st_robot_images;
      _robot_images_type * robot_images;
      typedef const char* _robot_descr_type;
      _robot_descr_type robot_descr;
      uint32_t capabilities_length;
      typedef multimaster_msgs_fkie::Capability _capabilities_type;
      _capabilities_type st_capabilities;
      _capabilities_type * capabilities;

    ListDescriptionResponse():
      robot_name(""),
      robot_type(""),
      robot_images_length(0), robot_images(NULL),
      robot_descr(""),
      capabilities_length(0), capabilities(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_robot_name = strlen(this->robot_name);
      varToArr(outbuffer + offset, length_robot_name);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_name, length_robot_name);
      offset += length_robot_name;
      uint32_t length_robot_type = strlen(this->robot_type);
      varToArr(outbuffer + offset, length_robot_type);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_type, length_robot_type);
      offset += length_robot_type;
      *(outbuffer + offset + 0) = (this->robot_images_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->robot_images_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->robot_images_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->robot_images_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->robot_images_length);
      for( uint32_t i = 0; i < robot_images_length; i++){
      uint32_t length_robot_imagesi = strlen(this->robot_images[i]);
      varToArr(outbuffer + offset, length_robot_imagesi);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_images[i], length_robot_imagesi);
      offset += length_robot_imagesi;
      }
      uint32_t length_robot_descr = strlen(this->robot_descr);
      varToArr(outbuffer + offset, length_robot_descr);
      offset += 4;
      memcpy(outbuffer + offset, this->robot_descr, length_robot_descr);
      offset += length_robot_descr;
      *(outbuffer + offset + 0) = (this->capabilities_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->capabilities_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->capabilities_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->capabilities_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->capabilities_length);
      for( uint32_t i = 0; i < capabilities_length; i++){
      offset += this->capabilities[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_robot_name;
      arrToVar(length_robot_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_name-1]=0;
      this->robot_name = (char *)(inbuffer + offset-1);
      offset += length_robot_name;
      uint32_t length_robot_type;
      arrToVar(length_robot_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_type-1]=0;
      this->robot_type = (char *)(inbuffer + offset-1);
      offset += length_robot_type;
      uint32_t robot_images_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      robot_images_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      robot_images_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      robot_images_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->robot_images_length);
      if(robot_images_lengthT > robot_images_length)
        this->robot_images = (char**)realloc(this->robot_images, robot_images_lengthT * sizeof(char*));
      robot_images_length = robot_images_lengthT;
      for( uint32_t i = 0; i < robot_images_length; i++){
      uint32_t length_st_robot_images;
      arrToVar(length_st_robot_images, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_robot_images; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_robot_images-1]=0;
      this->st_robot_images = (char *)(inbuffer + offset-1);
      offset += length_st_robot_images;
        memcpy( &(this->robot_images[i]), &(this->st_robot_images), sizeof(char*));
      }
      uint32_t length_robot_descr;
      arrToVar(length_robot_descr, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_robot_descr; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_robot_descr-1]=0;
      this->robot_descr = (char *)(inbuffer + offset-1);
      offset += length_robot_descr;
      uint32_t capabilities_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      capabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      capabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      capabilities_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->capabilities_length);
      if(capabilities_lengthT > capabilities_length)
        this->capabilities = (multimaster_msgs_fkie::Capability*)realloc(this->capabilities, capabilities_lengthT * sizeof(multimaster_msgs_fkie::Capability));
      capabilities_length = capabilities_lengthT;
      for( uint32_t i = 0; i < capabilities_length; i++){
      offset += this->st_capabilities.deserialize(inbuffer + offset);
        memcpy( &(this->capabilities[i]), &(this->st_capabilities), sizeof(multimaster_msgs_fkie::Capability));
      }
     return offset;
    }

    const char * getType(){ return LISTDESCRIPTION; };
    const char * getMD5(){ return "a36ba5a97ce785b9b964aa015b26332b"; };

  };

  class ListDescription {
    public:
    typedef ListDescriptionRequest Request;
    typedef ListDescriptionResponse Response;
  };

}
#endif
