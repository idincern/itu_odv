#ifndef _ROS_vision_msgs_BoundingBox3D_h
#define _ROS_vision_msgs_BoundingBox3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"
#include "geometry_msgs/Vector3.h"

namespace vision_msgs
{

  class BoundingBox3D : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _center_type;
      _center_type center;
      typedef geometry_msgs::Vector3 _size_type;
      _size_type size;

    BoundingBox3D():
      center(),
      size()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->center.serialize(outbuffer + offset);
      offset += this->size.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->center.deserialize(inbuffer + offset);
      offset += this->size.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "vision_msgs/BoundingBox3D"; };
    const char * getMD5(){ return "727c83f2b037373b8e968433d9c84ecb"; };

  };

}
#endif