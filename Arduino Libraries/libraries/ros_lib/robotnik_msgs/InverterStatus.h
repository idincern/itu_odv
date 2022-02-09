#ifndef _ROS_robotnik_msgs_InverterStatus_h
#define _ROS_robotnik_msgs_InverterStatus_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace robotnik_msgs
{

  class InverterStatus : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _ac_voltage_type;
      _ac_voltage_type ac_voltage;
      typedef float _dc_voltage_type;
      _dc_voltage_type dc_voltage;
      typedef float _load_type;
      _load_type load;
      typedef float _percentage_type;
      _percentage_type percentage;
      typedef float _temperature_type;
      _temperature_type temperature;
      typedef bool _on_type;
      _on_type on;
      typedef const char* _serial_number_type;
      _serial_number_type serial_number;

    InverterStatus():
      header(),
      ac_voltage(0),
      dc_voltage(0),
      load(0),
      percentage(0),
      temperature(0),
      on(0),
      serial_number("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_ac_voltage;
      u_ac_voltage.real = this->ac_voltage;
      *(outbuffer + offset + 0) = (u_ac_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_ac_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_ac_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_ac_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ac_voltage);
      union {
        float real;
        uint32_t base;
      } u_dc_voltage;
      u_dc_voltage.real = this->dc_voltage;
      *(outbuffer + offset + 0) = (u_dc_voltage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dc_voltage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dc_voltage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dc_voltage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dc_voltage);
      union {
        float real;
        uint32_t base;
      } u_load;
      u_load.real = this->load;
      *(outbuffer + offset + 0) = (u_load.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_load.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_load.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_load.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->load);
      union {
        float real;
        uint32_t base;
      } u_percentage;
      u_percentage.real = this->percentage;
      *(outbuffer + offset + 0) = (u_percentage.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_percentage.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_percentage.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_percentage.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->percentage);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.real = this->temperature;
      *(outbuffer + offset + 0) = (u_temperature.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temperature.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temperature.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temperature.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temperature);
      union {
        bool real;
        uint8_t base;
      } u_on;
      u_on.real = this->on;
      *(outbuffer + offset + 0) = (u_on.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->on);
      uint32_t length_serial_number = strlen(this->serial_number);
      varToArr(outbuffer + offset, length_serial_number);
      offset += 4;
      memcpy(outbuffer + offset, this->serial_number, length_serial_number);
      offset += length_serial_number;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_ac_voltage;
      u_ac_voltage.base = 0;
      u_ac_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_ac_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_ac_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_ac_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->ac_voltage = u_ac_voltage.real;
      offset += sizeof(this->ac_voltage);
      union {
        float real;
        uint32_t base;
      } u_dc_voltage;
      u_dc_voltage.base = 0;
      u_dc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_dc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_dc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_dc_voltage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->dc_voltage = u_dc_voltage.real;
      offset += sizeof(this->dc_voltage);
      union {
        float real;
        uint32_t base;
      } u_load;
      u_load.base = 0;
      u_load.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_load.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_load.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_load.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->load = u_load.real;
      offset += sizeof(this->load);
      union {
        float real;
        uint32_t base;
      } u_percentage;
      u_percentage.base = 0;
      u_percentage.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_percentage.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_percentage.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_percentage.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->percentage = u_percentage.real;
      offset += sizeof(this->percentage);
      union {
        float real;
        uint32_t base;
      } u_temperature;
      u_temperature.base = 0;
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temperature.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temperature = u_temperature.real;
      offset += sizeof(this->temperature);
      union {
        bool real;
        uint8_t base;
      } u_on;
      u_on.base = 0;
      u_on.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->on = u_on.real;
      offset += sizeof(this->on);
      uint32_t length_serial_number;
      arrToVar(length_serial_number, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_serial_number; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_serial_number-1]=0;
      this->serial_number = (char *)(inbuffer + offset-1);
      offset += length_serial_number;
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/InverterStatus"; };
    const char * getMD5(){ return "d693ae8f6a65a0d35c771d1a15a9e199"; };

  };

}
#endif