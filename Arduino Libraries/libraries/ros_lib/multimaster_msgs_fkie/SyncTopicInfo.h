#ifndef _ROS_multimaster_msgs_fkie_SyncTopicInfo_h
#define _ROS_multimaster_msgs_fkie_SyncTopicInfo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace multimaster_msgs_fkie
{

  class SyncTopicInfo : public ros::Msg
  {
    public:
      typedef const char* _topic_type;
      _topic_type topic;
      typedef const char* _node_type;
      _node_type node;
      typedef const char* _nodeuri_type;
      _nodeuri_type nodeuri;

    SyncTopicInfo():
      topic(""),
      node(""),
      nodeuri("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_topic = strlen(this->topic);
      varToArr(outbuffer + offset, length_topic);
      offset += 4;
      memcpy(outbuffer + offset, this->topic, length_topic);
      offset += length_topic;
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
      uint32_t length_topic;
      arrToVar(length_topic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_topic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_topic-1]=0;
      this->topic = (char *)(inbuffer + offset-1);
      offset += length_topic;
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

    const char * getType(){ return "multimaster_msgs_fkie/SyncTopicInfo"; };
    const char * getMD5(){ return "1b296160d6f5a9d7f6550f6130da2ba4"; };

  };

}
#endif