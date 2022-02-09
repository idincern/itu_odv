#ifndef _ROS_robotnik_msgs_SetElevatorFeedback_h
#define _ROS_robotnik_msgs_SetElevatorFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/ElevatorStatus.h"

namespace robotnik_msgs
{

  class SetElevatorFeedback : public ros::Msg
  {
    public:
      typedef robotnik_msgs::ElevatorStatus _status_type;
      _status_type status;

    SetElevatorFeedback():
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/SetElevatorFeedback"; };
    const char * getMD5(){ return "6cf74bddd0ae535bf9cb994b66c1cba4"; };

  };

}
#endif