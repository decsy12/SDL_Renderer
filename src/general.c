#include "general.h"
#include "mesh.h"
#include <stdlib.h>


int* matmul(float* A, float* B, int m, int n, int p) {
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


void MultiplyMatrix( Vec3D* i, Vec3D* o, Mat4x4* m)
{
    o->x = i->x * m->mat[0][0] + i->y * m->mat[1][0] + i->z * m->mat[2][0] + m->mat[3][0];
    o->y = i->x * m->mat[0][1] + i->y * m->mat[1][1] + i->z * m->mat[2][1] + m->mat[3][1];
    o->z = i->x * m->mat[0][2] + i->y * m->mat[1][2] + i->z * m->mat[2][2] + m->mat[3][2];
    float w = i->x * m->mat[0][3] + i->y * m->mat[1][3] + i->z * m->mat[2][3] + m->mat[3][3];

    if(w != 0.0f)
    {
        o->x /= w;
        o->y /= w;
        o->z /= w;
    }
}


//Matrix to Vec3D
Vec3D* mat2Struct( float* M, Vec3D* V )
{
    V->x = *(M+0);
    V->y = *(M+1);
    V->z = *(M+2);

    return V;
}

Vec3D crossProduct(Vec3D* A, Vec3D* B)
{
    Vec3D N;

    N.x = (A->y * B->z) - ( A->z * B->y );
    N.y = (A->z * B->x) - ( A->x * B->z );
    N.z = (A->x * B->y) - ( A->y * B->x );

    return N;
}
