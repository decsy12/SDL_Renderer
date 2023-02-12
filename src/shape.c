#include "shape.h"
#include "general.h"
#include <stdint.h>
#include <stdio.h>
#include <math.h>


void shape_printVertexes( Shape* S )
{
    for(uint8_t i = 0; i < S->numVertexes; i++)
    {        
        printf("[%d,%d,%d]\n",S->vertexes[i].x,S->vertexes[i].y,S->vertexes[i].z);
    }
}

void shape_translate( Shape* S, Vec3D tVec )
{
    for( uint16_t i = 0; i < S->numVertexes; i++ )
    {
        S->vertexes[i].x += tVec.x;
        S->vertexes[i].y += tVec.y;
        S->vertexes[i].z += tVec.z;
    }    
}

void shape_scale( Shape* S, Vec3D sVec )
{
    for(uint8_t i = 0; i < S->numVertexes; i++)
    {
        S->vertexes[i].x *= sVec.x;
        S->vertexes[i].y *= sVec.y;
        S->vertexes[i].z *= sVec.z;
    }    
}


// void shape_rotateZ( Shape* S, int8_t degrees )
// {
//     //  self.set_rotation([0,0,degrees])
//     // shape_setRotation({});

//     float rads = deg2rad(degrees);

//     /* Z-Axis rotation matrix */
//     float rotationZ[3*3] = {cos(rads), -sin(rads), 0, 
//                             sin(rads), cos(rads) , 0, 
//                             0        , 0         , 1};
    
//     for( uint8_t i = 0; i < S->numVertexes; i++ )
//     {                       
//         float tempVecMat[3] = { S->vertexes[i].x,
//                                 S->vertexes[i].y,
//                                 S->vertexes[i].z };
        
//         mat2Struct( matmul(tempVecMat, rotationZ, 1, 3, 3),
//                     &(S->vertexes[i]));
//     }     
// }


// void shape_rotateY( Shape* S, int8_t degrees )
// {
//     //  self.set_rotation([0,0,degrees])
//     // shape_setRotation({});

//     float rads = deg2rad(degrees);

//     /* Z-Axis rotation matrix */
//     float rotationY[3*3] = {cos(rads),  0, sin(rads),
//                             0,          1,         0,
//                             -1*sin(rads), 0, cos(rads)};
    
//     for( uint8_t i = 0; i < S->numVertexes; i++ )
//     {                        
//         mat2Struct(matmul(struct2Mat(&(S->vertexes[i])), rotationY, 1, 3, 3) , &(S->vertexes[i]));       
//     }     
// }


// void shape_rotateX( Shape* S, int8_t degrees )
// {
//     //  self.set_rotation([0,0,degrees])
//     // shape_setRotation({});

//     float rads = deg2rad(degrees);

//     /* Z-Axis rotation matrix */
//     float rotationX[3*3] = {1,         0,          0,
//                             0, cos(rads), -1*sin(rads),
//                             0, sin(rads), cos(rads)};
    
//     for( uint8_t i = 0; i < S->numVertexes; i++ )
//     {                        
//         mat2Struct(matmul(struct2Mat(&(S->vertexes[i])), rotationX, 1, 3, 3) , &(S->vertexes[i]));          
//     }     
// }
        
void shape_setRotation(Shape* S, Vec3D Rvec_deg)
{
    S->curRotation.x = (S->curRotation.x + Rvec_deg.x) % 360;
    S->curRotation.y = (S->curRotation.y + Rvec_deg.y) % 360;
    S->curRotation.z = (S->curRotation.z + Rvec_deg.z) % 360;
}


//     def scale_shape(self, sVec):
//         #Add check if dVec is 1x3 matrix, each with number
        
//         #Add distance vector to each vertex in Shape
//         for vertex in self.vertexes:
//             vertex[COORD_X] *= sVec[COORD_X]
//             vertex[COORD_Y] *= sVec[COORD_Y]
//             vertex[COORD_Z] *= sVec[COORD_Z]    
            
//     def new_edge(self, v1Idx, v2Idx):
//         #TODO: Find vertex index in vertexs array
        
//         #add both indexes to edges array
        
//         self.edges.append([v1Idx, v2Idx])
//         self.numEdges += 1