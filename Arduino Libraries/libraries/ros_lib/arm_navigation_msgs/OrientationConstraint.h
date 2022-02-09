#ifndef _ROS_arm_navigation_msgs_OrientationConstraint_h
#define _ROS_arm_navigation_msgs_OrientationConstraint_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Quaternion.h"

namespace arm_navigation_msgs
{

  class OrientationConstraint : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _link_name_type;
      _link_name_type link_name;
      typedef int32_t _type_type;
      _type_type type;
      typedef geometry_msgs::Quaternion _orientation_type;
      _orientation_type orientation;
      typedef double _absolute_roll_tolerance_type;
      _absolute_roll_tolerance_type absolute_roll_tolerance;
      typedef double _absolute_pitch_tolerance_type;
      _absolute_pitch_tolerance_type absolute_pitch_tolerance;
      typedef double _absolute_yaw_tolerance_type;
      _absolute_yaw_tolerance_type absolute_yaw_tolerance;
      typedef double _weight_type;
      _weight_type weight;
      enum { LINK_FRAME = 0 };
      enum { HEADER_FRAME = 1 };

    OrientationConstraint():
      header(),
      link_name(""),
      type(0),
      orientation(),
      absolute_roll_tolerance(0),
      absolute_pitch_tolerance(0),
      absolute_yaw_tolerance(0),
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
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_type.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_type.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_type.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->type);
      offset += this->orientation.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_absolute_roll_tolerance;
      u_absolute_roll_tolerance.real = this->absolute_roll_tolerance;
      *(outbuffer + offset + 0) = (u_absolute_roll_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_absolute_roll_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_absolute_roll_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_absolute_roll_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_absolute_roll_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_absolute_roll_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_absolute_roll_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_absolute_roll_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->absolute_roll_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_pitch_tolerance;
      u_absolute_pitch_tolerance.real = this->absolute_pitch_tolerance;
      *(outbuffer + offset + 0) = (u_absolute_pitch_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_absolute_pitch_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_absolute_pitch_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_absolute_pitch_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_absolute_pitch_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_absolute_pitch_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_absolute_pitch_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_absolute_pitch_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->absolute_pitch_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_yaw_tolerance;
      u_absolute_yaw_tolerance.real = this->absolute_yaw_tolerance;
      *(outbuffer + offset + 0) = (u_absolute_yaw_tolerance.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_absolute_yaw_tolerance.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_absolute_yaw_tolerance.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_absolute_yaw_tolerance.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_absolute_yaw_tolerance.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_absolute_yaw_tolerance.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_absolute_yaw_tolerance.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_absolute_yaw_tolerance.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->absolute_yaw_tolerance);
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
      union {
        int32_t real;
        uint32_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_type.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->type = u_type.real;
      offset += sizeof(this->type);
      offset += this->orientation.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_absolute_roll_tolerance;
      u_absolute_roll_tolerance.base = 0;
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_absolute_roll_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->absolute_roll_tolerance = u_absolute_roll_tolerance.real;
      offset += sizeof(this->absolute_roll_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_pitch_tolerance;
      u_absolute_pitch_tolerance.base = 0;
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_absolute_pitch_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->absolute_pitch_tolerance = u_absolute_pitch_tolerance.real;
      offset += sizeof(this->absolute_pitch_tolerance);
      union {
        double real;
        uint64_t base;
      } u_absolute_yaw_tolerance;
      u_absolute_yaw_tolerance.base = 0;
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_absolute_yaw_tolerance.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->absolute_yaw_tolerance = u_absolute_yaw_tolerance.real;
      offset += sizeof(this->absolute_yaw_tolerance);
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

    const char * getType(){ return "arm_navigation_msgs/OrientationConstraint"; };
    const char * getMD5(){ return "27d99749ba49d4a822298bbd1e0988ba"; };

  };

}
#endif