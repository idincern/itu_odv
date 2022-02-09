#ifndef _ROS_arm_navigation_msgs_SyncPlanningSceneGoal_h
#define _ROS_arm_navigation_msgs_SyncPlanningSceneGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/PlanningScene.h"

namespace arm_navigation_msgs
{

  class SyncPlanningSceneGoal : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::PlanningScene _planning_scene_type;
      _planning_scene_type planning_scene;

    SyncPlanningSceneGoal():
      planning_scene()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->planning_scene.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->planning_scene.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/SyncPlanningSceneGoal"; };
    const char * getMD5(){ return "285525c9abe002fbafa99af84a14b4cb"; };

  };

}
#endif