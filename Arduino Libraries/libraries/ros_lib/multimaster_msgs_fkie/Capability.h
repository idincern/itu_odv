#ifndef _ROS_multimaster_msgs_fkie_Capability_h
#define _ROS_multimaster_msgs_fkie_Capability_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multimaster_msgs_fkie
{

  class Capability : public ros::Msg
  {
    public:
      typedef const char* _namespace_type;
      _namespace_type namespace;
      typedef const char* _name_type;
      _name_type name;
      typedef const char* _type_type;
      _type_type type;
      uint32_t images_length;
      typedef char* _images_type;
      _images_type st_images;
      _images_type * images;
      typedef const char* _description_type;
      _description_type description;
      uint32_t nodes_length;
      typedef char* _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;

    Capability():
      namespace(""),
      name(""),
      type(""),
      images_length(0), images(NULL),
      description(""),
      nodes_length(0), nodes(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_namespace = strlen(this->namespace);
      varToArr(outbuffer + offset, length_namespace);
      offset += 4;
      memcpy(outbuffer + offset, this->namespace, length_namespace);
      offset += length_namespace;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      uint32_t length_type = strlen(this->type);
      varToArr(outbuffer + offset, length_type);
      offset += 4;
      memcpy(outbuffer + offset, this->type, length_type);
      offset += length_type;
      *(outbuffer + offset + 0) = (this->images_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->images_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->images_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->images_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->images_length);
      for( uint32_t i = 0; i < images_length; i++){
      uint32_t length_imagesi = strlen(this->images[i]);
      varToArr(outbuffer + offset, length_imagesi);
      offset += 4;
      memcpy(outbuffer + offset, this->images[i], length_imagesi);
      offset += length_imagesi;
      }
      uint32_t length_description = strlen(this->description);
      varToArr(outbuffer + offset, length_description);
      offset += 4;
      memcpy(outbuffer + offset, this->description, length_description);
      offset += length_description;
      *(outbuffer + offset + 0) = (this->nodes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->nodes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->nodes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->nodes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nodes_length);
      for( uint32_t i = 0; i < nodes_length; i++){
      uint32_t length_nodesi = strlen(this->nodes[i]);
      varToArr(outbuffer + offset, length_nodesi);
      offset += 4;
      memcpy(outbuffer + offset, this->nodes[i], length_nodesi);
      offset += length_nodesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_namespace;
      arrToVar(length_namespace, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_namespace; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_namespace-1]=0;
      this->namespace = (char *)(inbuffer + offset-1);
      offset += length_namespace;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      uint32_t length_type;
      arrToVar(length_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type-1]=0;
      this->type = (char *)(inbuffer + offset-1);
      offset += length_type;
      uint32_t images_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      images_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      images_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      images_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->images_length);
      if(images_lengthT > images_length)
        this->images = (char**)realloc(this->images, images_lengthT * sizeof(char*));
      images_length = images_lengthT;
      for( uint32_t i = 0; i < images_length; i++){
      uint32_t length_st_images;
      arrToVar(length_st_images, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_images; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_images-1]=0;
      this->st_images = (char *)(inbuffer + offset-1);
      offset += length_st_images;
        memcpy( &(this->images[i]), &(this->st_images), sizeof(char*));
      }
      uint32_t length_description;
      arrToVar(length_description, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_description; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_description-1]=0;
      this->description = (char *)(inbuffer + offset-1);
      offset += length_description;
      uint32_t nodes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      nodes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->nodes_length);
      if(nodes_lengthT > nodes_length)
        this->nodes = (char**)realloc(this->nodes, nodes_lengthT * sizeof(char*));
      nodes_length = nodes_lengthT;
      for( uint32_t i = 0; i < nodes_length; i++){
      uint32_t length_st_nodes;
      arrToVar(length_st_nodes, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_nodes; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_nodes-1]=0;
      this->st_nodes = (char *)(inbuffer + offset-1);
      offset += length_st_nodes;
        memcpy( &(this->nodes[i]), &(this->st_nodes), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/Capability"; };
    const char * getMD5(){ return "ca248f1a2644e7372795bf788ed1941b"; };

  };

}
#endif