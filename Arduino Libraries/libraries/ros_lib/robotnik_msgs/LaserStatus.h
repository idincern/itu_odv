#ifndef _ROS_robotnik_msgs_LaserStatus_h
#define _ROS_robotnik_msgs_LaserStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class LaserStatus : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef bool _detecting_obstacles_type;
      _detecting_obstacles_type detecting_obstacles;
      typedef bool _contaminated_type;
      _contaminated_type contaminated;
      typedef bool _free_warning_type;
      _free_warning_type free_warning;

    LaserStatus():
      name(""),
      detecting_obstacles(0),
      contaminated(0),
      free_warning(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_detecting_obstacles;
      u_detecting_obstacles.real = this->detecting_obstacles;
      *(outbuffer + offset + 0) = (u_detecting_obstacles.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->detecting_obstacles);
      union {
        bool real;
        uint8_t base;
      } u_contaminated;
      u_contaminated.real = this->contaminated;
      *(outbuffer + offset + 0) = (u_contaminated.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contaminated);
      union {
        bool real;
        uint8_t base;
      } u_free_warning;
      u_free_warning.real = this->free_warning;
      *(outbuffer + offset + 0) = (u_free_warning.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->free_warning);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      union {
        bool real;
        uint8_t base;
      } u_detecting_obstacles;
      u_detecting_obstacles.base = 0;
      u_detecting_obstacles.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->detecting_obstacles = u_detecting_obstacles.real;
      offset += sizeof(this->detecting_obstacles);
      union {
        bool real;
        uint8_t base;
      } u_contaminated;
      u_contaminated.base = 0;
      u_contaminated.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contaminated = u_contaminated.real;
      offset += sizeof(this->contaminated);
      union {
        bool real;
        uint8_t base;
      } u_free_warning;
      u_free_warning.base = 0;
      u_free_warning.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->free_warning = u_free_warning.real;
      offset += sizeof(this->free_warning);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/LaserStatus"; };
    const char * getMD5(){ return "1cf385df770632b74a2a5b1755bf77f3"; };

  };

}
#endif