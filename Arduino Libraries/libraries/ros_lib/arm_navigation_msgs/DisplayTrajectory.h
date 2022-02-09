#ifndef _ROS_arm_navigation_msgs_DisplayTrajectory_h
#define _ROS_arm_navigation_msgs_DisplayTrajectory_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/RobotTrajectory.h"
#include "arm_navigation_msgs/RobotState.h"

namespace arm_navigation_msgs
{

  class DisplayTrajectory : public ros::Msg
  {
    public:
      typedef const char* _model_id_type;
      _model_id_type model_id;
      typedef arm_navigation_msgs::RobotTrajectory _trajectory_type;
      _trajectory_type trajectory;
      typedef arm_navigation_msgs::RobotState _robot_state_type;
      _robot_state_type robot_state;

    DisplayTrajectory():
      model_id(""),
      trajectory(),
      robot_state()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_model_id = strlen(this->model_id);
      varToArr(outbuffer + offset, length_model_id);
      offset += 4;
      memcpy(outbuffer + offset, this->model_id, length_model_id);
      offset += length_model_id;
      offset += this->trajectory.serialize(outbuffer + offset);
      offset += this->robot_state.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_model_id;
      arrToVar(length_model_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_model_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_model_id-1]=0;
      this->model_id = (char *)(inbuffer + offset-1);
      offset += length_model_id;
      offset += this->trajectory.deserialize(inbuffer + offset);
      offset += this->robot_state.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/DisplayTrajectory"; };
    const char * getMD5(){ return "44077c82eeaba8cc3b61edfd4b548dd7"; };

  };

}
#endif