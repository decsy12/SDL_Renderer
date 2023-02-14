#include "shape.h"
#include "SDL2/SDL.h"
#include "general.h"
#include "main.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>


void shape_printVertexes( Shape* S )
{
    for(uint8_t i = 0; i < S->numVertexes; i++)
    {        
        printf("[%.2f,%.2f,%.2f]\n",S->vertexes[i].x,S->vertexes[i].y,S->vertexes[i].z);
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
    for(uint8_t i = 0; i < S->numVertexes; i++)
    {
        S->vertexes[i].x *= sVec.x;
        S->vertexes[i].y *= sVec.y;
        S->vertexes[i].z *= sVec.z;
    }    
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


//     def scale_shape(self, sVec):
//         #Add check if dVec is 1x3 matrix, each with number
        
//         #Add distance vector to each vertex in Shape
//         for vertex in self.vertexes:
//             vertex[COORD_X] *= sVec[COORD_X]
//             vertex[COORD_Y] *= sVec[COORD_Y]
//             vertex[COORD_Z] *= sVec[COORD_Z]    
            
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