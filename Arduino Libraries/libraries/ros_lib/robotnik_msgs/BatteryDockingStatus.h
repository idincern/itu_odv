#ifndef _ROS_robotnik_msgs_BatteryDockingStatus_h
#define _ROS_robotnik_msgs_BatteryDockingStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class BatteryDockingStatus : public ros::Msg
  {
    public:
      typedef const char* _operation_mode_type;
      _operation_mode_type operation_mode;
      typedef float _battery_current_type;
      _battery_current_type battery_current;
      typedef bool _contact_relay_status_type;
      _contact_relay_status_type contact_relay_status;
      typedef bool _charger_relay_status_type;
      _charger_relay_status_type charger_relay_status;
      enum { MODE_DISABLED = disabled };
      enum { MODE_AUTO_HW = automatic_hw };
      enum { MODE_AUTO_SW = automatic_sw };
      enum { MODE_MANUAL_SW = manual_sw };

    BatteryDockingStatus():
      operation_mode(""),
      battery_current(0),
      contact_relay_status(0),
      charger_relay_status(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_operation_mode = strlen(this->operation_mode);
      varToArr(outbuffer + offset, length_operation_mode);
      offset += 4;
      memcpy(outbuffer + offset, this->operation_mode, length_operation_mode);
      offset += length_operation_mode;
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.real = this->battery_current;
      *(outbuffer + offset + 0) = (u_battery_current.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_battery_current.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_battery_current.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_battery_current.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->battery_current);
      union {
        bool real;
        uint8_t base;
      } u_contact_relay_status;
      u_contact_relay_status.real = this->contact_relay_status;
      *(outbuffer + offset + 0) = (u_contact_relay_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->contact_relay_status);
      union {
        bool real;
        uint8_t base;
      } u_charger_relay_status;
      u_charger_relay_status.real = this->charger_relay_status;
      *(outbuffer + offset + 0) = (u_charger_relay_status.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->charger_relay_status);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_operation_mode;
      arrToVar(length_operation_mode, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_operation_mode; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_operation_mode-1]=0;
      this->operation_mode = (char *)(inbuffer + offset-1);
      offset += length_operation_mode;
      union {
        float real;
        uint32_t base;
      } u_battery_current;
      u_battery_current.base = 0;
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_battery_current.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->battery_current = u_battery_current.real;
      offset += sizeof(this->battery_current);
      union {
        bool real;
        uint8_t base;
      } u_contact_relay_status;
      u_contact_relay_status.base = 0;
      u_contact_relay_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->contact_relay_status = u_contact_relay_status.real;
      offset += sizeof(this->contact_relay_status);
      union {
        bool real;
        uint8_t base;
      } u_charger_relay_status;
      u_charger_relay_status.base = 0;
      u_charger_relay_status.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->charger_relay_status = u_charger_relay_status.real;
      offset += sizeof(this->charger_relay_status);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/BatteryDockingStatus"; };
    const char * getMD5(){ return "16af3d7230e4454981667998006e8e68"; };

  };

}
#endif