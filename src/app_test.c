#include <stdio.h>
#include "brick_game/tetris/figures.h"
#include "gui/cli/simple_view.h"




int main() {

    PlayCode code = 1;
    Figure figure = 0;
    int area_x = 10;
    int area_y = 20;
    
    Area area;
    area.x = area_x;
    area.y = area_y;
    start_area(&area);

    Figure_location figure_location;
    figure_location.color = VIOLET;


    while (code != EXIT) {
        if (code == CHANGE_FIGURE) {
            scanf("%d", &figure);
            figure_location.figure = figure;
            start_coordinates(&figure_location);
        }

        if (code == DOWN) {
            code = 1 + move_down(&figure_location, &area);
        } else if (code == LEFT) {
            code = 1 + move_left(&figure_location, &area);
        } else if (code == RIGHT) {
            code = 1 + move_right(&figure_location, &area);
        } 

        change_area(&area, &figure_location);
        draw_area(&area);

        scanf("%d", &code);

    }
    


    return 0;
}