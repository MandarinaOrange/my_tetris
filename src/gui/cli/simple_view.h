#ifndef SIMPLE_VIEW_H
#define SIMPLE_VIEW_H
#include <stdio.h>

#include "../../brick_game/tetris/figures.h"



typedef enum {
    EXIT = 0,
    CONTINUE = 1,
    CHANGE_FIGURE = 2,
    DOWN = 3,
    LEFT = 4,
    RIGHT = 5,

} PlayCode;




void draw_area(Area* area);

#endif