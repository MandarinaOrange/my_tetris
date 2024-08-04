#include "figures.h"
#include <stdio.h>

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12    
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------


int can_move(Figure_location* figure_location, Area* area){
    int result = 1;

    switch (figure_location->figure) {
    case 0:
        int a = area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1] + 1];
        int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1] + 1];
        int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1] + 1];
        int d = area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1] + 1];
        if (!a && !b && !c && !d) result = 0;
        break;
    case 1:
        //int a = area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1]];
        int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1] + 1];
        int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1] + 1];
        int d = area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1] + 1];
        if (!b && !c && !d) result = 0;
        break;
    case 2:
        int a = area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1] + 1];
        int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1] + 1];
        int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1] + 1];
        //int d = area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1]];
        if (!a && !b && !c) result = 0;
        break;
    case 3:
        //int a = area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1]];
        //int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
        int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1] + 1];
        int d = area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1] + 1];
        if (!c && !d) result = 0;
        break;
    case 4:
        int a = area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1] + 1];
        int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1] + 1];
        //int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1] + 1];
        if (!a && !b && !d) result = 0;
        break;
    case 5:
        int a = area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1] + 1];
        int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1] + 1];
        int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1] + 1];
        //int d = area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1]];
        if (!a && !b && !c) result = 0;
        break;
    case 6:
        int a = area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1] + 1];
        //int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
        int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1] + 1];
        int d = area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1] + 1];
        if (!a && !c && !d) result = 0;
        break;
   
    
    default:
        break;
    }

    return result;
}

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12    
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------

int can_move_left_right(int direction, Figure_location* figure_location, Area* area) {
    int result = 1;
    //direction -1 <- left || direction 1 -> right
    switch (figure_location->figure) {
    case 0:
        int a = area->field[figure_location->coordinates[0][0] + direction][figure_location->coordinates[0][1]];
        //int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
        //int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0] + direction][figure_location->coordinates[3][1]];
        if ((direction == -1 && !a) || (direction == 1 && !d)) result = 0;
        break;
    case 1:
        int a = area->field[figure_location->coordinates[0][0] + direction][figure_location->coordinates[0][1]];
        int b = area->field[figure_location->coordinates[1][0] + direction][figure_location->coordinates[1][1]];
        //int c = area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0] + direction][figure_location->coordinates[3][1]];
        if ((direction == -1 && !a && !b) || (direction == 1 && !d && !a)) result = 0;
        break;
    case 2:
        int a = area->field[figure_location->coordinates[0][0] + direction][figure_location->coordinates[0][1]];
        //int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
        int c = area->field[figure_location->coordinates[2][0] + direction][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0] + direction][figure_location->coordinates[3][1]];
        if ((direction == -1 && !a && !d) || (direction == 1 && !c && !d)) result = 0;
        break;
    case 3:
        int a = area->field[figure_location->coordinates[0][0] + direction][figure_location->coordinates[0][1]];
        int b = area->field[figure_location->coordinates[1][0] + direction][figure_location->coordinates[1][1]];
        int c = area->field[figure_location->coordinates[2][0] + direction][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0] + direction][figure_location->coordinates[3][1]];
        if ((direction == -1 && !a && !c) || (direction == 1 && !b && !d)) result = 0;
        break;
    case 4:
        int a = area->field[figure_location->coordinates[0][0] + direction][figure_location->coordinates[0][1]];
        int b = area->field[figure_location->coordinates[1][0] + direction][figure_location->coordinates[1][1]];
        int c = area->field[figure_location->coordinates[2][0] + direction][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0] + direction][figure_location->coordinates[3][1]];
        if ((direction == -1 && !a && !c) || (direction == 1 && !b && !d)) result = 0;
        break;
    case 5:
        int a = area->field[figure_location->coordinates[0][0] + direction][figure_location->coordinates[0][1]];
        //int b = area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
        int c = area->field[figure_location->coordinates[2][0] + direction][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0] + direction][figure_location->coordinates[3][1]];
        if ((direction == -1 && !a && !d) || (direction == 1 && !c && !d)) result = 0;
        break;
    case 6:
        int a = area->field[figure_location->coordinates[0][0] + direction][figure_location->coordinates[0][1]];
        int b = area->field[figure_location->coordinates[1][0] + direction][figure_location->coordinates[1][1]];
        int c = area->field[figure_location->coordinates[2][0] + direction][figure_location->coordinates[2][1]];
        int d = area->field[figure_location->coordinates[3][0] + direction][figure_location->coordinates[3][1]];
        if ((direction == -1 && !a && !c) || (direction == 1 && !b && !d)) result = 0;
        break;
   
    
    default:
        break;
    }

    return result;
}







int move_down(Figure_location* figure_location, Area* area) {

    int result = can_move(figure_location, area);
    if (!result)
    {
        for (int i = 0; i < 4; i++) {
            figure_location->coordinates[i][1]++;
        }
    }
    return result;
}



int move_left(Figure_location* figure_location, Area* area) {
    int result = can_move_left_right(-1, figure_location, area);
    if (!result) {
        for (int i = 0; i < 4; i++) {
            figure_location->coordinates[i][0]--;
        }
    }

    return result;
}


int move_right(Figure_location* figure_location, Area* area) {
    int result = can_move_left_right(1, figure_location, area);
    if (!result) {
        for (int i = 0; i < 4; i++) {
            figure_location->coordinates[i][0]++;
        }
    }

    return result;
}






























