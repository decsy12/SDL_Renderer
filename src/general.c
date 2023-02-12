#include "general.h"


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
Vec3D* mat2Struct( float* M, Vec3D* V )
{
    V->x = *(M+0);
    V->y = *(M+1);
    V->z = *(M+2);

    return V;
}
