#ifndef _ROS_vision_msgs_ObjectHypothesisWithPose_h
#define _ROS_vision_msgs_ObjectHypothesisWithPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/PoseWithCovariance.h"

namespace vision_msgs
{

  class ObjectHypothesisWithPose : public ros::Msg
  {
    public:
      typedef int64_t _id_type;
      _id_type id;
      typedef double _score_type;
      _score_type score;
      typedef geometry_msgs::PoseWithCovariance _pose_type;
      _pose_type pose;

    ObjectHypothesisWithPose():
      id(0),
      score(0),
      pose()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.real = this->id;
      *(outbuffer + offset + 0) = (u_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_id.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_id.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_id.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_id.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->id);
      union {
        double real;
        uint64_t base;
      } u_score;
      u_score.real = this->score;
      *(outbuffer + offset + 0) = (u_score.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_score.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_score.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_score.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_score.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_score.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_score.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_score.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->score);
      offset += this->pose.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_id;
      u_id.base = 0;
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_id.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->id = u_id.real;
      offset += sizeof(this->id);
      union {
        double real;
        uint64_t base;
      } u_score;
      u_score.base = 0;
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_score.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->score = u_score.real;
      offset += sizeof(this->score);
      offset += this->pose.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "vision_msgs/ObjectHypothesisWithPose"; };
    const char * getMD5(){ return "fa1ab3bc7146f53921fa142d631d02db"; };

  };

}
#endif