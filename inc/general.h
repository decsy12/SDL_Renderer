#ifndef GENERAL_H
#define GENERAL_H

#include <stdint.h>

typedef struct 
{
    float x;
    float y;
    float z;
}Vec3D;

#define deg2rad(deg)        360.0/M_PI/deg
#define rad2deg(rad)        M_PI/360.0*rad


int* matmul(float* A, float* B, int m, int n, int p);
// float* struct2Mat( Vec3D* V );
Vec3D* mat2Struct( float* M, Vec3D* V );

#endif