#ifndef _ROS_arm_navigation_msgs_VisibilityConstraint_h
#define _ROS_arm_navigation_msgs_VisibilityConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/PointStamped.h"
#include "geometry_msgs/PoseStamped.h"

namespace arm_navigation_msgs
{

  class VisibilityConstraint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef geometry_msgs::PointStamped _target_type;
      _target_type target;
      typedef geometry_msgs::PoseStamped _sensor_pose_type;
      _sensor_pose_type sensor_pose;
      typedef double _absolute_tolerance_type;
      _absolute_tolerance_type absolute_tolerance;

    VisibilityConstraint():
      header(),
      target(),
      sensor_pose(),
      absolute_tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->target.serialize(outbuffer + offset);
      offset += this->sensor_pose.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_absolute_tolerance;
      u_absolute_tolerance.real = this->absolute_tolerance;
      *(outbuffer + offset + 0) = (u_absolute_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_absolute_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_absolute_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_absolute_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_absolute_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_absolute_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_absolute_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_absolute_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->absolute_tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->target.deserialize(inbuffer + offset);
      offset += this->sensor_pose.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_absolute_tolerance;
      u_absolute_tolerance.base = 0;
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_absolute_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->absolute_tolerance = u_absolute_tolerance.real;
      offset += sizeof(this->absolute_tolerance);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/VisibilityConstraint"; };
    const char * getMD5(){ return "ab297b6588ea21c1a862067d8447cb08"; };

  };

}
#endif