#ifndef _ROS_waypoints_waypoint_array_h
#define _ROS_waypoints_waypoint_array_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "waypoints/waypoint_msg.h"
#include "waypoints/waypoint_group.h"

namespace waypoints
{

  class waypoint_array : public ros::Msg
  {
    public:
      typedef const char* _header_type;
      _header_type header;
      uint32_t waypoints_length;
      typedef waypoints::waypoint_msg _waypoints_type;
      _waypoints_type st_waypoints;
      _waypoints_type * waypoints;
      uint32_t groups_length;
      typedef waypoints::waypoint_group _groups_type;
      _groups_type st_groups;
      _groups_type * groups;

    waypoint_array():
      header(""),
      waypoints_length(0), waypoints(NULL),
      groups_length(0), groups(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_header = strlen(this->header);
      varToArr(outbuffer + offset, length_header);
      offset += 4;
      memcpy(outbuffer + offset, this->header, length_header);
      offset += length_header;
      *(outbuffer + offset + 0) = (this->waypoints_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->waypoints_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->waypoints_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->waypoints_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->waypoints_length);
      for( uint32_t i = 0; i < waypoints_length; i++){
      offset += this->waypoints[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->groups_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->groups_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->groups_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->groups_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->groups_length);
      for( uint32_t i = 0; i < groups_length; i++){
      offset += this->groups[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_header;
      arrToVar(length_header, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_header; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_header-1]=0;
      this->header = (char *)(inbuffer + offset-1);
      offset += length_header;
      uint32_t waypoints_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      waypoints_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->waypoints_length);
      if(waypoints_lengthT > waypoints_length)
        this->waypoints = (waypoints::waypoint_msg*)realloc(this->waypoints, waypoints_lengthT * sizeof(waypoints::waypoint_msg));
      waypoints_length = waypoints_lengthT;
      for( uint32_t i = 0; i < waypoints_length; i++){
      offset += this->st_waypoints.deserialize(inbuffer + offset);
        memcpy( &(this->waypoints[i]), &(this->st_waypoints), sizeof(waypoints::waypoint_msg));
      }
      uint32_t groups_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      groups_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->groups_length);
      if(groups_lengthT > groups_length)
        this->groups = (waypoints::waypoint_group*)realloc(this->groups, groups_lengthT * sizeof(waypoints::waypoint_group));
      groups_length = groups_lengthT;
      for( uint32_t i = 0; i < groups_length; i++){
      offset += this->st_groups.deserialize(inbuffer + offset);
        memcpy( &(this->groups[i]), &(this->st_groups), sizeof(waypoints::waypoint_group));
      }
     return offset;
    }

    const char * getType(){ return "waypoints/waypoint_array"; };
    const char * getMD5(){ return "50bb2806cd484cc8094f17a9e088e071"; };

  };

}
#endif