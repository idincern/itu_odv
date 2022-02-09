#ifndef _ROS_robotnik_msgs_MotorsStatusDifferential_h
#define _ROS_robotnik_msgs_MotorsStatusDifferential_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/MotorStatus.h"

namespace robotnik_msgs
{

  class MotorsStatusDifferential : public ros::Msg
  {
    public:
      typedef robotnik_msgs::MotorStatus _lwStatus_type;
      _lwStatus_type lwStatus;
      typedef robotnik_msgs::MotorStatus _rwStatus_type;
      _rwStatus_type rwStatus;

    MotorsStatusDifferential():
      lwStatus(),
      rwStatus()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->lwStatus.serialize(outbuffer + offset);
      offset += this->rwStatus.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->lwStatus.deserialize(inbuffer + offset);
      offset += this->rwStatus.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/MotorsStatusDifferential"; };
    const char * getMD5(){ return "f3eae6344ebc22baab4e7f49de91ea41"; };

  };

}
#endif