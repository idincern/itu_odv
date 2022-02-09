#ifndef _ROS_robotnik_msgs_RobotnikMotorsStatus_h
#define _ROS_robotnik_msgs_RobotnikMotorsStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/MotorStatus.h"

namespace robotnik_msgs
{

  class RobotnikMotorsStatus : public ros::Msg
  {
    public:
      uint32_t name_length;
      typedef char* _name_type;
      _name_type st_name;
      _name_type * name;
      uint32_t can_id_length;
      typedef int32_t _can_id_type;
      _can_id_type st_can_id;
      _can_id_type * can_id;
      uint32_t motor_status_length;
      typedef robotnik_msgs::MotorStatus _motor_status_type;
      _motor_status_type st_motor_status;
      _motor_status_type * motor_status;

    RobotnikMotorsStatus():
      name_length(0), name(NULL),
      can_id_length(0), can_id(NULL),
      motor_status_length(0), motor_status(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->name_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->name_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->name_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->name_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->name_length);
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_namei = strlen(this->name[i]);
      varToArr(outbuffer + offset, length_namei);
      offset += 4;
      memcpy(outbuffer + offset, this->name[i], length_namei);
      offset += length_namei;
      }
      *(outbuffer + offset + 0) = (this->can_id_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->can_id_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->can_id_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->can_id_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->can_id_length);
      for( uint32_t i = 0; i < can_id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_can_idi;
      u_can_idi.real = this->can_id[i];
      *(outbuffer + offset + 0) = (u_can_idi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_can_idi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_can_idi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_can_idi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->can_id[i]);
      }
      *(outbuffer + offset + 0) = (this->motor_status_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->motor_status_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->motor_status_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->motor_status_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->motor_status_length);
      for( uint32_t i = 0; i < motor_status_length; i++){
      offset += this->motor_status[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t name_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      name_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->name_length);
      if(name_lengthT > name_length)
        this->name = (char**)realloc(this->name, name_lengthT * sizeof(char*));
      name_length = name_lengthT;
      for( uint32_t i = 0; i < name_length; i++){
      uint32_t length_st_name;
      arrToVar(length_st_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_name-1]=0;
      this->st_name = (char *)(inbuffer + offset-1);
      offset += length_st_name;
        memcpy( &(this->name[i]), &(this->st_name), sizeof(char*));
      }
      uint32_t can_id_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      can_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      can_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      can_id_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->can_id_length);
      if(can_id_lengthT > can_id_length)
        this->can_id = (int32_t*)realloc(this->can_id, can_id_lengthT * sizeof(int32_t));
      can_id_length = can_id_lengthT;
      for( uint32_t i = 0; i < can_id_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_can_id;
      u_st_can_id.base = 0;
      u_st_can_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_can_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_can_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_can_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_can_id = u_st_can_id.real;
      offset += sizeof(this->st_can_id);
        memcpy( &(this->can_id[i]), &(this->st_can_id), sizeof(int32_t));
      }
      uint32_t motor_status_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      motor_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      motor_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      motor_status_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->motor_status_length);
      if(motor_status_lengthT > motor_status_length)
        this->motor_status = (robotnik_msgs::MotorStatus*)realloc(this->motor_status, motor_status_lengthT * sizeof(robotnik_msgs::MotorStatus));
      motor_status_length = motor_status_lengthT;
      for( uint32_t i = 0; i < motor_status_length; i++){
      offset += this->st_motor_status.deserialize(inbuffer + offset);
        memcpy( &(this->motor_status[i]), &(this->st_motor_status), sizeof(robotnik_msgs::MotorStatus));
      }
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/RobotnikMotorsStatus"; };
    const char * getMD5(){ return "40f5305ac2c33d213d54d21bf9ba7fc9"; };

  };

}
#endif