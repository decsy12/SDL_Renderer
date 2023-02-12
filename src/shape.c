#include "shape.h"
#include "general.h"
#include "stdint.h"


void shape_printVertexes( Shape* S )
{
    for(uint8_t i = 0; i < S->numVertexes; i++)
    {        
        printf("[%d,%d,%d]\n",S->vertexes[i].x,S->vertexes[i].y,S->vertexes[i].z);
    }

    return &S;
}

Shape* shape_translate( Shape* S, Vec3D tVec )
{
    for( uint16_t i = 0; i < S->numVertexes; i++ )
    {
        S->vertexes[i].x += tVec.x;
        S->vertexes[i].y += tVec.y;
        S->vertexes[i].z += tVec.z;
    }

    return &S;
}


Shape* shape_rotateZ( Shape* S, int8_t degrees )
{
    //  self.set_rotation([0,0,degrees])
    // shape_setRotation({});

    /* Z-Axis rotation matrix */
    float rotationZ[3*3] = [cos(deg2rad(degrees)), -sin(deg2rad(degrees)), 0,
                            sin(deg2rad(degrees)), cos(deg2rad(degrees)) , 0,
                            0                    , 0                     , 1];
    
    for( uint8_t i = 0; i < S->numVertexes; i++ )
    {                
        S->vertexes[i] = matmul(struct2Mat(S->vertexes[i]), rotationZ, 1, 3, 3);        
    } 

    return &S;
}


Shape* shape_rotateY( Shape* S, int8_t degrees )
{
    //  self.set_rotation([0,0,degrees])
    // shape_setRotation({});

    /* Z-Axis rotation matrix */
    float rotationY[3*3] = [cos(deg2rad(degrees)),  0, sin(deg2rad(degrees)),
                            0,                      1,                     0,
                            -sin(deg2rad(degrees)), 0, cos(deg2rad(degrees))];
    
    for( uint8_t i = 0; i < S->numVertexes; i++ )
    {                
        S->vertexes[i] = matmul(struct2Mat(S->vertexes[i]), rotationY, 1, 3, 3);        
    } 

    return &S;
}


Shape* shape_rotateX( Shape* S, int8_t degrees )
{
    //  self.set_rotation([0,0,degrees])
    // shape_setRotation({});

    /* Z-Axis rotation matrix */
    float rotationX[3*3] = [1,                     0,                      0,
                            0, cos(deg2rad(degrees)), -sin(deg2rad(degrees)),
                            0, sin(deg2rad(degrees)), cos(deg2rad(degrees))];
    
    for( uint8_t i = 0; i < S->numVertexes; i++ )
    {                
        S->vertexes[i] = matmul(struct2Mat(S->vertexes[i]), rotationX, 1, 3, 3);        
    } 

    return &S;
}
        
Shape* shape_setRotation(Shape* S, Vec3D Rvec_deg)
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