#ifndef _ROS_humanoid_nav_msgs_ExecFootstepsActionResult_h
#define _ROS_humanoid_nav_msgs_ExecFootstepsActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "humanoid_nav_msgs/ExecFootstepsResult.h"

namespace humanoid_nav_msgs
{

  class ExecFootstepsActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef humanoid_nav_msgs::ExecFootstepsResult _result_type;
      _result_type result;

    ExecFootstepsActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "humanoid_nav_msgs/ExecFootstepsActionResult"; };
    const char * getMD5(){ return "66fa71246c6848e28e972f9031bbbddc"; };

  };

}
#endif