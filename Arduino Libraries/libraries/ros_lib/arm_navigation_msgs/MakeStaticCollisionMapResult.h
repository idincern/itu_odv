#ifndef _ROS_arm_navigation_msgs_MakeStaticCollisionMapResult_h
#define _ROS_arm_navigation_msgs_MakeStaticCollisionMapResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_navigation_msgs
{

  class MakeStaticCollisionMapResult : public ros::Msg
  {
    public:

    MakeStaticCollisionMapResult()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MakeStaticCollisionMapResult"; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif