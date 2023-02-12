#ifndef GENERAL_H
#define GENERAL_H

#include "stdint.h"

typedef struct 
{
    int16_t x;
    int16_t y;
    int16_t z;
}Vec3D;


int* matmul(int* A, int* B, int m, int n, int p);
float* struct2Mat( Vec3D* V );
Vec3D* mat2Struct( float* M, Vec3D* V );

#endif