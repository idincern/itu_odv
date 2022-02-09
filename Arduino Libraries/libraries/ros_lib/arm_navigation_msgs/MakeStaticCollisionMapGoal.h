#ifndef _ROS_arm_navigation_msgs_MakeStaticCollisionMapGoal_h
#define _ROS_arm_navigation_msgs_MakeStaticCollisionMapGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace arm_navigation_msgs
{

  class MakeStaticCollisionMapGoal : public ros::Msg
  {
    public:
      typedef const char* _cloud_source_type;
      _cloud_source_type cloud_source;
      typedef int32_t _number_of_clouds_type;
      _number_of_clouds_type number_of_clouds;

    MakeStaticCollisionMapGoal():
      cloud_source(""),
      number_of_clouds(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_cloud_source = strlen(this->cloud_source);
      varToArr(outbuffer + offset, length_cloud_source);
      offset += 4;
      memcpy(outbuffer + offset, this->cloud_source, length_cloud_source);
      offset += length_cloud_source;
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_clouds;
      u_number_of_clouds.real = this->number_of_clouds;
      *(outbuffer + offset + 0) = (u_number_of_clouds.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_number_of_clouds.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_number_of_clouds.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_number_of_clouds.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_clouds);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_cloud_source;
      arrToVar(length_cloud_source, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_cloud_source; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_cloud_source-1]=0;
      this->cloud_source = (char *)(inbuffer + offset-1);
      offset += length_cloud_source;
      union {
        int32_t real;
        uint32_t base;
      } u_number_of_clouds;
      u_number_of_clouds.base = 0;
      u_number_of_clouds.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_number_of_clouds.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_number_of_clouds.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_number_of_clouds.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->number_of_clouds = u_number_of_clouds.real;
      offset += sizeof(this->number_of_clouds);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MakeStaticCollisionMapGoal"; };
    const char * getMD5(){ return "43564281ea7e3c1ca0f01095edc909f7"; };

  };

}
#endif