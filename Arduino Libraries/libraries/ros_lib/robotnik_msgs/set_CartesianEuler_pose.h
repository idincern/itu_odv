#ifndef _ROS_SERVICE_set_CartesianEuler_pose_h
#define _ROS_SERVICE_set_CartesianEuler_pose_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char SET_CARTESIANEULER_POSE[] = "robotnik_msgs/set_CartesianEuler_pose";

  class set_CartesianEuler_poseRequest : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _z_type;
      _z_type z;
      typedef float _A_type;
      _A_type A;
      typedef float _B_type;
      _B_type B;
      typedef float _C_type;
      _C_type C;

    set_CartesianEuler_poseRequest():
      x(0),
      y(0),
      z(0),
      A(0),
      B(0),
      C(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_A;
      u_A.real = this->A;
      *(outbuffer + offset + 0) = (u_A.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_A.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_A.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_A.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->A);
      union {
        float real;
        uint32_t base;
      } u_B;
      u_B.real = this->B;
      *(outbuffer + offset + 0) = (u_B.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_B.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_B.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_B.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->B);
      union {
        float real;
        uint32_t base;
      } u_C;
      u_C.real = this->C;
      *(outbuffer + offset + 0) = (u_C.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_C.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_C.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_C.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->C);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        float real;
        uint32_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        float real;
        uint32_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        float real;
        uint32_t base;
      } u_A;
      u_A.base = 0;
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_A.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->A = u_A.real;
      offset += sizeof(this->A);
      union {
        float real;
        uint32_t base;
      } u_B;
      u_B.base = 0;
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_B.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->B = u_B.real;
      offset += sizeof(this->B);
      union {
        float real;
        uint32_t base;
      } u_C;
      u_C.base = 0;
      u_C.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_C.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_C.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_C.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->C = u_C.real;
      offset += sizeof(this->C);
     return offset;
    }

    const char * getType(){ return SET_CARTESIANEULER_POSE; };
    const char * getMD5(){ return "cdb2d75b0c143402ced22eff49c8aa05"; };

  };

  class set_CartesianEuler_poseResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    set_CartesianEuler_poseResponse():
      ret(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ret;
      u_ret.real = this->ret;
      *(outbuffer + offset + 0) = (u_ret.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ret);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ret;
      u_ret.base = 0;
      u_ret.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ret = u_ret.real;
      offset += sizeof(this->ret);
     return offset;
    }

    const char * getType(){ return SET_CARTESIANEULER_POSE; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class set_CartesianEuler_pose {
    public:
    typedef set_CartesianEuler_poseRequest Request;
    typedef set_CartesianEuler_poseResponse Response;
  };

}
#endif
