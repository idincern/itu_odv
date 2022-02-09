#ifndef _ROS_arm_navigation_msgs_CollisionObjectOperation_h
#define _ROS_arm_navigation_msgs_CollisionObjectOperation_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_navigation_msgs
{

  class CollisionObjectOperation : public ros::Msg
  {
    public:
      typedef int8_t _operation_type;
      _operation_type operation;
      enum { ADD = 0 };
      enum { REMOVE = 1 };
      enum { DETACH_AND_ADD_AS_OBJECT = 2 };
      enum { ATTACH_AND_REMOVE_AS_OBJECT = 3 };

    CollisionObjectOperation():
      operation(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_operation;
      u_operation.real = this->operation;
      *(outbuffer + offset + 0) = (u_operation.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_operation;
      u_operation.base = 0;
      u_operation.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation = u_operation.real;
      offset += sizeof(this->operation);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/CollisionObjectOperation"; };
    const char * getMD5(){ return "66a2b3b971d193145f8da8c3e401a474"; };

  };

}
#endif