#ifndef _ROS_robotnik_msgs_BatteryStatus_h
#define _ROS_robotnik_msgs_BatteryStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class BatteryStatus : public ros::Msg
  {
    public:
      typedef float _voltage_type;
      _voltage_type voltage;
      typedef float _level_type;
      _level_type level;
      typedef uint32_t _time_remaining_type;
      _time_remaining_type time_remaining;
      typedef uint32_t _time_charging_type;
      _time_charging_type time_charging;
      typedef bool _is_charging_type;
      _is_charging_type is_charging;

    BatteryStatus():
      voltage(0),
      level(0),
      time_remaining(0),
      time_charging(0),
      is_charging(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.real = this->voltage;
      *(outbuffer + offset + 0) = (u_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_level;
      u_level.real = this->level;
      *(outbuffer + offset + 0) = (u_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->level);
      *(outbuffer + offset + 0) = (this->time_remaining >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_remaining >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_remaining >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_remaining >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_remaining);
      *(outbuffer + offset + 0) = (this->time_charging >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->time_charging >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->time_charging >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->time_charging >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time_charging);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.real = this->is_charging;
      *(outbuffer + offset + 0) = (u_is_charging.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_charging);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        float real;
        uint32_t base;
      } u_voltage;
      u_voltage.base = 0;
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->voltage = u_voltage.real;
      offset += sizeof(this->voltage);
      union {
        float real;
        uint32_t base;
      } u_level;
      u_level.base = 0;
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->level = u_level.real;
      offset += sizeof(this->level);
      this->time_remaining =  ((uint32_t) (*(inbuffer + offset)));
      this->time_remaining |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_remaining |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_remaining |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_remaining);
      this->time_charging =  ((uint32_t) (*(inbuffer + offset)));
      this->time_charging |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->time_charging |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->time_charging |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->time_charging);
      union {
        bool real;
        uint8_t base;
      } u_is_charging;
      u_is_charging.base = 0;
      u_is_charging.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_charging = u_is_charging.real;
      offset += sizeof(this->is_charging);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/BatteryStatus"; };
    const char * getMD5(){ return "1afa51cf91fcde0accaed73a28682ea9"; };

  };

}
#endif