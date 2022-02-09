#ifndef _ROS_robotnik_msgs_BatteryDockingStatusStamped_h
#define _ROS_robotnik_msgs_BatteryDockingStatusStamped_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "robotnik_msgs/BatteryDockingStatus.h"

namespace robotnik_msgs
{

  class BatteryDockingStatusStamped : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef robotnik_msgs::BatteryDockingStatus _status_type;
      _status_type status;

    BatteryDockingStatusStamped():
      header(),
      status()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/BatteryDockingStatusStamped"; };
    const char * getMD5(){ return "164b1e2a58421ffba2cec75fdf68cecc"; };

  };

}
#endif