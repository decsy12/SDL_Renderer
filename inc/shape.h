#ifndef SHAPE_H
#define SHAPE_H


typedef struct
{
    Vec3D*      vertexes;
    uint16_t    numEdges;
    uint16_t    numVertexes;
    Vec3D       curRotation;    
}Shape;

void    shape_printVertexes( Shape* S );
Shape*  shape_translate( Shape* S, Vec3D tVec );
Shape*  shape_rotateX( Shape* S, int8_t degrees );
Shape*  shape_rotateY( Shape* S, int8_t degrees );
Shape*  shape_rotateZ( Shape* S, int8_t degrees );
Shape*  shape_setRotation(Shape* S, Vec3D Rvec_deg);

#endif