#include <stdio.h>
#include "brick_game/tetris/figures.h"
#include "gui/cli/simple_view.h"




int main() {
    int help;
    PlayCode code = 1;
    Figure figure = 0;
    int area_x = 12;
    int area_y = 22;
    
    Area area;
    area.x = area_x;
    area.y = area_y;
    start_area(&area);

    Figure_location figure_location;
    figure_location.color = VIOLET;
    figure_location.figure = PALKA;
    start_coordinates(&figure_location);

    draw_area(&area);


    while (code != EXIT) {
        printf("OK\n");
        if (code == CHANGE_FIGURE) {
            scanf("%d", &help);
            figure = help;
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

        //change_area(&area, &figure_location);
        draw_area(&area);

        scanf("%d", &help);
        code = help;
    }
    


    return 0;
}