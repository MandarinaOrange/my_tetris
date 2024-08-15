#include <stdio.h>
#include "brick_game/tetris/figures.h"
#include "gui/cli/simple_view.h"




int main() {
    int help;
    PlayCode code = 1;
    int area_x = 12;
    int area_y = 22;
    

    Figure figure;
    figure.type = KVADRAT;
    figure.color = VIOLET;
    figure.rotation = UP;
    start_coordinates(&figure);

    Area area;
    area.x = 12;
    area.y = 22;
    start_area(&area);
    start_coordinates(&figure);
    change_area(&area, &figure);
    draw_area(&area);


    while (code != EXIT) {
        printf("OK\n");
        if (code == CHANGE_FIGURE) {
            scanf("%d", &help);
            figure.type = help;
            start_coordinates(&figure);
            change_area(&area, &figure);
        }

        if (code == MOVE_DOWN) {
            move_down(&area, &figure);
        } else if (code == MOVE_LEFT) {
            move_left(&area, &figure);
        } else if (code == MOVE_RIGHT) {
            move_right(&area, &figure);
        } 

        //change_area(&area, &figure_location);
        draw_area(&area);

        scanf("%d", &code);
        scanf("%c", &help);
    }
    


    return 0;
}