#ifndef _ROS_fiducial_msgs_Fiducial_h
#define _ROS_fiducial_msgs_Fiducial_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace fiducial_msgs
{

  class Fiducial : public ros::Msg
  {
    public:
      typedef int32_t _fiducial_id_type;
      _fiducial_id_type fiducial_id;
      typedef int32_t _direction_type;
      _direction_type direction;
      typedef double _x0_type;
      _x0_type x0;
      typedef double _y0_type;
      _y0_type y0;
      typedef double _x1_type;
      _x1_type x1;
      typedef double _y1_type;
      _y1_type y1;
      typedef double _x2_type;
      _x2_type x2;
      typedef double _y2_type;
      _y2_type y2;
      typedef double _x3_type;
      _x3_type x3;
      typedef double _y3_type;
      _y3_type y3;

    Fiducial():
      fiducial_id(0),
      direction(0),
      x0(0),
      y0(0),
      x1(0),
      y1(0),
      x2(0),
      y2(0),
      x3(0),
      y3(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.real = this->fiducial_id;
      *(outbuffer + offset + 0) = (u_fiducial_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fiducial_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fiducial_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fiducial_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fiducial_id);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.real = this->direction;
      *(outbuffer + offset + 0) = (u_direction.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_direction.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_direction.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_direction.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->direction);
      union {
        double real;
        uint64_t base;
      } u_x0;
      u_x0.real = this->x0;
      *(outbuffer + offset + 0) = (u_x0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x0.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x0.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x0.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x0.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x0.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x0);
      union {
        double real;
        uint64_t base;
      } u_y0;
      u_y0.real = this->y0;
      *(outbuffer + offset + 0) = (u_y0.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y0.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y0.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y0.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y0.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y0.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y0.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y0.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y0);
      union {
        double real;
        uint64_t base;
      } u_x1;
      u_x1.real = this->x1;
      *(outbuffer + offset + 0) = (u_x1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x1);
      union {
        double real;
        uint64_t base;
      } u_y1;
      u_y1.real = this->y1;
      *(outbuffer + offset + 0) = (u_y1.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y1.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y1.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y1.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y1.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y1.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y1.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y1.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y1);
      union {
        double real;
        uint64_t base;
      } u_x2;
      u_x2.real = this->x2;
      *(outbuffer + offset + 0) = (u_x2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x2);
      union {
        double real;
        uint64_t base;
      } u_y2;
      u_y2.real = this->y2;
      *(outbuffer + offset + 0) = (u_y2.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y2.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y2.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y2.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y2.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y2.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y2.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y2.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y2);
      union {
        double real;
        uint64_t base;
      } u_x3;
      u_x3.real = this->x3;
      *(outbuffer + offset + 0) = (u_x3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x3.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x3.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x3.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x3.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x3.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x3);
      union {
        double real;
        uint64_t base;
      } u_y3;
      u_y3.real = this->y3;
      *(outbuffer + offset + 0) = (u_y3.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y3.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y3.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y3.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y3.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y3.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y3.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y3.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y3);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.base = 0;
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fiducial_id = u_fiducial_id.real;
      offset += sizeof(this->fiducial_id);
      union {
        int32_t real;
        uint32_t base;
      } u_direction;
      u_direction.base = 0;
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_direction.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->direction = u_direction.real;
      offset += sizeof(this->direction);
      union {
        double real;
        uint64_t base;
      } u_x0;
      u_x0.base = 0;
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x0.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x0 = u_x0.real;
      offset += sizeof(this->x0);
      union {
        double real;
        uint64_t base;
      } u_y0;
      u_y0.base = 0;
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y0.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y0 = u_y0.real;
      offset += sizeof(this->y0);
      union {
        double real;
        uint64_t base;
      } u_x1;
      u_x1.base = 0;
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x1 = u_x1.real;
      offset += sizeof(this->x1);
      union {
        double real;
        uint64_t base;
      } u_y1;
      u_y1.base = 0;
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y1.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y1 = u_y1.real;
      offset += sizeof(this->y1);
      union {
        double real;
        uint64_t base;
      } u_x2;
      u_x2.base = 0;
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x2 = u_x2.real;
      offset += sizeof(this->x2);
      union {
        double real;
        uint64_t base;
      } u_y2;
      u_y2.base = 0;
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y2.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y2 = u_y2.real;
      offset += sizeof(this->y2);
      union {
        double real;
        uint64_t base;
      } u_x3;
      u_x3.base = 0;
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x3.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x3 = u_x3.real;
      offset += sizeof(this->x3);
      union {
        double real;
        uint64_t base;
      } u_y3;
      u_y3.base = 0;
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y3.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y3 = u_y3.real;
      offset += sizeof(this->y3);
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/Fiducial"; };
    const char * getMD5(){ return "a0094064db6c7772c6b638a2dab17f42"; };

  };

}
#endif