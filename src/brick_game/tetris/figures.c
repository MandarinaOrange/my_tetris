#include "figures.h"

#include <stdio.h>

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------

int can_move(Figure_location* figure_location, Area* area) {
  int result = 1;
    int a, b, c, d;

  switch (figure_location->figure) {
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

int can_move_left_right(int direction, Figure_location* figure_location,
                        Area* area) {
  int result = 1;
  // direction -1 <- left || direction 1 -> right
  int a, b, c, d;
  switch (figure_location->figure) {
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

int move_down(Figure_location* figure_location, Area* area) {
  int result = can_move(figure_location, area);


  if (!result) {
    for (int i = 0; i < 4; i++) {
      figure_location->coordinates[i][1]++;
    }
  }
  change_area(area, figure_location);
  clean_old_down(area, figure_location);
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

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------
void start_coordinates(Figure_location* figure_location) {
  switch (figure_location->figure) {
    case PALKA:
      figure_location->coordinates[0][0] = 3;
      figure_location->coordinates[0][1] = 0;
      figure_location->coordinates[1][0] = 4;
      figure_location->coordinates[1][1] = 0;
      figure_location->coordinates[2][0] = 5;
      figure_location->coordinates[2][1] = 0;
      figure_location->coordinates[3][0] = 6;
      figure_location->coordinates[3][1] = 0;
      break;
    case UGOL_G:
      figure_location->coordinates[0][0] = 3;
      figure_location->coordinates[0][1] = -1;
      figure_location->coordinates[1][0] = 3;
      figure_location->coordinates[1][1] = 0;
      figure_location->coordinates[2][0] = 4;
      figure_location->coordinates[2][1] = 0;
      figure_location->coordinates[3][0] = 5;
      figure_location->coordinates[3][1] = 0;
      break;
    case UGOL_L:
      figure_location->coordinates[0][0] = 3;
      figure_location->coordinates[0][1] = 0;
      figure_location->coordinates[1][0] = 4;
      figure_location->coordinates[1][1] = 0;
      figure_location->coordinates[2][0] = 5;
      figure_location->coordinates[2][1] = 0;
      figure_location->coordinates[3][0] = 5;
      figure_location->coordinates[3][1] = -1;
      break;
    case KVADRAT:
      figure_location->coordinates[0][0] = 3;
      figure_location->coordinates[0][1] = -1;
      figure_location->coordinates[1][0] = 4;
      figure_location->coordinates[1][1] = -1;
      figure_location->coordinates[2][0] = 3;
      figure_location->coordinates[2][1] = 0;
      figure_location->coordinates[3][0] = 4;
      figure_location->coordinates[3][1] = 0;
      break;
    case VVERH:
      figure_location->coordinates[0][0] = 3;
      figure_location->coordinates[0][1] = 0;
      figure_location->coordinates[1][0] = 4;
      figure_location->coordinates[1][1] = 0;
      figure_location->coordinates[2][0] = 4;
      figure_location->coordinates[2][1] = -1;
      figure_location->coordinates[3][0] = 5;
      figure_location->coordinates[3][1] = -1;
      break;
    case FUCK:
      figure_location->coordinates[0][0] = 3;
      figure_location->coordinates[0][1] = 0;
      figure_location->coordinates[1][0] = 4;
      figure_location->coordinates[1][1] = 0;
      figure_location->coordinates[2][0] = 5;
      figure_location->coordinates[2][1] = 0;
      figure_location->coordinates[3][0] = 4;
      figure_location->coordinates[3][1] = -1;
      break;
    case VNIZ:
      figure_location->coordinates[0][0] = 3;
      figure_location->coordinates[0][1] = -1;
      figure_location->coordinates[1][0] = 4;
      figure_location->coordinates[1][1] = -1;
      figure_location->coordinates[2][0] = 4;
      figure_location->coordinates[2][1] = 0;
      figure_location->coordinates[3][0] = 5;
      figure_location->coordinates[3][1] = 0;
      break;

    default:
      break;
  }
}

void start_area(Area* area) {

  for (int i = 0; i < area->x; i++) {
    area->field[i][0] = BORTIK;
    area->field[i][area->y-1] = BORTIK;
  }
  for (int i = 0; i < area->y; i++) {
    area->field[0][i] = BORTIK;
    area->field[area->x-1][i] = BORTIK;
  }
  for (int i = 1; i < area->x-1; i++) {
    for (int j = 1; j < area->y-1; j++) {
      area->field[i][j] = FREE;
    }
  }
}



//после того как изменили координаты нахождения фигурки, нужно поменять цвет поля в этих координатах на цвет этой фигурки
void change_area(Area* area, Figure_location* figure_location) {
  area->field[figure_location->coordinates[0][0]]
             [figure_location->coordinates[0][1]] = figure_location->color;
  area->field[figure_location->coordinates[1][0]]
             [figure_location->coordinates[1][1]] = figure_location->color;
  area->field[figure_location->coordinates[2][0]]
             [figure_location->coordinates[2][1]] = figure_location->color;
  area->field[figure_location->coordinates[3][0]]
             [figure_location->coordinates[3][1]] = figure_location->color;
}

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------
void clean_old_down(Area* area, Figure_location* figure) {
  switch (figure->figure)
  {
  case PALKA:
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[1][0]][figure->coordinates[1][1]-1] = FREE;
    area->field[figure->coordinates[2][0]][figure->coordinates[2][1]-1] = FREE;
    area->field[figure->coordinates[3][0]][figure->coordinates[3][1]-1] = FREE;
    break;
  case UGOL_G:
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[2][0]][figure->coordinates[2][1]-1] = FREE;
    area->field[figure->coordinates[3][0]][figure->coordinates[3][1]-1] = FREE;
    break;
  case UGOL_L:
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[1][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[3][0]][figure->coordinates[3][1]-1] = FREE;
    break;
  case KVADRAT:
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[1][0]][figure->coordinates[1][1]-1] = FREE;
    break;
  case VVERH:
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[2][0]][figure->coordinates[2][1]-1] = FREE;
    area->field[figure->coordinates[3][0]][figure->coordinates[3][1]-1] = FREE;
    break;
  case FUCK:
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[2][0]][figure->coordinates[2][1]-1] = FREE;
    area->field[figure->coordinates[3][0]][figure->coordinates[3][1]-1] = FREE;
    break;
  case VNIZ:
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]-1] = FREE;
    area->field[figure->coordinates[1][0]][figure->coordinates[1][1]-1] = FREE;
    area->field[figure->coordinates[3][0]][figure->coordinates[3][1]-1] = FREE;
    break;
  default:
    break;
  }
}