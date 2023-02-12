#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "SDL2/SDL.h"
#include <assert.h>

#include "shape.h"
#include "general.h"

// g++ -o main.exe ./src/main.c -Iinc ./src/shape.c -Iinc ./src/general.c -lmingw32 -lSDL2main -lSDL2

#define WINDOW_WIDTH        1000
#define WINDOW_HEIGHT       1000
#define WINDOW_MIDDLE_X     WINDOW_WIDTH / 2
#define WINDOW_MIDDLE_Y     WINDOW_HEIGHT / 2

#define R_MASK              32
#define G_MASK              16
#define B_MASK              8
#define A_MASK              0

#define COLOUR_BLACK        0xFFFFFFFF

#define BACKGROUND_COLOUR   COLOUR_BLACK
// #define BACKGROUND_R        (BACKGROUND_COLOUR & 0xFF000000) >> 32UL
// #define BACKGROUND_G        (BACKGROUND_COLOUR & 0x00FF0000) >> 16UL
// #define BACKGROUND_B        (BACKGROUND_COLOUR & 0x0000FF00) >> 8UL
// #define BACKGROUND_A        (BACKGROUND_COLOUR & 0x000000FF) >> 0UL
#define BACKGROUND_R        0x00
#define BACKGROUND_G        0x00
#define BACKGROUND_B        0x00
#define BACKGROUND_A        0x00

bool g_isRunning = true;    

float w = 10;
float h = 10;
float d = 10;

Vec3D v1 = {.x = w/2,  .y=h/2,  .z=d/2 };
Vec3D v2 = {.x = w/2,  .y=-h/2, .z=d/2 };
Vec3D v3 = {.x = -w/2, .y=h/2,  .z=d/2 };
Vec3D v4 = {.x = -w/2, .y=-h/2, .z=d/2 };
Vec3D v5 = {.x = w/2,  .y=h/2,  .z=-d/2};
Vec3D v6 = {.x = w/2,  .y=-h/2, .z=-d/2};
Vec3D v7 = {.x = -w/2, .y=h/2,  .z=-d/2};
Vec3D v8 = {.x = -w/2, .y=-h/2, .z=-d/2};

Shape cubey = { .curRotation = {.x = 0, .y = 0, .z = 0},
                .numEdges = 0,
                .numVertexes = 8,
                .vertexes = {v1,v2,v3,v4,v5,v6,v7,v8}};

int main(int argv, char** args)
{
    SDL_Event       event;
    SDL_Renderer*   renderer;
    SDL_Window*     window;        
        
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);    
    SDL_SetRenderDrawColor(renderer, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, BACKGROUND_A);
    SDL_RenderClear(renderer);  
    SDL_SetRenderDrawColor(renderer, 255 ,0 ,0 ,255);
    uint8_t width = 100;
    uint8_t height = 100;
    SDL_Rect r1 = { .x = WINDOW_MIDDLE_X - (250/2),
                    .y = WINDOW_MIDDLE_Y - (250/2),
                    .w = 250,
                    .h = 250};

    SDL_RenderDrawRect( renderer, &r1);    
    SDL_RenderPresent(renderer);

    while (g_isRunning)
    {
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