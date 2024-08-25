#include "figures.h"

#include <stdio.h>

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------

int can_move(Figure* figure_location, Area* area) {
  int result = 1;
  int a, b, c, d;

  switch (figure_location->type) {
    case 0:
      a = area->field[figure_location->coordinates[0][0]]
                     [figure_location->coordinates[0][1] + 1];
      b = area->field[figure_location->coordinates[1][0]]
                     [figure_location->coordinates[1][1] + 1];
      c = area->field[figure_location->coordinates[2][0]]
                     [figure_location->coordinates[2][1] + 1];
      d = area->field[figure_location->coordinates[3][0]]
                     [figure_location->coordinates[3][1] + 1];
      if (!a && !b && !c && !d) result = 0;
      break;
    case 1:
      // int a =
      // area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1]];
      b = area->field[figure_location->coordinates[1][0]]
                     [figure_location->coordinates[1][1] + 1];
      c = area->field[figure_location->coordinates[2][0]]
                     [figure_location->coordinates[2][1] + 1];
      d = area->field[figure_location->coordinates[3][0]]
                     [figure_location->coordinates[3][1] + 1];
      if (!b && !c && !d) result = 0;
      break;
    case 2:
      a = area->field[figure_location->coordinates[0][0]]
                     [figure_location->coordinates[0][1] + 1];
      b = area->field[figure_location->coordinates[1][0]]
                     [figure_location->coordinates[1][1] + 1];
      c = area->field[figure_location->coordinates[2][0]]
                     [figure_location->coordinates[2][1] + 1];
      // int d =
      // area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1]];
      if (!a && !b && !c) result = 0;
      break;
    case 3:
      // int a =
      // area->field[figure_location->coordinates[0][0]][figure_location->coordinates[0][1]];
      // int b =
      // area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
      c = area->field[figure_location->coordinates[2][0]]
                     [figure_location->coordinates[2][1] + 1];
      d = area->field[figure_location->coordinates[3][0]]
                     [figure_location->coordinates[3][1] + 1];
      if (!c && !d) result = 0;
      break;
    case 4:
      a = area->field[figure_location->coordinates[0][0]]
                     [figure_location->coordinates[0][1] + 1];
      b = area->field[figure_location->coordinates[1][0]]
                     [figure_location->coordinates[1][1] + 1];
      // int c =
      // area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0]]
                     [figure_location->coordinates[3][1] + 1];
      if (!a && !b && !d) result = 0;
      break;
    case 5:
      a = area->field[figure_location->coordinates[0][0]]
                     [figure_location->coordinates[0][1] + 1];
      b = area->field[figure_location->coordinates[1][0]]
                     [figure_location->coordinates[1][1] + 1];
      c = area->field[figure_location->coordinates[2][0]]
                     [figure_location->coordinates[2][1] + 1];
      // int d =
      // area->field[figure_location->coordinates[3][0]][figure_location->coordinates[3][1]];
      if (!a && !b && !c) result = 0;
      break;
    case 6:
      a = area->field[figure_location->coordinates[0][0]]
                     [figure_location->coordinates[0][1] + 1];
      // int b =
      // area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
      c = area->field[figure_location->coordinates[2][0]]
                     [figure_location->coordinates[2][1] + 1];
      d = area->field[figure_location->coordinates[3][0]]
                     [figure_location->coordinates[3][1] + 1];
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

int can_move_left_right(int direction, Figure* figure_location, Area* area) {
  int result = 1;
  // direction -1 <- left || direction 1 -> right
  int a, b, c, d;
  switch (figure_location->type) {
    case 0:
      a = area->field[figure_location->coordinates[0][0] + direction]
                     [figure_location->coordinates[0][1]];
      // int b =
      // area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
      // int c =
      // area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0] + direction]
                     [figure_location->coordinates[3][1]];
      if ((direction == -1 && !a) || (direction == 1 && !d)) result = 0;
      break;
    case 1:
      a = area->field[figure_location->coordinates[0][0] + direction]
                     [figure_location->coordinates[0][1]];
      b = area->field[figure_location->coordinates[1][0] + direction]
                     [figure_location->coordinates[1][1]];
      // int c =
      // area->field[figure_location->coordinates[2][0]][figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0] + direction]
                     [figure_location->coordinates[3][1]];
      if ((direction == -1 && !a && !b) || (direction == 1 && !d && !a))
        result = 0;
      break;
    case 2:
      a = area->field[figure_location->coordinates[0][0] + direction]
                     [figure_location->coordinates[0][1]];
      // int b =
      // area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
      c = area->field[figure_location->coordinates[2][0] + direction]
                     [figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0] + direction]
                     [figure_location->coordinates[3][1]];
      if ((direction == -1 && !a && !d) || (direction == 1 && !c && !d))
        result = 0;
      break;
    case 3:
      a = area->field[figure_location->coordinates[0][0] + direction]
                     [figure_location->coordinates[0][1]];
      b = area->field[figure_location->coordinates[1][0] + direction]
                     [figure_location->coordinates[1][1]];
      c = area->field[figure_location->coordinates[2][0] + direction]
                     [figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0] + direction]
                     [figure_location->coordinates[3][1]];
      if ((direction == -1 && !a && !c) || (direction == 1 && !b && !d))
        result = 0;
      break;
    case 4:
      a = area->field[figure_location->coordinates[0][0] + direction]
                     [figure_location->coordinates[0][1]];
      b = area->field[figure_location->coordinates[1][0] + direction]
                     [figure_location->coordinates[1][1]];
      c = area->field[figure_location->coordinates[2][0] + direction]
                     [figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0] + direction]
                     [figure_location->coordinates[3][1]];
      if ((direction == -1 && !a && !c) || (direction == 1 && !b && !d))
        result = 0;
      break;
    case 5:
      a = area->field[figure_location->coordinates[0][0] + direction]
                     [figure_location->coordinates[0][1]];
      // int b =
      // area->field[figure_location->coordinates[1][0]][figure_location->coordinates[1][1]];
      c = area->field[figure_location->coordinates[2][0] + direction]
                     [figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0] + direction]
                     [figure_location->coordinates[3][1]];
      if ((direction == -1 && !a && !d) || (direction == 1 && !c && !d))
        result = 0;
      break;
    case 6:
      a = area->field[figure_location->coordinates[0][0] + direction]
                     [figure_location->coordinates[0][1]];
      b = area->field[figure_location->coordinates[1][0] + direction]
                     [figure_location->coordinates[1][1]];
      c = area->field[figure_location->coordinates[2][0] + direction]
                     [figure_location->coordinates[2][1]];
      d = area->field[figure_location->coordinates[3][0] + direction]
                     [figure_location->coordinates[3][1]];
      if ((direction == -1 && !a && !c) || (direction == 1 && !b && !d))
        result = 0;
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

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------
