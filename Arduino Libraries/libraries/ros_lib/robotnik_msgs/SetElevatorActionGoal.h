#ifndef _ROS_robotnik_msgs_SetElevatorActionGoal_h
#define _ROS_robotnik_msgs_SetElevatorActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "robotnik_msgs/SetElevatorGoal.h"

namespace robotnik_msgs
{

  class SetElevatorActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef robotnik_msgs::SetElevatorGoal _goal_type;
      _goal_type goal;

    SetElevatorActionGoal():
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

    const char * getType(){ return "robotnik_msgs/SetElevatorActionGoal"; };
    const char * getMD5(){ return "44405fb0ad96ec02bcab6ffde5862da5"; };

  };

}
#endif