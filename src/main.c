#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "SDL2/SDL.h"
#include <cmath.h>
#include <assert.h>

#include "shape.h"

// COMPILE SCRIPT: g++ -o main.exe main.c -lmingw32 -lSDL2main -lSDL2

#define WINDOW_WIDTH    1000
#define WINDOW_HEIGHT   1000


bool g_isRunning = true;    


int* matmul(int* A, int* B, int m, int n, int p) {
  int* C = (int*)malloc(m * p * sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[i * n + k] * B[k * p + j];
            }
            C[i * p + j] = sum;
        }
    }

    return C;
}

//Vec3D to matrix
float* struct2Mat( Vec3D* V )
{
    float x[3];

    x[0] = V->x;
    x[1] = V->y;
    x[2] = V->z;

    return x;
}

//Matrix to Vec3D
float* mat2Struct( float* M, Vec3D* V )
{
    V->x = *(M+0);
    V->y = *(M+1);
    V->z = *(M+2);

    return V;
}


int main(int argv, char** args)
{
    SDL_Event       event;
    SDL_Renderer*   renderer;
    SDL_Window*     window;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawPoint(renderer, WINDOW_HEIGHT/2, WINDOW_WIDTH/2);
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