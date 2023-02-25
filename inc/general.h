#ifndef GENERAL_H
#define GENERAL_H

#include <stdint.h>
#include "mesh.h"

#define deg2rad(deg)        ( deg * M_PI ) / 180
#define rad2deg(rad)        rad * ( 180 / M_PI )

typedef struct
{
    float mat[4][4];
}Mat4x4;


int* matmul(float* A, float* B, int m, int n, int p);
void MultiplyMatrix( Vec3D* i, Vec3D* o, Mat4x4* m);
Vec3D* mat2Struct( float* M, Vec3D* V );
Vec3D crossProduct(Vec3D* A, Vec3D* B);

#endif