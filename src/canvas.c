#include <stdio.h>
#include <stdint.h>
#include "canvas.h"
#include "main.h"
#include "mesh.h"
#include "general.h"
#include "SDL2/SDL.h"

static void mesh_drawTriangle( SDL_Renderer* renderer, Triangle triag );

Mat4x4 g_matProj = {.mat = {{PROJ_ASPECT_RATIO * PROJ_FOV_RAD,      0,              0,                                                      0},
                            {0,                                     PROJ_FOV_RAD,   0,                                                      0},
                            {0,                                     0,              PROJ_FAR / (PROJ_FAR - PROJ_NEAR),                      1.0f},
                            {0,                                     0,              ( -PROJ_FAR * PROJ_NEAR ) / ( PROJ_FAR - PROJ_NEAR ),   0.0f}}};


void canvas_addShape( Canvas* C, Shape* newShape )
{

}

void canvas_bringForward( Canvas* C, Shape* newShape )
{

}

void canvas_takeBack( Canvas* C, Shape* newShape )
{

}

void canvas_toFront( Canvas* C, Shape* newShape )
{

}

void canvas_toBack( Canvas* C, Shape* newShape )
{

}


//! TODO: replace shape with mesh across full document
static void mesh_drawTriangle( SDL_Renderer* renderer, Triangle triag )
{    
    // SDL_RenderDrawLine(renderer, PIXEL_ALIGNMENT_X + triag.point[0].x, PIXEL_ALIGNMENT_Y + triag.point[0].y, PIXEL_ALIGNMENT_X + triag.point[1].x, PIXEL_ALIGNMENT_Y + triag.point[1].y );
    // SDL_RenderDrawLine(renderer, PIXEL_ALIGNMENT_X + triag.point[1].x, PIXEL_ALIGNMENT_Y + triag.point[1].y, PIXEL_ALIGNMENT_X + triag.point[2].x, PIXEL_ALIGNMENT_Y + triag.point[2].y );
    // SDL_RenderDrawLine(renderer, PIXEL_ALIGNMENT_X + triag.point[2].x, PIXEL_ALIGNMENT_Y + triag.point[2].y, PIXEL_ALIGNMENT_X + triag.point[0].x, PIXEL_ALIGNMENT_Y + triag.point[0].y );
    SDL_RenderDrawLine(renderer, triag.point[0].x, triag.point[0].y, triag.point[1].x, triag.point[1].y );
    SDL_RenderDrawLine(renderer, triag.point[1].x, triag.point[1].y, triag.point[2].x, triag.point[2].y );
    SDL_RenderDrawLine(renderer, triag.point[2].x, triag.point[2].y, triag.point[0].x, triag.point[0].y );
}


void canvas_drawMesh( SDL_Renderer* renderer, Mesh* mesh, uint16_t R, uint16_t G, uint16_t B )
{
    //! TODO: Colour of triangle edge should be stored in object
    SDL_SetRenderDrawColor(renderer, R ,G ,B ,255);       
    for(uint8_t i = 0 ; i < mesh->numTriangles; i++ )
    {
        Triangle triProjected, triTranslated;        

        triTranslated = mesh->tris[i];

        for(uint8_t j = 0; j < 3; j++)
        {
            triTranslated.point[j].z = mesh->tris[i].point[j].z + 10.0f;            

            //triprojected = current triangle * projection matrix
            MultiplyMatrix( &(triTranslated.point[j]), &(triProjected.point[j]), &g_matProj );            

            //Scale into view
            triProjected.point[j].x += 1.0f; 
            triProjected.point[j].y += 1.0f;                    

            // Move to middle of screen
            triProjected.point[j].x *= 0.5f * (float)WINDOW_WIDTH;
            triProjected.point[j].y *= 0.5f * (float)WINDOW_HEIGHT;            
        }

        mesh_drawTriangle( renderer, triProjected);
    }
}


void canvas_clearMesh( SDL_Renderer* renderer, Mesh* mesh )
{    
    canvas_drawMesh(renderer, mesh, BACKGROUND_R ,BACKGROUND_G ,BACKGROUND_B);
}