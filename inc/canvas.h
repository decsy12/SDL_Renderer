#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>
// #include "mesh.h"
#include "general.h"
#include "SDL2/SDL.h"

typedef struct {
    uint16_t        width;
    uint16_t        height;
    Shape**         currentCanvas;
    SDL_Renderer*   renderer;
    SDL_Window*     window;   
}Canvas;

void canvas_addShape( Canvas* C, Shape* newShape );
void canvas_bringForward( Canvas* C, Shape* newShape );
void canvas_takeBack( Canvas* C, Shape* newShape );
void canvas_toFront( Canvas* C, Shape* newShape );
void canvas_toBack( Canvas* C, Shape* newShape );

void canvas_clearMesh( SDL_Renderer* renderer, Mesh* mesh );
void canvas_drawMesh( SDL_Renderer* renderer, Mesh* mesh, uint16_t R, uint16_t G, uint16_t B );


#endif