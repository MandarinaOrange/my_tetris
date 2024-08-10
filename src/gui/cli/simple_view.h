#ifndef SIMPLE_VIEW_H
#define SIMPLE_VIEW_H
#include <stdio.h>

#include "../../brick_game/tetris/figures.h"



typedef enum {
    EXIT = 0,
    CONTINUE = 1,
    CHANGE_FIGURE = 2,
    MOVE_DOWN = 3,
    MOVE_LEFT = 4,
    MOVE_RIGHT = 5,

} PlayCode;




void draw_area(Area* area);

#endif