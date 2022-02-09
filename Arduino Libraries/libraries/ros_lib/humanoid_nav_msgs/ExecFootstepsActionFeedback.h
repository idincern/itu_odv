#ifndef _ROS_humanoid_nav_msgs_ExecFootstepsActionFeedback_h
#define _ROS_humanoid_nav_msgs_ExecFootstepsActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "humanoid_nav_msgs/ExecFootstepsFeedback.h"

namespace humanoid_nav_msgs
{

  class ExecFootstepsActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef humanoid_nav_msgs::ExecFootstepsFeedback _feedback_type;
      _feedback_type feedback;

    ExecFootstepsActionFeedback():
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

    const char * getType(){ return "humanoid_nav_msgs/ExecFootstepsActionFeedback"; };
    const char * getMD5(){ return "01da67223a0592f0de40186a03f441ff"; };

  };

}
#endif