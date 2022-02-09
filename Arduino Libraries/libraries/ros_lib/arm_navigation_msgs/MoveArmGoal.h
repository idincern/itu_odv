#ifndef _ROS_arm_navigation_msgs_MoveArmGoal_h
#define _ROS_arm_navigation_msgs_MoveArmGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "arm_navigation_msgs/PlanningScene.h"
#include "arm_navigation_msgs/MotionPlanRequest.h"
#include "arm_navigation_msgs/OrderedCollisionOperations.h"

namespace arm_navigation_msgs
{

  class MoveArmGoal : public ros::Msg
  {
    public:
      typedef const char* _planner_service_name_type;
      _planner_service_name_type planner_service_name;
      typedef arm_navigation_msgs::PlanningScene _planning_scene_diff_type;
      _planning_scene_diff_type planning_scene_diff;
      typedef arm_navigation_msgs::MotionPlanRequest _motion_plan_request_type;
      _motion_plan_request_type motion_plan_request;
      typedef arm_navigation_msgs::OrderedCollisionOperations _operations_type;
      _operations_type operations;
      typedef bool _accept_partial_plans_type;
      _accept_partial_plans_type accept_partial_plans;
      typedef bool _accept_invalid_goals_type;
      _accept_invalid_goals_type accept_invalid_goals;
      typedef bool _disable_ik_type;
      _disable_ik_type disable_ik;
      typedef bool _disable_collision_monitoring_type;
      _disable_collision_monitoring_type disable_collision_monitoring;

    MoveArmGoal():
      planner_service_name(""),
      planning_scene_diff(),
      motion_plan_request(),
      operations(),
      accept_partial_plans(0),
      accept_invalid_goals(0),
      disable_ik(0),
      disable_collision_monitoring(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_planner_service_name = strlen(this->planner_service_name);
      varToArr(outbuffer + offset, length_planner_service_name);
      offset += 4;
      memcpy(outbuffer + offset, this->planner_service_name, length_planner_service_name);
      offset += length_planner_service_name;
      offset += this->planning_scene_diff.serialize(outbuffer + offset);
      offset += this->motion_plan_request.serialize(outbuffer + offset);
      offset += this->operations.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_accept_partial_plans;
      u_accept_partial_plans.real = this->accept_partial_plans;
      *(outbuffer + offset + 0) = (u_accept_partial_plans.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accept_partial_plans);
      union {
        bool real;
        uint8_t base;
      } u_accept_invalid_goals;
      u_accept_invalid_goals.real = this->accept_invalid_goals;
      *(outbuffer + offset + 0) = (u_accept_invalid_goals.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->accept_invalid_goals);
      union {
        bool real;
        uint8_t base;
      } u_disable_ik;
      u_disable_ik.real = this->disable_ik;
      *(outbuffer + offset + 0) = (u_disable_ik.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_ik);
      union {
        bool real;
        uint8_t base;
      } u_disable_collision_monitoring;
      u_disable_collision_monitoring.real = this->disable_collision_monitoring;
      *(outbuffer + offset + 0) = (u_disable_collision_monitoring.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->disable_collision_monitoring);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_planner_service_name;
      arrToVar(length_planner_service_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_planner_service_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_planner_service_name-1]=0;
      this->planner_service_name = (char *)(inbuffer + offset-1);
      offset += length_planner_service_name;
      offset += this->planning_scene_diff.deserialize(inbuffer + offset);
      offset += this->motion_plan_request.deserialize(inbuffer + offset);
      offset += this->operations.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_accept_partial_plans;
      u_accept_partial_plans.base = 0;
      u_accept_partial_plans.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->accept_partial_plans = u_accept_partial_plans.real;
      offset += sizeof(this->accept_partial_plans);
      union {
        bool real;
        uint8_t base;
      } u_accept_invalid_goals;
      u_accept_invalid_goals.base = 0;
      u_accept_invalid_goals.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->accept_invalid_goals = u_accept_invalid_goals.real;
      offset += sizeof(this->accept_invalid_goals);
      union {
        bool real;
        uint8_t base;
      } u_disable_ik;
      u_disable_ik.base = 0;
      u_disable_ik.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_ik = u_disable_ik.real;
      offset += sizeof(this->disable_ik);
      union {
        bool real;
        uint8_t base;
      } u_disable_collision_monitoring;
      u_disable_collision_monitoring.base = 0;
      u_disable_collision_monitoring.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->disable_collision_monitoring = u_disable_collision_monitoring.real;
      offset += sizeof(this->disable_collision_monitoring);
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/MoveArmGoal"; };
    const char * getMD5(){ return "229373059043ad35d3ceeb2161f005d6"; };

  };

}
#endif