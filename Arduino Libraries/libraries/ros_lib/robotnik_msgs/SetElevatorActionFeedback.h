#ifndef _ROS_robotnik_msgs_SetElevatorActionFeedback_h
#define _ROS_robotnik_msgs_SetElevatorActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "robotnik_msgs/SetElevatorFeedback.h"

namespace robotnik_msgs
{

  class SetElevatorActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef robotnik_msgs::SetElevatorFeedback _feedback_type;
      _feedback_type feedback;

    SetElevatorActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/SetElevatorActionFeedback"; };
    const char * getMD5(){ return "f5744a577105abc7cbf3dfdce13037d5"; };

  };

}
#endif