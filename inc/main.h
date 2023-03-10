#ifndef MAIN_H
#define MAIN_H

#include <math.h>


#define WINDOW_WIDTH        1000
#define WINDOW_HEIGHT       1000
#define WINDOW_MIDDLE_X     WINDOW_WIDTH / 2
#define WINDOW_MIDDLE_Y     WINDOW_HEIGHT / 2

#define PROJ_ASPECT_RATIO   (float)WINDOW_HEIGHT / (float)WINDOW_WIDTH
#define PROJ_FAR            1000.0f
#define PROJ_NEAR           0.1f
#define PROJ_FOV            90.0f
#define PROJ_FOV_RAD        1.0f / tanf(PROJ_FOV * 0.5f / 180.0f * M_PI)


#define PIXEL_ALIGNMENT_X   WINDOW_MIDDLE_X
#define PIXEL_ALIGNMENT_Y   WINDOW_MIDDLE_Y

#define R_MASK              32
#define G_MASK              16
#define B_MASK              8
#define A_MASK              0

#define BACKGROUND_COLOUR   COLOUR_BLACK

#define WINDOW_FPS          60.0
#define WINDOW_TICK_MS      (1.0 / WINDOW_FPS ) * 1000

#define COLOUR_BLACK        0xFFFFFFFF
#define BACKGROUND_R        0x00
#define BACKGROUND_G        0x00
#define BACKGROUND_B        0x00
#define BACKGROUND_A        0x00

#endif