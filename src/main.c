#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "SDL2/SDL.h"
#include <assert.h>
#include <math.h>

#include "main.h"
#include "shape.h"
#include "general.h"

#pragma pack(1)

//! TODO: Restructure to follow proper graphics pipeline
//          - Vertex array
//          - Vertex processing (i.e. line drawing or edge handling) usually bundled into triangles
//          - Rasterisation (This may be performed by SDL as it uses OpenGL)
//          - Shading
//          - Output buffer

//! TODO: Should edge store pointer to each shape vertex at start and end of edge?
//! BUG: C1 and C2 dont seem to be seperatable, fix i.e. move cubes to different coordinates
//! TODO: Add better way to render multiple shapes i.e. should the canvas hold a pointer list to all shapes and passed into function?
//! TODO: Implement some placement engine e.g. placing a wall of cubes
//! TODO: Add extra 3D shapes

bool g_isRunning = true;    

void rotate_cube(SDL_Renderer *renderer, Shape* cube, uint16_t xR, uint16_t yR, uint16_t zR)
{
    shape_rotateY( cube, yR );         
    shape_rotateX( cube, xR );
    shape_rotateZ( cube, zR );     
    shape_draw(renderer, cube, 255, 255, 255);       
}

int main(int argv, char** args)
{
    SDL_Event       event;
    SDL_Renderer*   renderer;
    SDL_Window*     window;        
        
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);    
    SDL_SetWindowTitle(window, "SDL - CLOSE ME");
    SDL_SetRenderDrawColor(renderer, BACKGROUND_R, BACKGROUND_G, BACKGROUND_B, BACKGROUND_A);        

    Shape* C1 = shape_cube(50,50,50,   100,   100,  100);
    Shape* C2 = shape_cube(50,50,50,  -100,   100,  100);
    Shape* C3 = shape_cube(50,50,50,   100,  -100,  100);
    Shape* C4 = shape_cube(50,50,50,  -100,  -100,  100);

    Shape* C5 = shape_cube(50,50,50,  100 ,  100  , -100);
    Shape* C6 = shape_cube(50,50,50,  -100,  100  , -100);
    Shape* C7 = shape_cube(50,50,50,  100 ,  -100 , -100);
    Shape* C8 = shape_cube(50,50,50,  -100,  -100 , -100);

    while (g_isRunning)
    {           
        rotate_cube( renderer, C1,  1, 1, 1 );
        rotate_cube( renderer, C2,  1, 1, 1 );
        rotate_cube( renderer, C3,  1, 1, 1 );
        rotate_cube( renderer, C4,  1, 1, 1 );
        rotate_cube( renderer, C5,  1, 1, 1 );
        rotate_cube( renderer, C6,  1, 1, 1 );
        rotate_cube( renderer, C7,  1, 1, 1 );
        rotate_cube( renderer, C8,  1, 1, 1 );                             
        SDL_RenderPresent(renderer);                    
        SDL_Delay(WINDOW_TICK_MS);                     
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
        shape_clear(renderer, C1);   
        shape_clear(renderer, C2);           
        shape_clear(renderer, C3);   
        shape_clear(renderer, C4);   
        shape_clear(renderer, C5);   
        shape_clear(renderer, C6);           
        shape_clear(renderer, C7);   
        shape_clear(renderer, C8);        
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}