#ifndef GENERAL_H
#define GENERAL_H

#include <stdint.h>
#include "mesh.h"

#define deg2rad(deg)        ( deg * M_PI ) / 180
#define rad2deg(rad)        rad * ( 180 / M_PI )


int* matmul(float* A, float* B, int m, int n, int p);
// float* struct2Mat( Vec3D* V );
Vec3D* mat2Struct( float* M, Vec3D* V );

#endif