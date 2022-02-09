#ifndef _ROS_arm_navigation_msgs_OrientedBoundingBox_h
#define _ROS_arm_navigation_msgs_OrientedBoundingBox_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point32.h"

namespace arm_navigation_msgs
{

  class OrientedBoundingBox : public ros::Msg
  {
    public:
      typedef geometry_msgs::Point32 _center_type;
      _center_type center;
      typedef geometry_msgs::Point32 _extents_type;
      _extents_type extents;
      typedef geometry_msgs::Point32 _axis_type;
      _axis_type axis;
      typedef float _angle_type;
      _angle_type angle;

    OrientedBoundingBox():
      center(),
      extents(),
      axis(),
      angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->center.serialize(outbuffer + offset);
      offset += this->extents.serialize(outbuffer + offset);
      offset += this->axis.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.real = this->angle;
      *(outbuffer + offset + 0) = (u_angle.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_angle.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_angle.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_angle.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->center.deserialize(inbuffer + offset);
      offset += this->extents.deserialize(inbuffer + offset);
      offset += this->axis.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_angle;
      u_angle.base = 0;
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_angle.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->angle = u_angle.real;
      offset += sizeof(this->angle);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/OrientedBoundingBox"; };
    const char * getMD5(){ return "a9b13162620bd04a7cb84cf207e7a8ac"; };

  };

}
#endif