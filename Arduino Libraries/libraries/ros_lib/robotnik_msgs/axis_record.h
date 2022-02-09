#ifndef _ROS_SERVICE_axis_record_h
#define _ROS_SERVICE_axis_record_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char AXIS_RECORD[] = "robotnik_msgs/axis_record";

  class axis_recordRequest : public ros::Msg
  {
    public:
      typedef int8_t _action_type;
      _action_type action;
      typedef const char* _directory_type;
      _directory_type directory;
      typedef const char* _profile_type;
      _profile_type profile;
      typedef const char* _id_type;
      _id_type id;

    axis_recordRequest():
      action(0),
      directory(""),
      profile(""),
      id("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.real = this->action;
      *(outbuffer + offset + 0) = (u_action.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->action);
      uint32_t length_directory = strlen(this->directory);
      varToArr(outbuffer + offset, length_directory);
      offset += 4;
      memcpy(outbuffer + offset, this->directory, length_directory);
      offset += length_directory;
      uint32_t length_profile = strlen(this->profile);
      varToArr(outbuffer + offset, length_profile);
      offset += 4;
      memcpy(outbuffer + offset, this->profile, length_profile);
      offset += length_profile;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_action;
      u_action.base = 0;
      u_action.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->action = u_action.real;
      offset += sizeof(this->action);
      uint32_t length_directory;
      arrToVar(length_directory, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_directory; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_directory-1]=0;
      this->directory = (char *)(inbuffer + offset-1);
      offset += length_directory;
      uint32_t length_profile;
      arrToVar(length_profile, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_profile; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_profile-1]=0;
      this->profile = (char *)(inbuffer + offset-1);
      offset += length_profile;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
     return offset;
    }

    const char * getType(){ return AXIS_RECORD; };
    const char * getMD5(){ return "39a90fb80eeb30fd1922ed05ed1384be"; };

  };

  class axis_recordResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    axis_recordResponse():
      ret(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ret;
      u_ret.real = this->ret;
      *(outbuffer + offset + 0) = (u_ret.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ret);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ret;
      u_ret.base = 0;
      u_ret.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ret = u_ret.real;
      offset += sizeof(this->ret);
     return offset;
    }

    const char * getType(){ return AXIS_RECORD; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class axis_record {
    public:
    typedef axis_recordRequest Request;
    typedef axis_recordResponse Response;
  };

}
#endif
