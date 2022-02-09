#ifndef _ROS_arm_navigation_msgs_SyncPlanningSceneFeedback_h
#define _ROS_arm_navigation_msgs_SyncPlanningSceneFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_navigation_msgs
{

  class SyncPlanningSceneFeedback : public ros::Msg
  {
    public:
      typedef bool _client_processing_type;
      _client_processing_type client_processing;
      typedef bool _ready_type;
      _ready_type ready;

    SyncPlanningSceneFeedback():
      client_processing(0),
      ready(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_client_processing;
      u_client_processing.real = this->client_processing;
      *(outbuffer + offset + 0) = (u_client_processing.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->client_processing);
      union {
        bool real;
        uint8_t base;
      } u_ready;
      u_ready.real = this->ready;
      *(outbuffer + offset + 0) = (u_ready.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ready);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_client_processing;
      u_client_processing.base = 0;
      u_client_processing.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->client_processing = u_client_processing.real;
      offset += sizeof(this->client_processing);
      union {
        bool real;
        uint8_t base;
      } u_ready;
      u_ready.base = 0;
      u_ready.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ready = u_ready.real;
      offset += sizeof(this->ready);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/SyncPlanningSceneFeedback"; };
    const char * getMD5(){ return "5470cffcd2540df5b10d2ed9ddfde7e4"; };

  };

}
#endif