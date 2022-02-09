#ifndef _ROS_arm_navigation_msgs_PlanningScene_h
#define _ROS_arm_navigation_msgs_PlanningScene_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/RobotState.h"
#include "geometry_msgs/TransformStamped.h"
#include "arm_navigation_msgs/AllowedCollisionMatrix.h"
#include "arm_navigation_msgs/AllowedContactSpecification.h"
#include "arm_navigation_msgs/LinkPadding.h"
#include "arm_navigation_msgs/CollisionObject.h"
#include "arm_navigation_msgs/AttachedCollisionObject.h"
#include "arm_navigation_msgs/CollisionMap.h"

namespace arm_navigation_msgs
{

  class PlanningScene : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;
      uint32_t fixed_frame_transforms_length;
      typedef geometry_msgs::TransformStamped _fixed_frame_transforms_type;
      _fixed_frame_transforms_type st_fixed_frame_transforms;
      _fixed_frame_transforms_type * fixed_frame_transforms;
      typedef arm_navigation_msgs::AllowedCollisionMatrix _allowed_collision_matrix_type;
      _allowed_collision_matrix_type allowed_collision_matrix;
      uint32_t allowed_contacts_length;
      typedef arm_navigation_msgs::AllowedContactSpecification _allowed_contacts_type;
      _allowed_contacts_type st_allowed_contacts;
      _allowed_contacts_type * allowed_contacts;
      uint32_t link_padding_length;
      typedef arm_navigation_msgs::LinkPadding _link_padding_type;
      _link_padding_type st_link_padding;
      _link_padding_type * link_padding;
      uint32_t collision_objects_length;
      typedef arm_navigation_msgs::CollisionObject _collision_objects_type;
      _collision_objects_type st_collision_objects;
      _collision_objects_type * collision_objects;
      uint32_t attached_collision_objects_length;
      typedef arm_navigation_msgs::AttachedCollisionObject _attached_collision_objects_type;
      _attached_collision_objects_type st_attached_collision_objects;
      _attached_collision_objects_type * attached_collision_objects;
      typedef arm_navigation_msgs::CollisionMap _collision_map_type;
      _collision_map_type collision_map;

    PlanningScene():
      robot_state(),
      fixed_frame_transforms_length(0), fixed_frame_transforms(NULL),
      allowed_collision_matrix(),
      allowed_contacts_length(0), allowed_contacts(NULL),
      link_padding_length(0), link_padding(NULL),
      collision_objects_length(0), collision_objects(NULL),
      attached_collision_objects_length(0), attached_collision_objects(NULL),
      collision_map()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->robot_state.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->fixed_frame_transforms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->fixed_frame_transforms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->fixed_frame_transforms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->fixed_frame_transforms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fixed_frame_transforms_length);
      for( uint32_t i = 0; i < fixed_frame_transforms_length; i++){
      offset += this->fixed_frame_transforms[i].serialize(outbuffer + offset);
      }
      offset += this->allowed_collision_matrix.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->allowed_contacts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->allowed_contacts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->allowed_contacts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->allowed_contacts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->allowed_contacts_length);
      for( uint32_t i = 0; i < allowed_contacts_length; i++){
      offset += this->allowed_contacts[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->link_padding_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->link_padding_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->link_padding_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->link_padding_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->link_padding_length);
      for( uint32_t i = 0; i < link_padding_length; i++){
      offset += this->link_padding[i].serialize(outbuffer + offset);
      }
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
      offset += this->collision_map.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->robot_state.deserialize(inbuffer + offset);
      uint32_t fixed_frame_transforms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      fixed_frame_transforms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->fixed_frame_transforms_length);
      if(fixed_frame_transforms_lengthT > fixed_frame_transforms_length)
        this->fixed_frame_transforms = (geometry_msgs::TransformStamped*)realloc(this->fixed_frame_transforms, fixed_frame_transforms_lengthT * sizeof(geometry_msgs::TransformStamped));
      fixed_frame_transforms_length = fixed_frame_transforms_lengthT;
      for( uint32_t i = 0; i < fixed_frame_transforms_length; i++){
      offset += this->st_fixed_frame_transforms.deserialize(inbuffer + offset);
        memcpy( &(this->fixed_frame_transforms[i]), &(this->st_fixed_frame_transforms), sizeof(geometry_msgs::TransformStamped));
      }
      offset += this->allowed_collision_matrix.deserialize(inbuffer + offset);
      uint32_t allowed_contacts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      allowed_contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      allowed_contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      allowed_contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->allowed_contacts_length);
      if(allowed_contacts_lengthT > allowed_contacts_length)
        this->allowed_contacts = (arm_navigation_msgs::AllowedContactSpecification*)realloc(this->allowed_contacts, allowed_contacts_lengthT * sizeof(arm_navigation_msgs::AllowedContactSpecification));
      allowed_contacts_length = allowed_contacts_lengthT;
      for( uint32_t i = 0; i < allowed_contacts_length; i++){
      offset += this->st_allowed_contacts.deserialize(inbuffer + offset);
        memcpy( &(this->allowed_contacts[i]), &(this->st_allowed_contacts), sizeof(arm_navigation_msgs::AllowedContactSpecification));
      }
      uint32_t link_padding_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      link_padding_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->link_padding_length);
      if(link_padding_lengthT > link_padding_length)
        this->link_padding = (arm_navigation_msgs::LinkPadding*)realloc(this->link_padding, link_padding_lengthT * sizeof(arm_navigation_msgs::LinkPadding));
      link_padding_length = link_padding_lengthT;
      for( uint32_t i = 0; i < link_padding_length; i++){
      offset += this->st_link_padding.deserialize(inbuffer + offset);
        memcpy( &(this->link_padding[i]), &(this->st_link_padding), sizeof(arm_navigation_msgs::LinkPadding));
      }
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
      offset += this->collision_map.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/PlanningScene"; };
    const char * getMD5(){ return "6d1add8ef6efdd62d194ef430abd4b75"; };

  };

}
#endif