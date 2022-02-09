#ifndef _ROS_robotnik_msgs_Alarms_h
#define _ROS_robotnik_msgs_Alarms_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/AlarmSensor.h"

namespace robotnik_msgs
{

  class Alarms : public ros::Msg
  {
    public:
      uint32_t alarms_length;
      typedef robotnik_msgs::AlarmSensor _alarms_type;
      _alarms_type st_alarms;
      _alarms_type * alarms;

    Alarms():
      alarms_length(0), alarms(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->alarms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alarms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alarms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alarms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alarms_length);
      for( uint32_t i = 0; i < alarms_length; i++){
      offset += this->alarms[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t alarms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      alarms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      alarms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      alarms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->alarms_length);
      if(alarms_lengthT > alarms_length)
        this->alarms = (robotnik_msgs::AlarmSensor*)realloc(this->alarms, alarms_lengthT * sizeof(robotnik_msgs::AlarmSensor));
      alarms_length = alarms_lengthT;
      for( uint32_t i = 0; i < alarms_length; i++){
      offset += this->st_alarms.deserialize(inbuffer + offset);
        memcpy( &(this->alarms[i]), &(this->st_alarms), sizeof(robotnik_msgs::AlarmSensor));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/Alarms"; };
    const char * getMD5(){ return "83113d787282f31e7cff7eb72a2096c0"; };

  };

}
#endif