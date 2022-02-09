#ifndef _ROS_robotnik_msgs_SetElevatorAction_h
#define _ROS_robotnik_msgs_SetElevatorAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/SetElevatorActionGoal.h"
#include "robotnik_msgs/SetElevatorActionResult.h"
#include "robotnik_msgs/SetElevatorActionFeedback.h"

namespace robotnik_msgs
{

  class SetElevatorAction : public ros::Msg
  {
    public:
      typedef robotnik_msgs::SetElevatorActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef robotnik_msgs::SetElevatorActionResult _action_result_type;
      _action_result_type action_result;
      typedef robotnik_msgs::SetElevatorActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    SetElevatorAction():
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

    const char * getType(){ return "robotnik_msgs/SetElevatorAction"; };
    const char * getMD5(){ return "a239c1d232c11052aae10003929f5e20"; };

  };

}
#endif