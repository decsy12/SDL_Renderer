#include "SDL2/SDL.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "mesh.h"
#include "general.h"
#include "main.h"

Vec3D v1 = {.x = UNIT_CUBE_WIDTH/2,   .y= UNIT_CUBE_HEIGHT/2,  .z=UNIT_CUBE_DEPTH/2 };    
Vec3D v2 = {.x = UNIT_CUBE_WIDTH/2,   .y=-UNIT_CUBE_HEIGHT/2,  .z=UNIT_CUBE_DEPTH/2 };    
Vec3D v3 = {.x = -UNIT_CUBE_WIDTH/2,  .y=-UNIT_CUBE_HEIGHT/2,  .z=UNIT_CUBE_DEPTH/2 };    
Vec3D v4 = {.x = -UNIT_CUBE_WIDTH/2,  .y= UNIT_CUBE_HEIGHT/2,  .z=UNIT_CUBE_DEPTH/2 };    
Vec3D v5 = {.x = UNIT_CUBE_WIDTH/2,   .y= UNIT_CUBE_HEIGHT/2,  .z=-UNIT_CUBE_DEPTH/2};    
Vec3D v6 = {.x = UNIT_CUBE_WIDTH/2,   .y=-UNIT_CUBE_HEIGHT/2,  .z=-UNIT_CUBE_DEPTH/2};    
Vec3D v7 = {.x = -UNIT_CUBE_WIDTH/2,  .y=-UNIT_CUBE_HEIGHT/2,  .z=-UNIT_CUBE_DEPTH/2};    
Vec3D v8 = {.x = -UNIT_CUBE_WIDTH/2,  .y= UNIT_CUBE_HEIGHT/2,  .z=-UNIT_CUBE_DEPTH/2};    
Vec3D vertexes[] = {v1, v2, v3, v4, v5, v6, v7, v8};    
uint8_t e1[] =  {0 , 1};
uint8_t e2[] =  {1 , 2};
uint8_t e3[] =  {2 , 3};
uint8_t e4[] =  {3 , 0};
uint8_t e5[] =  {4 , 5};
uint8_t e6[] =  {5 , 6};
uint8_t e7[] =  {6 , 7};
uint8_t e8[] =  {7 , 4};
uint8_t e9[] =  {0 , 4};
uint8_t e10[] = {1 , 5};
uint8_t e11[] = {2 , 6};
uint8_t e12[] = {3 , 7};
uint8_t* edges[] = {e1, e2, e3, e4, e5, e6, e7, e8, e9, e10, e11, e12};
Vec3D rV = { .x = 0, .y = 0, .z = 0 };


// Shape* shape_cube( double w, double h, double d, double x, double y, double z )
// {
    
//     Shape* temp = (Shape*)malloc( sizeof( Shape ) );    

//     temp->vertexes = shape_copyVertexes(vertexes, 8);
//     temp->numEdges = 12;
//     temp->numVertexes = 8;
//     temp->curRotation = rV;
//     temp->edges = edges;   
//     temp->width = UNIT_CUBE_WIDTH;
//     temp->height = UNIT_CUBE_HEIGHT;
//     temp->depth = UNIT_CUBE_DEPTH;     

//     shape_scale(temp, {w,h,d});
//     shape_moveTo(temp,{x,y,z});    

//     return temp;
// }

// Mesh* mesh_cube( double w, double h, double d, double x, double y, double z )
// {
//      Vec3D p1 = {0, 0 , 50};
//     Vec3D p2 = {100, 0 , 50};
//     Vec3D p3 = {100, 100 , 50};
//     Vec3D p4 = {0, 100 , 50};

//     Vec3D p5 = {0, 0 , -50};
//     Vec3D p6 = {100, 0 , -50};
//     Vec3D p7 = {100, 100 , -50};
//     Vec3D p8 = {0, 100 , -50};

//     Triangle t1 = {.point = {p1, p2, p3}};
//     Triangle t2 = {.point = {p3, p4, p1}};        

//     Triangle t3 = {.point = {p5, p6, p7}};
//     Triangle t4 = {.point = {p7, p8, p5}};        

//     Triangle t5 = {.point = {p1, p5, p8}};
//     Triangle t6 = {.point = {p8, p4, p1}};        

//     Triangle t7 = {.point = {p2, p6, p7}};
//     Triangle t8 = {.point = {p7, p3, p2}};

//     Triangle t9 = {.point = {p4, p3, p7}};
//     Triangle t10 = {.point = {p7, p8, p4}};        

//     Triangle t11 = {.point = {p1, p2, p6}};
//     Triangle t12 = {.point = {p6, p5, p1}};        

//     Triangle arr[12] = {t1, t2,t3, t4,t5, t6,t7, t8, t9, t10, t11, t12};

//     Mesh* temp = (Mesh*)malloc( sizeof( Mesh ) );    

//     temp-> = shape_copyVertexes(vertexes, 8);
//     temp->numEdges = 12;
//     temp->numVertexes = 8;
//     temp->curRotation = rV;
//     temp->edges = edges;   
//     temp->width = UNIT_CUBE_WIDTH;
//     temp->height = UNIT_CUBE_HEIGHT;
//     temp->depth = UNIT_CUBE_DEPTH;     

//     shape_scale(temp, {w,h,d});
//     shape_moveTo(temp,{x,y,z});    

//     return temp;
// }

//! TODO: replace shape with mesh across full document
static void mesh_drawTriangle( SDL_Renderer* renderer, Triangle triag )
{
    SDL_RenderDrawLine(renderer, PIXEL_ALIGNMENT_X + triag.point[0].x, PIXEL_ALIGNMENT_Y + triag.point[0].y, PIXEL_ALIGNMENT_X + triag.point[1].x, PIXEL_ALIGNMENT_Y + triag.point[1].y );
    SDL_RenderDrawLine(renderer, PIXEL_ALIGNMENT_X + triag.point[1].x, PIXEL_ALIGNMENT_Y + triag.point[1].y, PIXEL_ALIGNMENT_X + triag.point[2].x, PIXEL_ALIGNMENT_Y + triag.point[2].y );
    SDL_RenderDrawLine(renderer, PIXEL_ALIGNMENT_X + triag.point[2].x, PIXEL_ALIGNMENT_Y + triag.point[2].y, PIXEL_ALIGNMENT_X + triag.point[0].x, PIXEL_ALIGNMENT_Y + triag.point[0].y );
}


void mesh_draw( SDL_Renderer* renderer, Mesh* mesh, uint16_t R, uint16_t G, uint16_t B )
{
    //! TODO: Colour of triangle edge should be stored in object
    SDL_SetRenderDrawColor(renderer, R ,G ,B ,255);       
    for(uint8_t i = 0 ; i < mesh->numTriangles; i++ )
    {
        mesh_drawTriangle( renderer, mesh->tris[i]);
    }
}


void mesh_moveTo( Mesh* mesh, Vec3D pV )
{    
    Vec3D newV1 = {.x = pV.x + mesh->width/2,   .y=pV.y +  mesh->height/2,  .z=pV.z + mesh->depth/2 };
    Vec3D newV2 = {.x = pV.x + mesh->width/2,   .y=pV.y + -mesh->height/2,  .z=pV.z + mesh->depth/2 };
    Vec3D newV3 = {.x = pV.x + -mesh->width/2,  .y=pV.y + -mesh->height/2,  .z=pV.z + mesh->depth/2 };
    Vec3D newV4 = {.x = pV.x + -mesh->width/2,  .y=pV.y +  mesh->height/2,  .z=pV.z + mesh->depth/2 };
    Vec3D newV5 = {.x = pV.x + mesh->width/2,   .y=pV.y +  mesh->height/2,  .z=pV.z + -mesh->depth/2};
    Vec3D newV6 = {.x = pV.x + mesh->width/2,   .y=pV.y + -mesh->height/2,  .z=pV.z + -mesh->depth/2};
    Vec3D newV7 = {.x = pV.x + -mesh->width/2,  .y=pV.y + -mesh->height/2,  .z=pV.z + -mesh->depth/2};
    Vec3D newV8 = {.x = pV.x + -mesh->width/2,  .y=pV.y +  mesh->height/2,  .z=pV.z + -mesh->depth/2};
    Vec3D newPoints[] = {newV1, newV2, newV3, newV4, newV5, newV6, newV7, newV8};    

    for(uint8_t i = 0 ; i < mesh->numTriangles; i++)  
    {
        for(uint8_t j = 0; j < 3; j++)
        {
            mesh->tris[i].point[j].x = newPoints[i].x;
            mesh->tris[i].point[j].y = newPoints[i].y;
            mesh->tris[i].point[j].z = newPoints[i].z;
        }
    }
}

void mesh_translate( Mesh* mesh, Vec3D tVec )
{
    for( uint16_t i = 0; i < mesh->numTriangles; i++ )
    {
        for(uint8_t j = 0; j < 3; j++)
        {
            mesh->tris[i].point[j].x += tVec.x;
            mesh->tris[i].point[j].y += tVec.z;
            mesh->tris[i].point[j].z += tVec.z;
        }
    }    
}

void mesh_scale( Mesh* mesh, Vec3D sVec )
{
    mesh_setSize(mesh, sVec);
    for(uint8_t i = 0; i < mesh->numTriangles; i++)
    {
        for(uint8_t j = 0; j < 3; j++)
        {
            mesh->tris[i].point[j].x *= sVec.x;
            mesh->tris[i].point[j].y *= sVec.z;
            mesh->tris[i].point[j].z *= sVec.z;
        }
    }    
}

void mesh_setSize(Mesh* mesh, Vec3D sVec)
{
    double newWidth = mesh->width * sVec.x;
    double newHeight = mesh->height * sVec.y;
    double newDepth = mesh->depth * sVec.z;
    mesh->width = newWidth;
    mesh->height = newHeight;
    mesh->depth = newDepth;    
}




void mesh_rotateZ( Mesh* mesh, double degrees )
{    
    Vec3D rV = { .x = 0, .y = 0, .z = degrees };
    // shape_setRotation(S, rV);

    double rads = deg2rad(degrees);       
    
    /* For all triangles */
    for( uint8_t i = 0; i < mesh->numTriangles; i++ )
    {       
        /* For all points in triangle */                          
        for( uint8_t j = 0; j < 3; j++ )
        {
            double xPrime = 0;     
            double yPrime = 0;                        

            xPrime = (mesh->tris[i].point[j].x)*cos(rads) + (mesh->tris[i].point[j].y)*sin(rads);        
            yPrime = (mesh->tris[i].point[j].y)*cos(rads) - (mesh->tris[i].point[j].x)*sin(rads);    

            mesh->tris[i].point[j].x = xPrime;
            mesh->tris[i].point[j].y = yPrime;
        }
    }             
}


void mesh_rotateY( Mesh* mesh, double degrees )
{
    Vec3D rV = { .x = 0, .y = degrees, .z = 0 };
    // shape_setRotation(S, rV);

    double rads = deg2rad(degrees);

    /* For all triangles */
    for( uint8_t i = 0; i < mesh->numTriangles; i++ )
    {       
        /* For all points in triangle */                          
        for( uint8_t j = 0; j < 3; j++ )
        {
            double xPrime = 0;     
            double zPrime = 0;                        

            xPrime = (mesh->tris[i].point[j].x)*cos(rads) - (mesh->tris[i].point[j].z)*sin(rads);        
            zPrime = (mesh->tris[i].point[j].x)*sin(rads) + (mesh->tris[i].point[j].z)*cos(rads);    

            mesh->tris[i].point[j].x = xPrime;
            mesh->tris[i].point[j].z = zPrime;
        }
    }   
}


void mesh_rotateX( Mesh* mesh, double degrees )
{
    Vec3D rV = { .x = degrees, .y = 0, .z = 0 };
    // shape_setRotation(S, rV);

    float rads = deg2rad(degrees);
    
    /* For all triangles */
    for( uint8_t i = 0; i < mesh->numTriangles; i++ )
    {       
        /* For all points in triangle */                          
        for( uint8_t j = 0; j < 3; j++ )
        {
            double yPrime = 0;     
            double zPrime = 0;                        

            yPrime = (mesh->tris[i].point[j].y)*cos(rads) + (mesh->tris[i].point[j].z)*sin(rads);        
            zPrime = (mesh->tris[i].point[j].z)*cos(rads) - (mesh->tris[i].point[j].y)*sin(rads);    

            mesh->tris[i].point[j].y = yPrime;
            mesh->tris[i].point[j].z = zPrime;
        }
    }   
}
        
void mesh_setRotation(Mesh* mesh, Vec3D Rvec_deg)
{        
    mesh->curRotation.x = (int)round(mesh->curRotation.x + Rvec_deg.x) % 360;
    mesh->curRotation.y = (int)round(mesh->curRotation.y + Rvec_deg.y) % 360;
    mesh->curRotation.z = (int)round(mesh->curRotation.z + Rvec_deg.z) % 360;    
}



// void my_PerspectiveFOV(double fov, double aspect, double near, double far, double* mret) {
//     double D2R = M_PI / 180.0;
//     double yScale = 1.0 / tan(D2R * fov / 2);
//     double xScale = yScale / aspect;
//     double nearmfar = near - far;
//     double m[] = {
//         xScale, 0, 0, 0,
//         0, yScale, 0, 0,
//         0, 0, (far + near) / nearmfar, -1,
//         0, 0, 2*far*near / nearmfar, 0 
//     };    
//     memcpy(mret, m, sizeof(double)*16);
// }


void mesh_clear( SDL_Renderer* renderer, Mesh* mesh )
{
    SDL_SetRenderDrawColor(renderer, BACKGROUND_R ,BACKGROUND_G ,BACKGROUND_B ,255);        
    for(uint8_t i = 0; i < mesh->numTriangles; i++)
    {                
        mesh_drawTriangle(renderer, mesh->tris[i]);        
    }    
}


Vec3D* shape_copyVertexes( Vec3D source[], uint8_t size ) {    
    Vec3D* newArr = (Vec3D*)malloc(VEC3D_SIZE * size); // allocate memory for the new array

    for( uint8_t i = 0; i < size; i++ )
    {        
        (newArr + i)->x = source[i].x;        
        (newArr + i)->y = source[i].y;
        (newArr + i)->z = source[i].z;                
    }

  return newArr; // return the new array
}