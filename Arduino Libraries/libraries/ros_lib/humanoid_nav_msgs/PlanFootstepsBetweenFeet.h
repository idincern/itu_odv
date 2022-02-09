#ifndef _ROS_SERVICE_PlanFootstepsBetweenFeet_h
#define _ROS_SERVICE_PlanFootstepsBetweenFeet_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "humanoid_nav_msgs/StepTarget.h"

namespace humanoid_nav_msgs
{

static const char PLANFOOTSTEPSBETWEENFEET[] = "humanoid_nav_msgs/PlanFootstepsBetweenFeet";

  class PlanFootstepsBetweenFeetRequest : public ros::Msg
  {
    public:
      typedef humanoid_nav_msgs::StepTarget _start_left_type;
      _start_left_type start_left;
      typedef humanoid_nav_msgs::StepTarget _start_right_type;
      _start_right_type start_right;
      typedef humanoid_nav_msgs::StepTarget _goal_left_type;
      _goal_left_type goal_left;
      typedef humanoid_nav_msgs::StepTarget _goal_right_type;
      _goal_right_type goal_right;

    PlanFootstepsBetweenFeetRequest():
      start_left(),
      start_right(),
      goal_left(),
      goal_right()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->start_left.serialize(outbuffer + offset);
      offset += this->start_right.serialize(outbuffer + offset);
      offset += this->goal_left.serialize(outbuffer + offset);
      offset += this->goal_right.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->start_left.deserialize(inbuffer + offset);
      offset += this->start_right.deserialize(inbuffer + offset);
      offset += this->goal_left.deserialize(inbuffer + offset);
      offset += this->goal_right.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return PLANFOOTSTEPSBETWEENFEET; };
    const char * getMD5(){ return "a081711eb51a4a4283b2b9f345efe272"; };

  };

  class PlanFootstepsBetweenFeetResponse : public ros::Msg
  {
    public:
      typedef bool _result_type;
      _result_type result;
      uint32_t footsteps_length;
      typedef humanoid_nav_msgs::StepTarget _footsteps_type;
      _footsteps_type st_footsteps;
      _footsteps_type * footsteps;
      typedef double _costs_type;
      _costs_type costs;
      typedef double _final_eps_type;
      _final_eps_type final_eps;
      typedef double _planning_time_type;
      _planning_time_type planning_time;
      typedef int64_t _expanded_states_type;
      _expanded_states_type expanded_states;

    PlanFootstepsBetweenFeetResponse():
      result(0),
      footsteps_length(0), footsteps(NULL),
      costs(0),
      final_eps(0),
      planning_time(0),
      expanded_states(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.real = this->result;
      *(outbuffer + offset + 0) = (u_result.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->result);
      *(outbuffer + offset + 0) = (this->footsteps_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->footsteps_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->footsteps_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->footsteps_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->footsteps_length);
      for( uint32_t i = 0; i < footsteps_length; i++){
      offset += this->footsteps[i].serialize(outbuffer + offset);
      }
      union {
        double real;
        uint64_t base;
      } u_costs;
      u_costs.real = this->costs;
      *(outbuffer + offset + 0) = (u_costs.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_costs.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_costs.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_costs.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_costs.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_costs.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_costs.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_costs.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->costs);
      union {
        double real;
        uint64_t base;
      } u_final_eps;
      u_final_eps.real = this->final_eps;
      *(outbuffer + offset + 0) = (u_final_eps.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_final_eps.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_final_eps.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_final_eps.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_final_eps.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_final_eps.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_final_eps.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_final_eps.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->final_eps);
      union {
        double real;
        uint64_t base;
      } u_planning_time;
      u_planning_time.real = this->planning_time;
      *(outbuffer + offset + 0) = (u_planning_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_planning_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_planning_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_planning_time.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_planning_time.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_planning_time.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_planning_time.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_planning_time.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->planning_time);
      union {
        int64_t real;
        uint64_t base;
      } u_expanded_states;
      u_expanded_states.real = this->expanded_states;
      *(outbuffer + offset + 0) = (u_expanded_states.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_expanded_states.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_expanded_states.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_expanded_states.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_expanded_states.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_expanded_states.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_expanded_states.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_expanded_states.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->expanded_states);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_result;
      u_result.base = 0;
      u_result.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->result = u_result.real;
      offset += sizeof(this->result);
      uint32_t footsteps_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      footsteps_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->footsteps_length);
      if(footsteps_lengthT > footsteps_length)
        this->footsteps = (humanoid_nav_msgs::StepTarget*)realloc(this->footsteps, footsteps_lengthT * sizeof(humanoid_nav_msgs::StepTarget));
      footsteps_length = footsteps_lengthT;
      for( uint32_t i = 0; i < footsteps_length; i++){
      offset += this->st_footsteps.deserialize(inbuffer + offset);
        memcpy( &(this->footsteps[i]), &(this->st_footsteps), sizeof(humanoid_nav_msgs::StepTarget));
      }
      union {
        double real;
        uint64_t base;
      } u_costs;
      u_costs.base = 0;
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_costs.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->costs = u_costs.real;
      offset += sizeof(this->costs);
      union {
        double real;
        uint64_t base;
      } u_final_eps;
      u_final_eps.base = 0;
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_final_eps.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->final_eps = u_final_eps.real;
      offset += sizeof(this->final_eps);
      union {
        double real;
        uint64_t base;
      } u_planning_time;
      u_planning_time.base = 0;
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_planning_time.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->planning_time = u_planning_time.real;
      offset += sizeof(this->planning_time);
      union {
        int64_t real;
        uint64_t base;
      } u_expanded_states;
      u_expanded_states.base = 0;
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_expanded_states.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->expanded_states = u_expanded_states.real;
      offset += sizeof(this->expanded_states);
     return offset;
    }

    const char * getType(){ return PLANFOOTSTEPSBETWEENFEET; };
    const char * getMD5(){ return "1af07cd1d4ffe34a9a731e87aa13835c"; };

  };

  class PlanFootstepsBetweenFeet {
    public:
    typedef PlanFootstepsBetweenFeetRequest Request;
    typedef PlanFootstepsBetweenFeetResponse Response;
  };

}
#endif
