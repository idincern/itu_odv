#ifndef _ROS_multimaster_msgs_fkie_SyncServiceInfo_h
#define _ROS_multimaster_msgs_fkie_SyncServiceInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multimaster_msgs_fkie
{

  class SyncServiceInfo : public ros::Msg
  {
    public:
      typedef const char* _service_type;
      _service_type service;
      typedef const char* _serviceuri_type;
      _serviceuri_type serviceuri;
      typedef const char* _node_type;
      _node_type node;
      typedef const char* _nodeuri_type;
      _nodeuri_type nodeuri;

    SyncServiceInfo():
      service(""),
      serviceuri(""),
      node(""),
      nodeuri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_service = strlen(this->service);
      varToArr(outbuffer + offset, length_service);
      offset += 4;
      memcpy(outbuffer + offset, this->service, length_service);
      offset += length_service;
      uint32_t length_serviceuri = strlen(this->serviceuri);
      varToArr(outbuffer + offset, length_serviceuri);
      offset += 4;
      memcpy(outbuffer + offset, this->serviceuri, length_serviceuri);
      offset += length_serviceuri;
      uint32_t length_node = strlen(this->node);
      varToArr(outbuffer + offset, length_node);
      offset += 4;
      memcpy(outbuffer + offset, this->node, length_node);
      offset += length_node;
      uint32_t length_nodeuri = strlen(this->nodeuri);
      varToArr(outbuffer + offset, length_nodeuri);
      offset += 4;
      memcpy(outbuffer + offset, this->nodeuri, length_nodeuri);
      offset += length_nodeuri;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_service;
      arrToVar(length_service, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_service; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_service-1]=0;
      this->service = (char *)(inbuffer + offset-1);
      offset += length_service;
      uint32_t length_serviceuri;
      arrToVar(length_serviceuri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serviceuri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serviceuri-1]=0;
      this->serviceuri = (char *)(inbuffer + offset-1);
      offset += length_serviceuri;
      uint32_t length_node;
      arrToVar(length_node, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_node; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_node-1]=0;
      this->node = (char *)(inbuffer + offset-1);
      offset += length_node;
      uint32_t length_nodeuri;
      arrToVar(length_nodeuri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_nodeuri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_nodeuri-1]=0;
      this->nodeuri = (char *)(inbuffer + offset-1);
      offset += length_nodeuri;
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/SyncServiceInfo"; };
    const char * getMD5(){ return "8c21bb9ea24403924441840b8c167c40"; };

  };

}
#endif