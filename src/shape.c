#include "SDL2/SDL.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>

#include "shape.h"
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


Shape* shape_cube( double w, double h, double d, double x, double y, double z )
{
    
    Shape* temp = (Shape*)malloc( sizeof( Shape ) );    

    temp->vertexes = shape_copyVertexes(vertexes, 8);
    temp->numEdges = 12;
    temp->numVertexes = 8;
    temp->curRotation = rV;
    temp->edges = edges;   
    temp->width = UNIT_CUBE_WIDTH;
    temp->height = UNIT_CUBE_HEIGHT;
    temp->depth = UNIT_CUBE_DEPTH;     

    shape_scale(temp, {w,h,d});
    shape_moveTo(temp,{x,y,z});    

    return temp;
}


void shape_printVertexes( Shape* S, const char* shapeName )
{
    for(uint8_t i = 0; i < S->numVertexes; i++)
    {        
        printf("%s vertex[%d] = \t[%.2f, %.2f, %.2f]\n",shapeName,i,S->vertexes[i].x,S->vertexes[i].y,S->vertexes[i].z);
    }
}

void shape_moveTo( Shape* S, Vec3D pV )
{    
    Vec3D newV1 = {.x = pV.x + S->width/2,   .y=pV.y +  S->height/2,  .z=pV.z + S->depth/2 };    
    Vec3D newV2 = {.x = pV.x + S->width/2,   .y=pV.y + -S->height/2,  .z=pV.z + S->depth/2 };    
    Vec3D newV3 = {.x = pV.x + -S->width/2,  .y=pV.y + -S->height/2,  .z=pV.z + S->depth/2 };    
    Vec3D newV4 = {.x = pV.x + -S->width/2,  .y=pV.y +  S->height/2,  .z=pV.z + S->depth/2 };    
    Vec3D newV5 = {.x = pV.x + S->width/2,   .y=pV.y +  S->height/2,  .z=pV.z + -S->depth/2};    
    Vec3D newV6 = {.x = pV.x + S->width/2,   .y=pV.y + -S->height/2,  .z=pV.z + -S->depth/2};    
    Vec3D newV7 = {.x = pV.x + -S->width/2,  .y=pV.y + -S->height/2,  .z=pV.z + -S->depth/2};    
    Vec3D newV8 = {.x = pV.x + -S->width/2,  .y=pV.y +  S->height/2,  .z=pV.z + -S->depth/2};    
    Vec3D newVertexes[] = {newV1, newV2, newV3, newV4, newV5, newV6, newV7, newV8};    

    for(uint8_t i = 0 ; i < S->numVertexes; i++)  
    {
        S->vertexes[i].x = newVertexes[i].x;
        S->vertexes[i].y = newVertexes[i].y;
        S->vertexes[i].z = newVertexes[i].z;
    }
}

void shape_translate( Shape* S, Vec3D tVec )
{
    for( uint16_t i = 0; i < S->numVertexes; i++ )
    {
        S->vertexes[i].x += tVec.x;
        S->vertexes[i].y += tVec.y;
        S->vertexes[i].z += tVec.z;
    }    
}

void shape_scale( Shape* S, Vec3D sVec )
{
    shape_setSize(S, sVec);
    for(uint8_t i = 0; i < S->numVertexes; i++)
    {
        S->vertexes[i].x *= sVec.x;
        S->vertexes[i].y *= sVec.y;
        S->vertexes[i].z *= sVec.z;
    }    
}

void shape_setSize(Shape* S, Vec3D sVec)
{
    double newWidth = S->width * sVec.x;
    double newHeight = S->height * sVec.y;
    double newDepth = S->width * sVec.z;
    S->width = newWidth;
    S->height = newHeight;
    S->depth = newDepth;    
}

void shape_rotateZ( Shape* S, double degrees )
{    
    Vec3D rV = { .x = degrees, .y = 0, .z = 0 };
    shape_setRotation(S, rV);

    double rads = deg2rad(degrees);       
    
    for( uint8_t i = 0; i < S->numVertexes; i++ )
    {                         
        double xPrime = 0;     
        double yPrime = 0;
                
        xPrime = (S->vertexes[i].x)*cos(rads) + (S->vertexes[i].y)*sin(rads);        
        yPrime = (S->vertexes[i].y)*cos(rads) - (S->vertexes[i].x)*sin(rads);    

        S->vertexes[i].x = xPrime;
        S->vertexes[i].y = yPrime;
    }             
}


void shape_rotateY( Shape* S, double degrees )
{
    Vec3D rV = { .x = degrees, .y = 0, .z = 0 };
    shape_setRotation(S, rV);

    double rads = deg2rad(degrees);

    
    for( uint8_t i = 0; i < S->numVertexes; i++ )
    {                        
        double xPrime = 0;     
        double zPrime = 0;
        
        xPrime = (S->vertexes[i].x)*cos(rads) - (S->vertexes[i].z)*sin(rads);
        zPrime = (S->vertexes[i].x)*sin(rads) + (S->vertexes[i].z)*cos(rads);        

        S->vertexes[i].x = xPrime;
        S->vertexes[i].z = zPrime;
    }     
}


void shape_rotateX( Shape* S, double degrees )
{
    Vec3D rV = { .x = degrees, .y = 0, .z = 0 };
    shape_setRotation(S, rV);

    float rads = deg2rad(degrees);
    
    for( uint8_t i = 0; i < S->numVertexes; i++ )
    {                        
        double yPrime = 0;     
        double zPrime = 0;
        
        yPrime = (S->vertexes[i].y)*cos(rads) + (S->vertexes[i].z)*sin(rads);
        zPrime = (S->vertexes[i].z)*cos(rads) - (S->vertexes[i].y)*sin(rads);    

        S->vertexes[i].y = yPrime;
        S->vertexes[i].z = zPrime;
    }       
}
        
void shape_setRotation(Shape* S, Vec3D Rvec_deg)
{        
    S->curRotation.x = (int)round(S->curRotation.x + Rvec_deg.x) % 360;
    S->curRotation.y = (int)round(S->curRotation.x + Rvec_deg.y) % 360;
    S->curRotation.z = (int)round(S->curRotation.x + Rvec_deg.z) % 360;
}


//     def new_edge(self, v1Idx, v2Idx):
//         #TODO: Find vertex index in vertexs array
        
//         #add both indexes to edges array
        
//         self.edges.append([v1Idx, v2Idx])
//         self.numEdges += 1



void shape_draw( SDL_Renderer* renderer, Shape* S, uint8_t R, uint8_t G, uint8_t B)
{
    SDL_SetRenderDrawColor(renderer, R ,G ,B ,255);        
    for(uint8_t i = 0; i < S->numEdges; i++)
    {                
        uint8_t V1Idx = S->edges[i][0];
        uint8_t V2Idx = S->edges[i][1];
        SDL_RenderDrawLine(renderer, PIXEL_ALIGNMENT_X + S->vertexes[V1Idx].x, PIXEL_ALIGNMENT_Y + S->vertexes[V1Idx].y, PIXEL_ALIGNMENT_X + S->vertexes[V2Idx].x, PIXEL_ALIGNMENT_Y + S->vertexes[V2Idx].y);
    }    
}

void shape_clear( SDL_Renderer* renderer, Shape* S )
{
    SDL_SetRenderDrawColor(renderer, BACKGROUND_R ,BACKGROUND_G ,BACKGROUND_B ,255);        
    for(uint8_t i = 0; i < S->numEdges; i++)
    {
        uint8_t V1Idx = S->edges[i][0];
        uint8_t V2Idx = S->edges[i][1];
        SDL_RenderDrawLine(renderer, WINDOW_MIDDLE_X + S->vertexes[V1Idx].x, WINDOW_MIDDLE_Y + S->vertexes[V1Idx].y, WINDOW_MIDDLE_X + S->vertexes[V2Idx].x, WINDOW_MIDDLE_Y + S->vertexes[V2Idx].y);
    }    
}


Vec3D* shape_copyVertexes( Vec3D source[], uint8_t size ) {    
    Vec3D* newArr = (Vec3D*)malloc(VEC3D_SIZE * size); // allocate memory for the new array

    for( uint8_t i = 0; i < size; i++ )
    {        
        (newArr + i)->x = source[i].x;        
        (newArr + i)->y = source[i].y;
        (newArr + i)->z = source[i].z;        
        // printf("Copying [%.2f,%.2f,%.2f]    ->\t [%.2f,%.2f,%.2f] \n", source[i].x, source[i].y, source[i].z, (newArr + i)->x, (newArr + i)->y, (newArr + i)->z);
    }

  return newArr; // return the new array
}