#ifndef _ROS_robotnik_msgs_Data_h
#define _ROS_robotnik_msgs_Data_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace robotnik_msgs
{

  class Data : public ros::Msg
  {
    public:
      typedef const char* _interface_type;
      _interface_type interface;
      typedef float _bytes_sent_type;
      _bytes_sent_type bytes_sent;
      typedef float _bytes_received_type;
      _bytes_received_type bytes_received;
      typedef const char* _units_sent_type;
      _units_sent_type units_sent;
      typedef const char* _units_received_type;
      _units_received_type units_received;
      typedef int32_t _packages_sent_type;
      _packages_sent_type packages_sent;
      typedef int32_t _packages_received_type;
      _packages_received_type packages_received;

    Data():
      interface(""),
      bytes_sent(0),
      bytes_received(0),
      units_sent(""),
      units_received(""),
      packages_sent(0),
      packages_received(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_interface = strlen(this->interface);
      varToArr(outbuffer + offset, length_interface);
      offset += 4;
      memcpy(outbuffer + offset, this->interface, length_interface);
      offset += length_interface;
      union {
        float real;
        uint32_t base;
      } u_bytes_sent;
      u_bytes_sent.real = this->bytes_sent;
      *(outbuffer + offset + 0) = (u_bytes_sent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bytes_sent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bytes_sent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bytes_sent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bytes_sent);
      union {
        float real;
        uint32_t base;
      } u_bytes_received;
      u_bytes_received.real = this->bytes_received;
      *(outbuffer + offset + 0) = (u_bytes_received.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bytes_received.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bytes_received.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bytes_received.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bytes_received);
      uint32_t length_units_sent = strlen(this->units_sent);
      varToArr(outbuffer + offset, length_units_sent);
      offset += 4;
      memcpy(outbuffer + offset, this->units_sent, length_units_sent);
      offset += length_units_sent;
      uint32_t length_units_received = strlen(this->units_received);
      varToArr(outbuffer + offset, length_units_received);
      offset += 4;
      memcpy(outbuffer + offset, this->units_received, length_units_received);
      offset += length_units_received;
      union {
        int32_t real;
        uint32_t base;
      } u_packages_sent;
      u_packages_sent.real = this->packages_sent;
      *(outbuffer + offset + 0) = (u_packages_sent.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packages_sent.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packages_sent.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packages_sent.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->packages_sent);
      union {
        int32_t real;
        uint32_t base;
      } u_packages_received;
      u_packages_received.real = this->packages_received;
      *(outbuffer + offset + 0) = (u_packages_received.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_packages_received.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_packages_received.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_packages_received.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->packages_received);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_interface;
      arrToVar(length_interface, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_interface; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_interface-1]=0;
      this->interface = (char *)(inbuffer + offset-1);
      offset += length_interface;
      union {
        float real;
        uint32_t base;
      } u_bytes_sent;
      u_bytes_sent.base = 0;
      u_bytes_sent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bytes_sent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bytes_sent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bytes_sent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bytes_sent = u_bytes_sent.real;
      offset += sizeof(this->bytes_sent);
      union {
        float real;
        uint32_t base;
      } u_bytes_received;
      u_bytes_received.base = 0;
      u_bytes_received.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bytes_received.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bytes_received.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bytes_received.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bytes_received = u_bytes_received.real;
      offset += sizeof(this->bytes_received);
      uint32_t length_units_sent;
      arrToVar(length_units_sent, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_units_sent; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_units_sent-1]=0;
      this->units_sent = (char *)(inbuffer + offset-1);
      offset += length_units_sent;
      uint32_t length_units_received;
      arrToVar(length_units_received, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_units_received; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_units_received-1]=0;
      this->units_received = (char *)(inbuffer + offset-1);
      offset += length_units_received;
      union {
        int32_t real;
        uint32_t base;
      } u_packages_sent;
      u_packages_sent.base = 0;
      u_packages_sent.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packages_sent.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packages_sent.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packages_sent.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->packages_sent = u_packages_sent.real;
      offset += sizeof(this->packages_sent);
      union {
        int32_t real;
        uint32_t base;
      } u_packages_received;
      u_packages_received.base = 0;
      u_packages_received.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_packages_received.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_packages_received.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_packages_received.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->packages_received = u_packages_received.real;
      offset += sizeof(this->packages_received);
     return offset;
    }

    const char * getType(){ return "robotnik_msgs/Data"; };
    const char * getMD5(){ return "beae478f52d7795f673d8edc9e4295a2"; };

  };

}
#endif