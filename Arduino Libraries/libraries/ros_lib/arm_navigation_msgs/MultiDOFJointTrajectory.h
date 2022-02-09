#ifndef _ROS_arm_navigation_msgs_MultiDOFJointTrajectory_h
#define _ROS_arm_navigation_msgs_MultiDOFJointTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/duration.h"
#include "arm_navigation_msgs/MultiDOFJointTrajectoryPoint.h"

namespace arm_navigation_msgs
{

  class MultiDOFJointTrajectory : public ros::Msg
  {
    public:
      typedef ros::Duration _stamp_type;
      _stamp_type stamp;
      uint32_t joint_names_length;
      typedef char* _joint_names_type;
      _joint_names_type st_joint_names;
      _joint_names_type * joint_names;
      uint32_t frame_ids_length;
      typedef char* _frame_ids_type;
      _frame_ids_type st_frame_ids;
      _frame_ids_type * frame_ids;
      uint32_t child_frame_ids_length;
      typedef char* _child_frame_ids_type;
      _child_frame_ids_type st_child_frame_ids;
      _child_frame_ids_type * child_frame_ids;
      uint32_t points_length;
      typedef arm_navigation_msgs::MultiDOFJointTrajectoryPoint _points_type;
      _points_type st_points;
      _points_type * points;

    MultiDOFJointTrajectory():
      stamp(),
      joint_names_length(0), joint_names(NULL),
      frame_ids_length(0), frame_ids(NULL),
      child_frame_ids_length(0), child_frame_ids(NULL),
      points_length(0), points(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      *(outbuffer + offset + 0) = (this->joint_names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->joint_names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->joint_names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->joint_names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->joint_names_length);
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_joint_namesi = strlen(this->joint_names[i]);
      varToArr(outbuffer + offset, length_joint_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->joint_names[i], length_joint_namesi);
      offset += length_joint_namesi;
      }
      *(outbuffer + offset + 0) = (this->frame_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->frame_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->frame_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->frame_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frame_ids_length);
      for( uint32_t i = 0; i < frame_ids_length; i++){
      uint32_t length_frame_idsi = strlen(this->frame_ids[i]);
      varToArr(outbuffer + offset, length_frame_idsi);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_ids[i], length_frame_idsi);
      offset += length_frame_idsi;
      }
      *(outbuffer + offset + 0) = (this->child_frame_ids_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->child_frame_ids_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->child_frame_ids_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->child_frame_ids_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->child_frame_ids_length);
      for( uint32_t i = 0; i < child_frame_ids_length; i++){
      uint32_t length_child_frame_idsi = strlen(this->child_frame_ids[i]);
      varToArr(outbuffer + offset, length_child_frame_idsi);
      offset += 4;
      memcpy(outbuffer + offset, this->child_frame_ids[i], length_child_frame_idsi);
      offset += length_child_frame_idsi;
      }
      *(outbuffer + offset + 0) = (this->points_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->points_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->points_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->points_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->points_length);
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->points[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
      uint32_t joint_names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      joint_names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->joint_names_length);
      if(joint_names_lengthT > joint_names_length)
        this->joint_names = (char**)realloc(this->joint_names, joint_names_lengthT * sizeof(char*));
      joint_names_length = joint_names_lengthT;
      for( uint32_t i = 0; i < joint_names_length; i++){
      uint32_t length_st_joint_names;
      arrToVar(length_st_joint_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_joint_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_joint_names-1]=0;
      this->st_joint_names = (char *)(inbuffer + offset-1);
      offset += length_st_joint_names;
        memcpy( &(this->joint_names[i]), &(this->st_joint_names), sizeof(char*));
      }
      uint32_t frame_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      frame_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      frame_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      frame_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->frame_ids_length);
      if(frame_ids_lengthT > frame_ids_length)
        this->frame_ids = (char**)realloc(this->frame_ids, frame_ids_lengthT * sizeof(char*));
      frame_ids_length = frame_ids_lengthT;
      for( uint32_t i = 0; i < frame_ids_length; i++){
      uint32_t length_st_frame_ids;
      arrToVar(length_st_frame_ids, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_frame_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_frame_ids-1]=0;
      this->st_frame_ids = (char *)(inbuffer + offset-1);
      offset += length_st_frame_ids;
        memcpy( &(this->frame_ids[i]), &(this->st_frame_ids), sizeof(char*));
      }
      uint32_t child_frame_ids_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      child_frame_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      child_frame_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      child_frame_ids_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->child_frame_ids_length);
      if(child_frame_ids_lengthT > child_frame_ids_length)
        this->child_frame_ids = (char**)realloc(this->child_frame_ids, child_frame_ids_lengthT * sizeof(char*));
      child_frame_ids_length = child_frame_ids_lengthT;
      for( uint32_t i = 0; i < child_frame_ids_length; i++){
      uint32_t length_st_child_frame_ids;
      arrToVar(length_st_child_frame_ids, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_child_frame_ids; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_child_frame_ids-1]=0;
      this->st_child_frame_ids = (char *)(inbuffer + offset-1);
      offset += length_st_child_frame_ids;
        memcpy( &(this->child_frame_ids[i]), &(this->st_child_frame_ids), sizeof(char*));
      }
      uint32_t points_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      points_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->points_length);
      if(points_lengthT > points_length)
        this->points = (arm_navigation_msgs::MultiDOFJointTrajectoryPoint*)realloc(this->points, points_lengthT * sizeof(arm_navigation_msgs::MultiDOFJointTrajectoryPoint));
      points_length = points_lengthT;
      for( uint32_t i = 0; i < points_length; i++){
      offset += this->st_points.deserialize(inbuffer + offset);
        memcpy( &(this->points[i]), &(this->st_points), sizeof(arm_navigation_msgs::MultiDOFJointTrajectoryPoint));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MultiDOFJointTrajectory"; };
    const char * getMD5(){ return "524f128fb0a65e2838b0e3e3f75207d0"; };

  };

}
#endif