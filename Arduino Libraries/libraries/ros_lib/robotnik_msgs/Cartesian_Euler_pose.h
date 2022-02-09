#ifndef _ROS_robotnik_msgs_Cartesian_Euler_pose_h
#define _ROS_robotnik_msgs_Cartesian_Euler_pose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class Cartesian_Euler_pose : public ros::Msg
  {
    public:
      typedef double _x_type;
      _x_type x;
      typedef double _y_type;
      _y_type y;
      typedef double _z_type;
      _z_type z;
      typedef double _A_type;
      _A_type A;
      typedef double _B_type;
      _B_type B;
      typedef double _C_type;
      _C_type C;

    Cartesian_Euler_pose():
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
        double real;
        uint64_t base;
      } u_x;
      u_x.real = this->x;
      *(outbuffer + offset + 0) = (u_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_x.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_x.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_x.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_x.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_x.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_x.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_x.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.real = this->y;
      *(outbuffer + offset + 0) = (u_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_y.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_y.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_y.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_y.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_y.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_y.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_y.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.real = this->z;
      *(outbuffer + offset + 0) = (u_z.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_z.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_z.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_z.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_z.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_z.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_z.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_z.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->z);
      union {
        double real;
        uint64_t base;
      } u_A;
      u_A.real = this->A;
      *(outbuffer + offset + 0) = (u_A.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_A.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_A.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_A.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_A.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_A.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_A.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_A.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->A);
      union {
        double real;
        uint64_t base;
      } u_B;
      u_B.real = this->B;
      *(outbuffer + offset + 0) = (u_B.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_B.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_B.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_B.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_B.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_B.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_B.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_B.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->B);
      union {
        double real;
        uint64_t base;
      } u_C;
      u_C.real = this->C;
      *(outbuffer + offset + 0) = (u_C.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_C.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_C.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_C.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_C.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_C.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_C.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_C.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->C);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_x;
      u_x.base = 0;
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_x.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->x = u_x.real;
      offset += sizeof(this->x);
      union {
        double real;
        uint64_t base;
      } u_y;
      u_y.base = 0;
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_y.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->y = u_y.real;
      offset += sizeof(this->y);
      union {
        double real;
        uint64_t base;
      } u_z;
      u_z.base = 0;
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_z.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->z = u_z.real;
      offset += sizeof(this->z);
      union {
        double real;
        uint64_t base;
      } u_A;
      u_A.base = 0;
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_A.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->A = u_A.real;
      offset += sizeof(this->A);
      union {
        double real;
        uint64_t base;
      } u_B;
      u_B.base = 0;
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_B.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->B = u_B.real;
      offset += sizeof(this->B);
      union {
        double real;
        uint64_t base;
      } u_C;
      u_C.base = 0;
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_C.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->C = u_C.real;
      offset += sizeof(this->C);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/Cartesian_Euler_pose"; };
    const char * getMD5(){ return "1b7d5ac5679ead09b31ec87e784aa10e"; };

  };

}
#endif