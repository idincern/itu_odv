#ifndef _ROS_arm_navigation_msgs_MoveArmActionFeedback_h
#define _ROS_arm_navigation_msgs_MoveArmActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "arm_navigation_msgs/MoveArmFeedback.h"

namespace arm_navigation_msgs
{

  class MoveArmActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef arm_navigation_msgs::MoveArmFeedback _feedback_type;
      _feedback_type feedback;

    MoveArmActionFeedback():
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

    const char * getType(){ return "arm_navigation_msgs/MoveArmActionFeedback"; };
    const char * getMD5(){ return "50284463bfe759fbf589fc263537baad"; };

  };

}
#endif