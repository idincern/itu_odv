#ifndef _ROS_arm_navigation_msgs_MakeStaticCollisionMapActionGoal_h
#define _ROS_arm_navigation_msgs_MakeStaticCollisionMapActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "arm_navigation_msgs/MakeStaticCollisionMapGoal.h"

namespace arm_navigation_msgs
{

  class MakeStaticCollisionMapActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef arm_navigation_msgs::MakeStaticCollisionMapGoal _goal_type;
      _goal_type goal;

    MakeStaticCollisionMapActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MakeStaticCollisionMapActionGoal"; };
    const char * getMD5(){ return "9233244d249847c9ee000cb0fccbaf8e"; };

  };

}
#endif