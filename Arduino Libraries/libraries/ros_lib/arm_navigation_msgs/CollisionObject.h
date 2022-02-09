#ifndef _ROS_arm_navigation_msgs_CollisionObject_h
#define _ROS_arm_navigation_msgs_CollisionObject_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "arm_navigation_msgs/CollisionObjectOperation.h"
#include "arm_navigation_msgs/Shape.h"
#include "geometry_msgs/Pose.h"

namespace arm_navigation_msgs
{

  class CollisionObject : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _id_type;
      _id_type id;
      typedef float _padding_type;
      _padding_type padding;
      typedef arm_navigation_msgs::CollisionObjectOperation _operation_type;
      _operation_type operation;
      uint32_t shapes_length;
      typedef arm_navigation_msgs::Shape _shapes_type;
      _shapes_type st_shapes;
      _shapes_type * shapes;
      uint32_t poses_length;
      typedef geometry_msgs::Pose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    CollisionObject():
      header(),
      id(""),
      padding(0),
      operation(),
      shapes_length(0), shapes(NULL),
      poses_length(0), poses(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      union {
        float real;
        uint32_t base;
      } u_padding;
      u_padding.real = this->padding;
      *(outbuffer + offset + 0) = (u_padding.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_padding.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_padding.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_padding.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->padding);
      offset += this->operation.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->shapes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->shapes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->shapes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->shapes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->shapes_length);
      for( uint32_t i = 0; i < shapes_length; i++){
      offset += this->shapes[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      union {
        float real;
        uint32_t base;
      } u_padding;
      u_padding.base = 0;
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_padding.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->padding = u_padding.real;
      offset += sizeof(this->padding);
      offset += this->operation.deserialize(inbuffer + offset);
      uint32_t shapes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      shapes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      shapes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      shapes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->shapes_length);
      if(shapes_lengthT > shapes_length)
        this->shapes = (arm_navigation_msgs::Shape*)realloc(this->shapes, shapes_lengthT * sizeof(arm_navigation_msgs::Shape));
      shapes_length = shapes_lengthT;
      for( uint32_t i = 0; i < shapes_length; i++){
      offset += this->st_shapes.deserialize(inbuffer + offset);
        memcpy( &(this->shapes[i]), &(this->st_shapes), sizeof(arm_navigation_msgs::Shape));
      }
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (geometry_msgs::Pose*)realloc(this->poses, poses_lengthT * sizeof(geometry_msgs::Pose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(geometry_msgs::Pose));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/CollisionObject"; };
    const char * getMD5(){ return "7b972910c23ece1b873b3de0cf92ba97"; };

  };

}
#endif