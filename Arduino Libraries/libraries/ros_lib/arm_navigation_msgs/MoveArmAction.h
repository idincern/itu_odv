#ifndef _ROS_arm_navigation_msgs_MoveArmAction_h
#define _ROS_arm_navigation_msgs_MoveArmAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/MoveArmActionGoal.h"
#include "arm_navigation_msgs/MoveArmActionResult.h"
#include "arm_navigation_msgs/MoveArmActionFeedback.h"

namespace arm_navigation_msgs
{

  class MoveArmAction : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::MoveArmActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef arm_navigation_msgs::MoveArmActionResult _action_result_type;
      _action_result_type action_result;
      typedef arm_navigation_msgs::MoveArmActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    MoveArmAction():
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

    const char * getType(){ return "arm_navigation_msgs/MoveArmAction"; };
    const char * getMD5(){ return "6a991a3116cabdf4675f6b122822116b"; };

  };

}
#endif