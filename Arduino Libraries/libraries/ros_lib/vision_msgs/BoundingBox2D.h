#ifndef _ROS_vision_msgs_BoundingBox2D_h
#define _ROS_vision_msgs_BoundingBox2D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose2D.h"

namespace vision_msgs
{

  class BoundingBox2D : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose2D _center_type;
      _center_type center;
      typedef double _size_x_type;
      _size_x_type size_x;
      typedef double _size_y_type;
      _size_y_type size_y;

    BoundingBox2D():
      center(),
      size_x(0),
      size_y(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->center.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_size_x;
      u_size_x.real = this->size_x;
      *(outbuffer + offset + 0) = (u_size_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_size_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_size_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_size_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_size_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->size_x);
      union {
        double real;
        uint64_t base;
      } u_size_y;
      u_size_y.real = this->size_y;
      *(outbuffer + offset + 0) = (u_size_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_size_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_size_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_size_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_size_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_size_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_size_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_size_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->size_y);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->center.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_size_x;
      u_size_x.base = 0;
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_size_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->size_x = u_size_x.real;
      offset += sizeof(this->size_x);
      union {
        double real;
        uint64_t base;
      } u_size_y;
      u_size_y.base = 0;
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_size_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->size_y = u_size_y.real;
      offset += sizeof(this->size_y);
     return offset;
    }

    const char * getType(){ return "vision_msgs/BoundingBox2D"; };
    const char * getMD5(){ return "9ab41e2a4c8627735e5091a9abd68b02"; };

  };

}
#endif