#ifndef _ROS_arm_navigation_msgs_MoveArmResult_h
#define _ROS_arm_navigation_msgs_MoveArmResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/ArmNavigationErrorCodes.h"
#include "arm_navigation_msgs/ContactInformation.h"

namespace arm_navigation_msgs
{

  class MoveArmResult : public ros::Msg
  {
    public:
      typedef arm_navigation_msgs::ArmNavigationErrorCodes _error_code_type;
      _error_code_type error_code;
      uint32_t contacts_length;
      typedef arm_navigation_msgs::ContactInformation _contacts_type;
      _contacts_type st_contacts;
      _contacts_type * contacts;

    MoveArmResult():
      error_code(),
      contacts_length(0), contacts(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->error_code.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->contacts_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->contacts_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->contacts_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->contacts_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->contacts_length);
      for( uint32_t i = 0; i < contacts_length; i++){
      offset += this->contacts[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->error_code.deserialize(inbuffer + offset);
      uint32_t contacts_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      contacts_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->contacts_length);
      if(contacts_lengthT > contacts_length)
        this->contacts = (arm_navigation_msgs::ContactInformation*)realloc(this->contacts, contacts_lengthT * sizeof(arm_navigation_msgs::ContactInformation));
      contacts_length = contacts_lengthT;
      for( uint32_t i = 0; i < contacts_length; i++){
      offset += this->st_contacts.deserialize(inbuffer + offset);
        memcpy( &(this->contacts[i]), &(this->st_contacts), sizeof(arm_navigation_msgs::ContactInformation));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MoveArmResult"; };
    const char * getMD5(){ return "3229301226a0605e3ffc9dfdaeac662f"; };

  };

}
#endif