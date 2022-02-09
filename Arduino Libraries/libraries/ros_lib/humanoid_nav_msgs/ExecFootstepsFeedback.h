#ifndef _ROS_humanoid_nav_msgs_ExecFootstepsFeedback_h
#define _ROS_humanoid_nav_msgs_ExecFootstepsFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "humanoid_nav_msgs/StepTarget.h"

namespace humanoid_nav_msgs
{

  class ExecFootstepsFeedback : public ros::Msg
  {
    public:
      uint32_t executed_footsteps_length;
      typedef humanoid_nav_msgs::StepTarget _executed_footsteps_type;
      _executed_footsteps_type st_executed_footsteps;
      _executed_footsteps_type * executed_footsteps;

    ExecFootstepsFeedback():
      executed_footsteps_length(0), executed_footsteps(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->executed_footsteps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->executed_footsteps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->executed_footsteps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->executed_footsteps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->executed_footsteps_length);
      for( uint32_t i = 0; i < executed_footsteps_length; i++){
      offset += this->executed_footsteps[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t executed_footsteps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      executed_footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      executed_footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      executed_footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->executed_footsteps_length);
      if(executed_footsteps_lengthT > executed_footsteps_length)
        this->executed_footsteps = (humanoid_nav_msgs::StepTarget*)realloc(this->executed_footsteps, executed_footsteps_lengthT * sizeof(humanoid_nav_msgs::StepTarget));
      executed_footsteps_length = executed_footsteps_lengthT;
      for( uint32_t i = 0; i < executed_footsteps_length; i++){
      offset += this->st_executed_footsteps.deserialize(inbuffer + offset);
        memcpy( &(this->executed_footsteps[i]), &(this->st_executed_footsteps), sizeof(humanoid_nav_msgs::StepTarget));
      }
     return offset;
    }

    const char * getType(){ return "humanoid_nav_msgs/ExecFootstepsFeedback"; };
    const char * getMD5(){ return "5dfde2cb244d6c76567d3c52c40a988c"; };

  };

}
#endif