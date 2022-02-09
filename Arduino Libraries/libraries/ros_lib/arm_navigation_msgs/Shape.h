#ifndef _ROS_arm_navigation_msgs_Shape_h
#define _ROS_arm_navigation_msgs_Shape_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"

namespace arm_navigation_msgs
{

  class Shape : public ros::Msg
  {
    public:
      typedef int8_t _type_type;
      _type_type type;
      uint32_t dimensions_length;
      typedef double _dimensions_type;
      _dimensions_type st_dimensions;
      _dimensions_type * dimensions;
      uint32_t triangles_length;
      typedef int32_t _triangles_type;
      _triangles_type st_triangles;
      _triangles_type * triangles;
      uint32_t vertices_length;
      typedef geometry_msgs::Point _vertices_type;
      _vertices_type st_vertices;
      _vertices_type * vertices;
      enum { SPHERE = 0 };
      enum { BOX = 1 };
      enum { CYLINDER = 2 };
      enum { MESH = 3 };

    Shape():
      type(0),
      dimensions_length(0), dimensions(NULL),
      triangles_length(0), triangles(NULL),
      vertices_length(0), vertices(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.real = this->type;
      *(outbuffer + offset + 0) = (u_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->type);
      *(outbuffer + offset + 0) = (this->dimensions_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dimensions_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dimensions_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dimensions_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dimensions_length);
      for( uint32_t i = 0; i < dimensions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_dimensionsi;
      u_dimensionsi.real = this->dimensions[i];
      *(outbuffer + offset + 0) = (u_dimensionsi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_dimensionsi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_dimensionsi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_dimensionsi.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_dimensionsi.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_dimensionsi.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_dimensionsi.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_dimensionsi.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->dimensions[i]);
      }
      *(outbuffer + offset + 0) = (this->triangles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->triangles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->triangles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->triangles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->triangles_length);
      for( uint32_t i = 0; i < triangles_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_trianglesi;
      u_trianglesi.real = this->triangles[i];
      *(outbuffer + offset + 0) = (u_trianglesi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_trianglesi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_trianglesi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_trianglesi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->triangles[i]);
      }
      *(outbuffer + offset + 0) = (this->vertices_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vertices_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vertices_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vertices_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vertices_length);
      for( uint32_t i = 0; i < vertices_length; i++){
      offset += this->vertices[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_type;
      u_type.base = 0;
      u_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->type = u_type.real;
      offset += sizeof(this->type);
      uint32_t dimensions_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dimensions_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dimensions_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dimensions_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dimensions_length);
      if(dimensions_lengthT > dimensions_length)
        this->dimensions = (double*)realloc(this->dimensions, dimensions_lengthT * sizeof(double));
      dimensions_length = dimensions_lengthT;
      for( uint32_t i = 0; i < dimensions_length; i++){
      union {
        double real;
        uint64_t base;
      } u_st_dimensions;
      u_st_dimensions.base = 0;
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_st_dimensions.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->st_dimensions = u_st_dimensions.real;
      offset += sizeof(this->st_dimensions);
        memcpy( &(this->dimensions[i]), &(this->st_dimensions), sizeof(double));
      }
      uint32_t triangles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      triangles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->triangles_length);
      if(triangles_lengthT > triangles_length)
        this->triangles = (int32_t*)realloc(this->triangles, triangles_lengthT * sizeof(int32_t));
      triangles_length = triangles_lengthT;
      for( uint32_t i = 0; i < triangles_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_triangles;
      u_st_triangles.base = 0;
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_triangles.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_triangles = u_st_triangles.real;
      offset += sizeof(this->st_triangles);
        memcpy( &(this->triangles[i]), &(this->st_triangles), sizeof(int32_t));
      }
      uint32_t vertices_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      vertices_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->vertices_length);
      if(vertices_lengthT > vertices_length)
        this->vertices = (geometry_msgs::Point*)realloc(this->vertices, vertices_lengthT * sizeof(geometry_msgs::Point));
      vertices_length = vertices_lengthT;
      for( uint32_t i = 0; i < vertices_length; i++){
      offset += this->st_vertices.deserialize(inbuffer + offset);
        memcpy( &(this->vertices[i]), &(this->st_vertices), sizeof(geometry_msgs::Point));
      }
     return offset;
    }

    const char * getType(){ return "arm_navigation_msgs/Shape"; };
    const char * getMD5(){ return "59935940044147de75e7523b5d37c4d7"; };

  };

}
#endif