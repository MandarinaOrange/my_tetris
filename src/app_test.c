#include <stdio.h>
#include "brick_game/tetris/figures.h"
#include "gui/cli/simple_view.h"




int main() {
    int help;
    PlayCode code = 1;
    int area_x = 12;
    int area_y = 22;
    

    Figure figure;
    figure.type = PALKA;
    figure.color = VIOLET;
    figure.rotation = UP;
    start_coordinates(&figure);

    Area area;
    area.x = 12;
    area.y = 22;
    start_area(&area);
    start_palka(&figure);
    change_area(&area, &figure);
    draw_area(&area);


    while (code != EXIT) {
        printf("OK\n");
        if (code == CHANGE_FIGURE) {
            scanf("%d", &help);
            figure.type = help;
            start_palka(&figure);
            change_area(&area, &figure);
        }

        if (code == MOVE_DOWN) {
            move_down_palka(&area, &figure);
        } else if (code == MOVE_LEFT) {
            move_left_palka(&area, &figure);
        } else if (code == MOVE_RIGHT) {
            move_right_palka(&area, &figure);
        } 

        //change_area(&area, &figure_location);
        draw_area(&area);

        scanf("%d", &code);
        //code = help;
    }
    


    return 0;
}