#ifndef _ROS_arm_navigation_msgs_SyncPlanningSceneResult_h
#define _ROS_arm_navigation_msgs_SyncPlanningSceneResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_navigation_msgs
{

  class SyncPlanningSceneResult : public ros::Msg
  {
    public:
      typedef bool _ok_type;
      _ok_type ok;

    SyncPlanningSceneResult():
      ok(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.real = this->ok;
      *(outbuffer + offset + 0) = (u_ok.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ok);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ok;
      u_ok.base = 0;
      u_ok.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ok = u_ok.real;
      offset += sizeof(this->ok);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/SyncPlanningSceneResult"; };
    const char * getMD5(){ return "6f6da3883749771fac40d6deb24a8c02"; };

  };

}
#endif