#ifndef SHAPE_H
#define SHAPE_H

#include "general.h"

typedef struct
{
    Vec3D*      vertexes;
    uint16_t    numEdges;
    uint16_t    numVertexes;
    Vec3D       curRotation;    
    uint8_t**     edges;
}Shape;

void  shape_printVertexes( Shape* S );
void  shape_translate( Shape* S, Vec3D tVec );
void  shape_scale( Shape* S, Vec3D sVec );
void  shape_rotateX( Shape* S, double degrees );
void  shape_rotateY( Shape* S, double degrees );
void  shape_rotateZ( Shape* S, double degrees );
void  shape_setRotation(Shape* S, Vec3D Rvec_deg);

#endif