#ifndef _ROS_arm_navigation_msgs_MakeStaticCollisionMapAction_h
#define _ROS_arm_navigation_msgs_MakeStaticCollisionMapAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/MakeStaticCollisionMapActionGoal.h"
#include "arm_navigation_msgs/MakeStaticCollisionMapActionResult.h"
#include "arm_navigation_msgs/MakeStaticCollisionMapActionFeedback.h"

namespace arm_navigation_msgs
{

  class MakeStaticCollisionMapAction : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::MakeStaticCollisionMapActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef arm_navigation_msgs::MakeStaticCollisionMapActionResult _action_result_type;
      _action_result_type action_result;
      typedef arm_navigation_msgs::MakeStaticCollisionMapActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    MakeStaticCollisionMapAction():
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

    const char * getType(){ return "arm_navigation_msgs/MakeStaticCollisionMapAction"; };
    const char * getMD5(){ return "aa13998383a2996b29b6fe4862547a17"; };

  };

}
#endif