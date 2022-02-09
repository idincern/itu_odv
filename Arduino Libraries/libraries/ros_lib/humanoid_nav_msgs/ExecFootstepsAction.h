#ifndef _ROS_humanoid_nav_msgs_ExecFootstepsAction_h
#define _ROS_humanoid_nav_msgs_ExecFootstepsAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "humanoid_nav_msgs/ExecFootstepsActionGoal.h"
#include "humanoid_nav_msgs/ExecFootstepsActionResult.h"
#include "humanoid_nav_msgs/ExecFootstepsActionFeedback.h"

namespace humanoid_nav_msgs
{

  class ExecFootstepsAction : public ros::Msg
  {
    public:
      typedef humanoid_nav_msgs::ExecFootstepsActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef humanoid_nav_msgs::ExecFootstepsActionResult _action_result_type;
      _action_result_type action_result;
      typedef humanoid_nav_msgs::ExecFootstepsActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    ExecFootstepsAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "humanoid_nav_msgs/ExecFootstepsAction"; };
    const char * getMD5(){ return "1a2c4888b786ce4d1be346c228ea5a28"; };

  };

}
#endif