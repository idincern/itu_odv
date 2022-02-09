#ifndef _ROS_multimaster_msgs_fkie_SyncMasterInfo_h
#define _ROS_multimaster_msgs_fkie_SyncMasterInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "multimaster_msgs_fkie/SyncTopicInfo.h"
#include "multimaster_msgs_fkie/SyncServiceInfo.h"

namespace multimaster_msgs_fkie
{

  class SyncMasterInfo : public ros::Msg
  {
    public:
      typedef const char* _masteruri_type;
      _masteruri_type masteruri;
      uint32_t nodes_length;
      typedef char* _nodes_type;
      _nodes_type st_nodes;
      _nodes_type * nodes;
      uint32_t publisher_length;
      typedef multimaster_msgs_fkie::SyncTopicInfo _publisher_type;
      _publisher_type st_publisher;
      _publisher_type * publisher;
      uint32_t subscriber_length;
      typedef multimaster_msgs_fkie::SyncTopicInfo _subscriber_type;
      _subscriber_type st_subscriber;
      _subscriber_type * subscriber;
      uint32_t services_length;
      typedef multimaster_msgs_fkie::SyncServiceInfo _services_type;
      _services_type st_services;
      _services_type * services;

    SyncMasterInfo():
      masteruri(""),
      nodes_length(0), nodes(NULL),
      publisher_length(0), publisher(NULL),
      subscriber_length(0), subscriber(NULL),
      services_length(0), services(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_masteruri = strlen(this->masteruri);
      varToArr(outbuffer + offset, length_masteruri);
      offset += 4;
      memcpy(outbuffer + offset, this->masteruri, length_masteruri);
      offset += length_masteruri;
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
      *(outbuffer + offset + 0) = (this->publisher_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->publisher_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->publisher_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->publisher_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->publisher_length);
      for( uint32_t i = 0; i < publisher_length; i++){
      offset += this->publisher[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->subscriber_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->subscriber_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->subscriber_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->subscriber_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->subscriber_length);
      for( uint32_t i = 0; i < subscriber_length; i++){
      offset += this->subscriber[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->services_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->services_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->services_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->services_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->services_length);
      for( uint32_t i = 0; i < services_length; i++){
      offset += this->services[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_masteruri;
      arrToVar(length_masteruri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_masteruri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_masteruri-1]=0;
      this->masteruri = (char *)(inbuffer + offset-1);
      offset += length_masteruri;
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
      uint32_t publisher_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      publisher_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      publisher_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      publisher_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->publisher_length);
      if(publisher_lengthT > publisher_length)
        this->publisher = (multimaster_msgs_fkie::SyncTopicInfo*)realloc(this->publisher, publisher_lengthT * sizeof(multimaster_msgs_fkie::SyncTopicInfo));
      publisher_length = publisher_lengthT;
      for( uint32_t i = 0; i < publisher_length; i++){
      offset += this->st_publisher.deserialize(inbuffer + offset);
        memcpy( &(this->publisher[i]), &(this->st_publisher), sizeof(multimaster_msgs_fkie::SyncTopicInfo));
      }
      uint32_t subscriber_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      subscriber_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      subscriber_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      subscriber_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->subscriber_length);
      if(subscriber_lengthT > subscriber_length)
        this->subscriber = (multimaster_msgs_fkie::SyncTopicInfo*)realloc(this->subscriber, subscriber_lengthT * sizeof(multimaster_msgs_fkie::SyncTopicInfo));
      subscriber_length = subscriber_lengthT;
      for( uint32_t i = 0; i < subscriber_length; i++){
      offset += this->st_subscriber.deserialize(inbuffer + offset);
        memcpy( &(this->subscriber[i]), &(this->st_subscriber), sizeof(multimaster_msgs_fkie::SyncTopicInfo));
      }
      uint32_t services_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      services_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      services_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      services_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->services_length);
      if(services_lengthT > services_length)
        this->services = (multimaster_msgs_fkie::SyncServiceInfo*)realloc(this->services, services_lengthT * sizeof(multimaster_msgs_fkie::SyncServiceInfo));
      services_length = services_lengthT;
      for( uint32_t i = 0; i < services_length; i++){
      offset += this->st_services.deserialize(inbuffer + offset);
        memcpy( &(this->services[i]), &(this->st_services), sizeof(multimaster_msgs_fkie::SyncServiceInfo));
      }
     return offset;
    }

    const char * getType(){ return "multimaster_msgs_fkie/SyncMasterInfo"; };
    const char * getMD5(){ return "ba4b02792114bcc4bae507c60dd14d66"; };

  };

}
#endif