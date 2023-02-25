#ifndef MESH_H
#define MESH_H

#include "SDL2/SDL.h"

#define  VEC3D_SIZE         24U

#define  UNIT_CUBE_WIDTH    1U
#define  UNIT_CUBE_HEIGHT   1U
#define  UNIT_CUBE_DEPTH    1U

typedef struct 
{
    double x, y, z;    
}Vec3D;

typedef struct 
{
    Vec3D  point[3];
}Triangle;

typedef struct 
{
    Triangle*   tris;     
    uint16_t    numTriangles;     
    Vec3D       curRotation;            
    double      width;
    double      height;
    double      depth;      
}Mesh;

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
void    shape_rotateX( Shape* S, double degrees );
void    shape_rotateY( Shape* S, double degrees );
void    shape_rotateZ( Shape* S, double degrees );
void    shape_draw( SDL_Renderer* renderer, Shape* S, uint8_t R, uint8_t G, uint8_t B);
void    shape_clear( SDL_Renderer* renderer, Shape* S );
Vec3D*  shape_copyVertexes( Vec3D source[], uint8_t size );
Shape*  shape_cube( double w, double h, double d, double x, double y, double z );

void    mesh_moveTo( Mesh* mesh, Vec3D pV );
void    mesh_translate( Mesh* mesh, Vec3D tVec );
void    mesh_setSize(Mesh* mesh, Vec3D sVec);
void    mesh_scale( Mesh* mesh, Vec3D sVec );
void    mesh_setRotation(Mesh* mesh, Vec3D Rvec_deg);
void    mesh_draw( SDL_Renderer* renderer, Mesh* mesh, uint16_t R, uint16_t G, uint16_t B );
void    mesh_clear( SDL_Renderer* renderer, Mesh* mesh );
void    mesh_rotateX( Mesh* mesh, double degrees );
void    mesh_rotateY( Mesh* mesh, double degrees );
void    mesh_rotateZ( Mesh* mesh, double degrees );

#endif