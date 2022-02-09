#ifndef _ROS_fiducial_msgs_FiducialTransform_h
#define _ROS_fiducial_msgs_FiducialTransform_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Transform.h"

namespace fiducial_msgs
{

  class FiducialTransform : public ros::Msg
  {
    public:
      typedef int32_t _fiducial_id_type;
      _fiducial_id_type fiducial_id;
      typedef geometry_msgs::Transform _transform_type;
      _transform_type transform;
      typedef double _image_error_type;
      _image_error_type image_error;
      typedef double _object_error_type;
      _object_error_type object_error;
      typedef double _fiducial_area_type;
      _fiducial_area_type fiducial_area;

    FiducialTransform():
      fiducial_id(0),
      transform(),
      image_error(0),
      object_error(0),
      fiducial_area(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.real = this->fiducial_id;
      *(outbuffer + offset + 0) = (u_fiducial_id.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fiducial_id.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fiducial_id.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fiducial_id.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->fiducial_id);
      offset += this->transform.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_image_error;
      u_image_error.real = this->image_error;
      *(outbuffer + offset + 0) = (u_image_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_image_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_image_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_image_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_image_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_image_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_image_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_image_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->image_error);
      union {
        double real;
        uint64_t base;
      } u_object_error;
      u_object_error.real = this->object_error;
      *(outbuffer + offset + 0) = (u_object_error.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_object_error.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_object_error.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_object_error.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_object_error.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_object_error.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_object_error.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_object_error.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->object_error);
      union {
        double real;
        uint64_t base;
      } u_fiducial_area;
      u_fiducial_area.real = this->fiducial_area;
      *(outbuffer + offset + 0) = (u_fiducial_area.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_fiducial_area.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_fiducial_area.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_fiducial_area.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_fiducial_area.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_fiducial_area.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_fiducial_area.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_fiducial_area.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->fiducial_area);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_fiducial_id;
      u_fiducial_id.base = 0;
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fiducial_id.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->fiducial_id = u_fiducial_id.real;
      offset += sizeof(this->fiducial_id);
      offset += this->transform.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_image_error;
      u_image_error.base = 0;
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_image_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->image_error = u_image_error.real;
      offset += sizeof(this->image_error);
      union {
        double real;
        uint64_t base;
      } u_object_error;
      u_object_error.base = 0;
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_object_error.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->object_error = u_object_error.real;
      offset += sizeof(this->object_error);
      union {
        double real;
        uint64_t base;
      } u_fiducial_area;
      u_fiducial_area.base = 0;
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_fiducial_area.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->fiducial_area = u_fiducial_area.real;
      offset += sizeof(this->fiducial_area);
     return offset;
    }

    const char * getType(){ return "fiducial_msgs/FiducialTransform"; };
    const char * getMD5(){ return "9f77f4c92fda876d2249ffbc19859044"; };

  };

}
#endif