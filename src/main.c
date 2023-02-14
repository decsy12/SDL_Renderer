#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "SDL2/SDL.h"
#include <assert.h>
#include <math.h>

#include "main.h"
#include "shape.h"
#include "general.h"

// g++ -o main.exe ./src/main.c -Iinc ./src/shape.c -Iinc ./src/general.c -lmingw32 -lSDL2main -lSDL2

bool g_isRunning = true;    

double w = 200;
double h = 200;
double d = 200;


//! TODO: Refactor this process into a clean function or something
Vec3D v1 = {.x = w/2,   .y= h/2,  .z=d/2 };
Vec3D v2 = {.x = w/2,   .y=-h/2,  .z=d/2 };
Vec3D v3 = {.x = -w/2,  .y=-h/2,  .z=d/2 };
Vec3D v4 = {.x = -w/2,  .y= h/2,  .z=d/2 };

Vec3D v5 = {.x = w/2,   .y= h/2,  .z=-d/2};
Vec3D v6 = {.x = w/2,   .y=-h/2,  .z=-d/2};
Vec3D v7 = {.x = -w/2,  .y=-h/2,  .z=-d/2};
Vec3D v8 = {.x = -w/2,  .y= h/2,  .z=-d/2};
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


Shape cubey = { .vertexes = vertexes,
                .numEdges = 12,
                .numVertexes = 8,
                .curRotation = {.x = 0, .y = 0, .z = 0},
                .edges = edges,};


int main(int argv, char** args)
{
    SDL_Event       event;
    SDL_Renderer*   renderer;
    SDL_Window*     window;        
        
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);    
    SDL_SetRenderDrawColor(renderer, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, BACKGROUND_A);        
        
    while (g_isRunning)
    {
        SDL_RenderPresent(renderer);    
        shape_rotateY( &cubey, 1 );         
        shape_rotateX( &cubey, 1 );
        shape_rotateZ( &cubey, 1 );     
        shape_draw(renderer, &cubey, 255, 255, 255);   
        SDL_RenderPresent(renderer);    
        SDL_Delay(WINDOW_TICK_MS);        
        shape_clear(renderer, &cubey);   
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                g_isRunning = false;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    g_isRunning = false;
                }
            }
        }
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}