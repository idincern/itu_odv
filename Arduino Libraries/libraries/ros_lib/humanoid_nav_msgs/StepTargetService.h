#ifndef _ROS_SERVICE_StepTargetService_h
#define _ROS_SERVICE_StepTargetService_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "humanoid_nav_msgs/StepTarget.h"

namespace humanoid_nav_msgs
{

static const char STEPTARGETSERVICE[] = "humanoid_nav_msgs/StepTargetService";

  class StepTargetServiceRequest : public ros::Msg
  {
    public:
      typedef humanoid_nav_msgs::StepTarget _step_type;
      _step_type step;

    StepTargetServiceRequest():
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

    const char * getType(){ return STEPTARGETSERVICE; };
    const char * getMD5(){ return "f22cfce442b381849d82602383b052c7"; };

  };

  class StepTargetServiceResponse : public ros::Msg
  {
    public:

    StepTargetServiceResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return STEPTARGETSERVICE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class StepTargetService {
    public:
    typedef StepTargetServiceRequest Request;
    typedef StepTargetServiceResponse Response;
  };

}
#endif
