#ifndef _ROS_arm_navigation_msgs_WorkspaceParameters_h
#define _ROS_arm_navigation_msgs_WorkspaceParameters_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/Shape.h"
#include "geometry_msgs/PoseStamped.h"

namespace arm_navigation_msgs
{

  class WorkspaceParameters : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::Shape _workspace_region_shape_type;
      _workspace_region_shape_type workspace_region_shape;
      typedef geometry_msgs::PoseStamped _workspace_region_pose_type;
      _workspace_region_pose_type workspace_region_pose;

    WorkspaceParameters():
      workspace_region_shape(),
      workspace_region_pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->workspace_region_shape.serialize(outbuffer + offset);
      offset += this->workspace_region_pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->workspace_region_shape.deserialize(inbuffer + offset);
      offset += this->workspace_region_pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/WorkspaceParameters"; };
    const char * getMD5(){ return "1487490edff0df276863abf2cf221de5"; };

  };

}
#endif