#ifndef _ROS_SERVICE_home_h
#define _ROS_SERVICE_home_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

static const char HOME[] = "robotnik_msgs/home";

  class homeRequest : public ros::Msg
  {
    public:
      typedef bool _request_type;
      _request_type request;

    homeRequest():
      request(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_request;
      u_request.real = this->request;
      *(outbuffer + offset + 0) = (u_request.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->request);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_request;
      u_request.base = 0;
      u_request.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->request = u_request.real;
      offset += sizeof(this->request);
     return offset;
    }

    const char * getType(){ return HOME; };
    const char * getMD5(){ return "6f7e5ad6ab0ddf42c5727a195315a470"; };

  };

  class homeResponse : public ros::Msg
  {
    public:
      typedef bool _ret_type;
      _ret_type ret;

    homeResponse():
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

    const char * getType(){ return HOME; };
    const char * getMD5(){ return "e2cc9e9d8c464550830df49c160979ad"; };

  };

  class home {
    public:
    typedef homeRequest Request;
    typedef homeResponse Response;
  };

}
#endif
