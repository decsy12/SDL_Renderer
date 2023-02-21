#ifndef SHAPE_H
#define SHAPE_H

#include "general.h"
#include "SDL2/SDL.h"

#define  VEC3D_SIZE         24U

#define  UNIT_CUBE_WIDTH    1U
#define  UNIT_CUBE_HEIGHT   1U
#define  UNIT_CUBE_DEPTH    1U

typedef struct
{
    Vec3D*      vertexes;
    uint16_t    numEdges;
    uint16_t    numVertexes;
    Vec3D       curRotation;    
    uint8_t**   edges;    
    double      width;
    double      height;
    double      depth;
}Shape;

typedef struct 
{
    uint16_t    vStart;
    uint16_t    vEnd;
}Edge;

void    shape_printVertexes( Shape* S, const char* shapeName );
void    shape_translate( Shape* S, Vec3D tVec );
void    shape_scale( Shape* S, Vec3D sVec );
void    shape_setSize(Shape* S, Vec3D sVec);
void    shape_rotateX( Shape* S, double degrees );
void    shape_rotateY( Shape* S, double degrees );
void    shape_rotateZ( Shape* S, double degrees );
void    shape_setRotation(Shape* S, Vec3D Rvec_deg);
void    shape_draw( SDL_Renderer* renderer, Shape* S, uint8_t R, uint8_t G, uint8_t B);
void    shape_clear( SDL_Renderer* renderer, Shape* S );
void    shape_moveTo( Shape* S, Vec3D pV );
Vec3D*  shape_copyVertexes( Vec3D source[], uint8_t size );
Shape*  shape_cube( double w, double h, double d, double x, double y, double z );

// Shape*  shape_cube( double w, double h, double d, double x, double y, double z);

#endif