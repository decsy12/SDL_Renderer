#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include "SDL2/SDL.h"
#include <assert.h>
#include <math.h>

#include "main.h"
#include "mesh.h"
#include "general.h"
#include "canvas.h"

#pragma pack(1)

//! TODO: Implement perspective matrix
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

void rotate_cube(SDL_Renderer *renderer, Mesh* cube, uint16_t xR, uint16_t yR, uint16_t zR)
{
    mesh_rotateY( cube, yR );         
    mesh_rotateX( cube, xR );    
    mesh_rotateZ( cube, zR );     
    mesh_draw(renderer, cube, 255, 255, 255);       
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

    // Shape* C1 = shape_cube(50,50,50,   100,   100,  100);
    // Shape* C2 = shape_cube(50,50,50,  -100,   100,  100);
    // Shape* C3 = shape_cube(50,50,50,   100,  -100,  100);
    // Shape* C4 = shape_cube(50,50,50,  -100,  -100,  100);

    // Shape* C5 = shape_cube(50,50,50,  100 ,  100  , -100);
    // Shape* C6 = shape_cube(50,50,50,  -100,  100  , -100);
    // Shape* C7 = shape_cube(50,50,50,  100 ,  -100 , -100);
    // Shape* C8 = shape_cube(50,50,50,  -100,  -100 , -100);

    Vec3D p1 = {0, 0 , 50};
    Vec3D p2 = {100, 0 , 50};
    Vec3D p3 = {100, 100 , 50};
    Vec3D p4 = {0, 100 , 50};

    Vec3D p5 = {0, 0 , -50};
    Vec3D p6 = {100, 0 , -50};
    Vec3D p7 = {100, 100 , -50};
    Vec3D p8 = {0, 100 , -50};

    Triangle t1 = {.point = {p1, p2, p3}};
    Triangle t2 = {.point = {p3, p4, p1}};        

    Triangle t3 = {.point = {p5, p6, p7}};
    Triangle t4 = {.point = {p7, p8, p5}};        

    Triangle t5 = {.point = {p1, p5, p8}};
    Triangle t6 = {.point = {p8, p4, p1}};        

    Triangle t7 = {.point = {p2, p6, p7}};
    Triangle t8 = {.point = {p7, p3, p2}};

    Triangle t9 = {.point = {p4, p3, p7}};
    Triangle t10 = {.point = {p7, p8, p4}};        

    Triangle t11 = {.point = {p1, p2, p6}};
    Triangle t12 = {.point = {p6, p5, p1}};        

    Triangle arr[12] = {t1, t2,t3, t4,t5, t6,t7, t8, t9, t10, t11, t12};
    Mesh Cube = { .tris = arr,
                    .numTriangles = sizeof(arr)/sizeof(arr[0])};    

    while (g_isRunning)
    {           
        //! TODO: Replace these rotate functions with Canvas functions i.e. for loop rotating all canvas objects
        rotate_cube( renderer, &Cube, 1, 1, 1 );
        
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
        mesh_clear(renderer, &Cube);      
        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}