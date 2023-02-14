#ifndef MAIN_H
#define MAIN_H

#define WINDOW_WIDTH        1000
#define WINDOW_HEIGHT       1000
#define WINDOW_MIDDLE_X     WINDOW_WIDTH / 2
#define WINDOW_MIDDLE_Y     WINDOW_HEIGHT / 2

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