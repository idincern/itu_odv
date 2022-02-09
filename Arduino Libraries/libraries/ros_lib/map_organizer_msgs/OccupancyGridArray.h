#ifndef _ROS_map_organizer_msgs_OccupancyGridArray_h
#define _ROS_map_organizer_msgs_OccupancyGridArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "nav_msgs/OccupancyGrid.h"

namespace map_organizer_msgs
{

  class OccupancyGridArray : public ros::Msg
  {
    public:
      uint32_t maps_length;
      typedef nav_msgs::OccupancyGrid _maps_type;
      _maps_type st_maps;
      _maps_type * maps;

    OccupancyGridArray():
      maps_length(0), maps(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->maps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->maps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->maps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->maps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->maps_length);
      for( uint32_t i = 0; i < maps_length; i++){
      offset += this->maps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t maps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      maps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      maps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      maps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->maps_length);
      if(maps_lengthT > maps_length)
        this->maps = (nav_msgs::OccupancyGrid*)realloc(this->maps, maps_lengthT * sizeof(nav_msgs::OccupancyGrid));
      maps_length = maps_lengthT;
      for( uint32_t i = 0; i < maps_length; i++){
      offset += this->st_maps.deserialize(inbuffer + offset);
        memcpy( &(this->maps[i]), &(this->st_maps), sizeof(nav_msgs::OccupancyGrid));
      }
     return offset;
    }

    const char * getType(){ return "map_organizer_msgs/OccupancyGridArray"; };
    const char * getMD5(){ return "85454c38b6be9c50825ab01fbdf78776"; };

  };

}
#endif