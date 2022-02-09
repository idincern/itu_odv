#ifndef _ROS_SERVICE_ClipFootstep_h
#define _ROS_SERVICE_ClipFootstep_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "humanoid_nav_msgs/StepTarget.h"

namespace humanoid_nav_msgs
{

static const char CLIPFOOTSTEP[] = "humanoid_nav_msgs/ClipFootstep";

  class ClipFootstepRequest : public ros::Msg
  {
    public:
      typedef humanoid_nav_msgs::StepTarget _step_type;
      _step_type step;

    ClipFootstepRequest():
      step()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->step.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->step.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CLIPFOOTSTEP; };
    const char * getMD5(){ return "f22cfce442b381849d82602383b052c7"; };

  };

  class ClipFootstepResponse : public ros::Msg
  {
    public:
      typedef humanoid_nav_msgs::StepTarget _step_type;
      _step_type step;

    ClipFootstepResponse():
      step()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->step.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->step.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return CLIPFOOTSTEP; };
    const char * getMD5(){ return "f22cfce442b381849d82602383b052c7"; };

  };

  class ClipFootstep {
    public:
    typedef ClipFootstepRequest Request;
    typedef ClipFootstepResponse Response;
  };

}
#endif
