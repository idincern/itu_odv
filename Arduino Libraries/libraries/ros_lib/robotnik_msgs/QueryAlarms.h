#ifndef _ROS_SERVICE_QueryAlarms_h
#define _ROS_SERVICE_QueryAlarms_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "robotnik_msgs/QueryAlarm.h"

namespace robotnik_msgs
{

static const char QUERYALARMS[] = "robotnik_msgs/QueryAlarms";

  class QueryAlarmsRequest : public ros::Msg
  {
    public:
      typedef const char* _type_query_type;
      _type_query_type type_query;
      typedef const char* _start_date_type;
      _start_date_type start_date;
      typedef const char* _end_date_type;
      _end_date_type end_date;
      typedef int32_t _top_type;
      _top_type top;
      typedef const char* _filter_type_type;
      _filter_type_type filter_type;
      enum { TYPE_QUERY_ALL = ALL };
      enum { TYPE_QUERY_TOP = TOP };
      enum { TYPE_BETWEEN_DATE = BETWEEN_DATE };
      enum { TYPE_TOP_BETWEEN_DATE = TOP_BETWEEN_DATE };
      enum { FILTER_TYPE_NOTHING = NOTHING };
      enum { FILTER_TYPE_EVENT = EVENT };
      enum { FILTER_TYPE_ALARM = ALARM };
      enum { FILTER_TYPE_ERROR = ERROR };

    QueryAlarmsRequest():
      type_query(""),
      start_date(""),
      end_date(""),
      top(0),
      filter_type("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_type_query = strlen(this->type_query);
      varToArr(outbuffer + offset, length_type_query);
      offset += 4;
      memcpy(outbuffer + offset, this->type_query, length_type_query);
      offset += length_type_query;
      uint32_t length_start_date = strlen(this->start_date);
      varToArr(outbuffer + offset, length_start_date);
      offset += 4;
      memcpy(outbuffer + offset, this->start_date, length_start_date);
      offset += length_start_date;
      uint32_t length_end_date = strlen(this->end_date);
      varToArr(outbuffer + offset, length_end_date);
      offset += 4;
      memcpy(outbuffer + offset, this->end_date, length_end_date);
      offset += length_end_date;
      union {
        int32_t real;
        uint32_t base;
      } u_top;
      u_top.real = this->top;
      *(outbuffer + offset + 0) = (u_top.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_top.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_top.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_top.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->top);
      uint32_t length_filter_type = strlen(this->filter_type);
      varToArr(outbuffer + offset, length_filter_type);
      offset += 4;
      memcpy(outbuffer + offset, this->filter_type, length_filter_type);
      offset += length_filter_type;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_type_query;
      arrToVar(length_type_query, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_type_query; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_type_query-1]=0;
      this->type_query = (char *)(inbuffer + offset-1);
      offset += length_type_query;
      uint32_t length_start_date;
      arrToVar(length_start_date, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_start_date; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_start_date-1]=0;
      this->start_date = (char *)(inbuffer + offset-1);
      offset += length_start_date;
      uint32_t length_end_date;
      arrToVar(length_end_date, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_end_date; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_end_date-1]=0;
      this->end_date = (char *)(inbuffer + offset-1);
      offset += length_end_date;
      union {
        int32_t real;
        uint32_t base;
      } u_top;
      u_top.base = 0;
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_top.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->top = u_top.real;
      offset += sizeof(this->top);
      uint32_t length_filter_type;
      arrToVar(length_filter_type, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_filter_type; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_filter_type-1]=0;
      this->filter_type = (char *)(inbuffer + offset-1);
      offset += length_filter_type;
     return offset;
    }

    const char * getType(){ return QUERYALARMS; };
    const char * getMD5(){ return "f1be883ec4718e1184241817a2fe2b57"; };

  };

  class QueryAlarmsResponse : public ros::Msg
  {
    public:
      uint32_t alarms_length;
      typedef robotnik_msgs::QueryAlarm _alarms_type;
      _alarms_type st_alarms;
      _alarms_type * alarms;
      typedef bool _success_type;
      _success_type success;
      typedef const char* _msg_type;
      _msg_type msg;

    QueryAlarmsResponse():
      alarms_length(0), alarms(NULL),
      success(0),
      msg("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->alarms_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->alarms_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->alarms_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->alarms_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->alarms_length);
      for( uint32_t i = 0; i < alarms_length; i++){
      offset += this->alarms[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_msg = strlen(this->msg);
      varToArr(outbuffer + offset, length_msg);
      offset += 4;
      memcpy(outbuffer + offset, this->msg, length_msg);
      offset += length_msg;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t alarms_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      alarms_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      alarms_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      alarms_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->alarms_length);
      if(alarms_lengthT > alarms_length)
        this->alarms = (robotnik_msgs::QueryAlarm*)realloc(this->alarms, alarms_lengthT * sizeof(robotnik_msgs::QueryAlarm));
      alarms_length = alarms_lengthT;
      for( uint32_t i = 0; i < alarms_length; i++){
      offset += this->st_alarms.deserialize(inbuffer + offset);
        memcpy( &(this->alarms[i]), &(this->st_alarms), sizeof(robotnik_msgs::QueryAlarm));
      }
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_msg;
      arrToVar(length_msg, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_msg; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_msg-1]=0;
      this->msg = (char *)(inbuffer + offset-1);
      offset += length_msg;
     return offset;
    }

    const char * getType(){ return QUERYALARMS; };
    const char * getMD5(){ return "6d2c5e83064a46d4d198ba7049acbc1c"; };

  };

  class QueryAlarms {
    public:
    typedef QueryAlarmsRequest Request;
    typedef QueryAlarmsResponse Response;
  };

}
#endif
