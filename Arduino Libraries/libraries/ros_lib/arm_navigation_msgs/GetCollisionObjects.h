#ifndef _ROS_SERVICE_GetCollisionObjects_h
#define _ROS_SERVICE_GetCollisionObjects_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/CollisionMap.h"
#include "arm_navigation_msgs/CollisionObject.h"
#include "arm_navigation_msgs/AttachedCollisionObject.h"

namespace arm_navigation_msgs
{

static const char GETCOLLISIONOBJECTS[] = "arm_navigation_msgs/GetCollisionObjects";

  class GetCollisionObjectsRequest : public ros::Msg
  {
    public:
      typedef bool _include_points_type;
      _include_points_type include_points;

    GetCollisionObjectsRequest():
      include_points(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_include_points;
      u_include_points.real = this->include_points;
      *(outbuffer + offset + 0) = (u_include_points.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->include_points);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_include_points;
      u_include_points.base = 0;
      u_include_points.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->include_points = u_include_points.real;
      offset += sizeof(this->include_points);
     return offset;
    }

    const char * getType(){ return GETCOLLISIONOBJECTS; };
    const char * getMD5(){ return "3ae7288b23c84452d229e442c1673708"; };

  };

  class GetCollisionObjectsResponse : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::CollisionMap _points_type;
      _points_type points;
      uint32_t collision_objects_length;
      typedef arm_navigation_msgs::CollisionObject _collision_objects_type;
      _collision_objects_type st_collision_objects;
      _collision_objects_type * collision_objects;
      uint32_t attached_collision_objects_length;
      typedef arm_navigation_msgs::AttachedCollisionObject _attached_collision_objects_type;
      _attached_collision_objects_type st_attached_collision_objects;
      _attached_collision_objects_type * attached_collision_objects;

    GetCollisionObjectsResponse():
      points(),
      collision_objects_length(0), collision_objects(NULL),
      attached_collision_objects_length(0), attached_collision_objects(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->points.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->collision_objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->collision_objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->collision_objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->collision_objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->collision_objects_length);
      for( uint32_t i = 0; i < collision_objects_length; i++){
      offset += this->collision_objects[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->attached_collision_objects_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->attached_collision_objects_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->attached_collision_objects_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->attached_collision_objects_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->attached_collision_objects_length);
      for( uint32_t i = 0; i < attached_collision_objects_length; i++){
      offset += this->attached_collision_objects[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->points.deserialize(inbuffer + offset);
      uint32_t collision_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->collision_objects_length);
      if(collision_objects_lengthT > collision_objects_length)
        this->collision_objects = (arm_navigation_msgs::CollisionObject*)realloc(this->collision_objects, collision_objects_lengthT * sizeof(arm_navigation_msgs::CollisionObject));
      collision_objects_length = collision_objects_lengthT;
      for( uint32_t i = 0; i < collision_objects_length; i++){
      offset += this->st_collision_objects.deserialize(inbuffer + offset);
        memcpy( &(this->collision_objects[i]), &(this->st_collision_objects), sizeof(arm_navigation_msgs::CollisionObject));
      }
      uint32_t attached_collision_objects_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      attached_collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      attached_collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      attached_collision_objects_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->attached_collision_objects_length);
      if(attached_collision_objects_lengthT > attached_collision_objects_length)
        this->attached_collision_objects = (arm_navigation_msgs::AttachedCollisionObject*)realloc(this->attached_collision_objects, attached_collision_objects_lengthT * sizeof(arm_navigation_msgs::AttachedCollisionObject));
      attached_collision_objects_length = attached_collision_objects_lengthT;
      for( uint32_t i = 0; i < attached_collision_objects_length; i++){
      offset += this->st_attached_collision_objects.deserialize(inbuffer + offset);
        memcpy( &(this->attached_collision_objects[i]), &(this->st_attached_collision_objects), sizeof(arm_navigation_msgs::AttachedCollisionObject));
      }
     return offset;
    }

    const char * getType(){ return GETCOLLISIONOBJECTS; };
    const char * getMD5(){ return "c361b849f4eb74ea667a930b0b9dc801"; };

  };

  class GetCollisionObjects {
    public:
    typedef GetCollisionObjectsRequest Request;
    typedef GetCollisionObjectsResponse Response;
  };

}
#endif
