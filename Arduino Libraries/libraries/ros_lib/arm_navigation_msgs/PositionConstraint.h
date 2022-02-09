#ifndef _ROS_arm_navigation_msgs_PositionConstraint_h
#define _ROS_arm_navigation_msgs_PositionConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"
#include "arm_navigation_msgs/Shape.h"
#include "geometry_msgs/Quaternion.h"

namespace arm_navigation_msgs
{

  class PositionConstraint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _link_name_type;
      _link_name_type link_name;
      typedef geometry_msgs::Point _target_point_offset_type;
      _target_point_offset_type target_point_offset;
      typedef geometry_msgs::Point _position_type;
      _position_type position;
      typedef arm_navigation_msgs::Shape _constraint_region_shape_type;
      _constraint_region_shape_type constraint_region_shape;
      typedef geometry_msgs::Quaternion _constraint_region_orientation_type;
      _constraint_region_orientation_type constraint_region_orientation;
      typedef double _weight_type;
      _weight_type weight;

    PositionConstraint():
      header(),
      link_name(""),
      target_point_offset(),
      position(),
      constraint_region_shape(),
      constraint_region_orientation(),
      weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_link_name = strlen(this->link_name);
      varToArr(outbuffer + offset, length_link_name);
      offset += 4;
      memcpy(outbuffer + offset, this->link_name, length_link_name);
      offset += length_link_name;
      offset += this->target_point_offset.serialize(outbuffer + offset);
      offset += this->position.serialize(outbuffer + offset);
      offset += this->constraint_region_shape.serialize(outbuffer + offset);
      offset += this->constraint_region_orientation.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_weight;
      u_weight.real = this->weight;
      *(outbuffer + offset + 0) = (u_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_weight.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_weight.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_weight.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_weight.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_weight.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_link_name;
      arrToVar(length_link_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_name-1]=0;
      this->link_name = (char *)(inbuffer + offset-1);
      offset += length_link_name;
      offset += this->target_point_offset.deserialize(inbuffer + offset);
      offset += this->position.deserialize(inbuffer + offset);
      offset += this->constraint_region_shape.deserialize(inbuffer + offset);
      offset += this->constraint_region_orientation.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_weight;
      u_weight.base = 0;
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_weight.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->weight = u_weight.real;
      offset += sizeof(this->weight);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/PositionConstraint"; };
    const char * getMD5(){ return "7e3d9697e64b346b9d3cb7311bb88ccb"; };

  };

}
#endif