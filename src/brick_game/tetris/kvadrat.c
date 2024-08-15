#include "figures.h"

void start_kvadrat(Figure* figure) {
  figure->coordinates[0][0] = 4;
  figure->coordinates[0][1] = -1;
  figure->coordinates[1][0] = 5;
  figure->coordinates[1][1] = -1;
  figure->coordinates[2][0] = 4;
  figure->coordinates[2][1] = 0;
  figure->coordinates[3][0] = 5;
  figure->coordinates[3][1] = 0;

  figure->rotation = UP;
}

//         0 1
//         2 3

void clean_old_kvadrat_down(Area* area, Figure* figure) {
  area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] = FREE;
  area->field[figure->coordinates[1][0]][figure->coordinates[1][1] - 1] = FREE;
}

void clean_old_kvadrat_left(Area* area, Figure* figure) {
  area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]] = FREE;
  area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]] = FREE;
}

void clean_old_kvadrat_right(Area* area, Figure* figure) {
  area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]] = FREE;
  area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]] = FREE;
}

void move_left_kvadrat(Area* area, Figure* figure) {
  int code = can_move_left_kvadrat(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]--;
    }
    change_area(area, figure);
    clean_old_kvadrat_left(area, figure);
  }
}

int can_move_left_kvadrat(Area* area, Figure* figure) {
  Color a, b;
  int result = 1;

  a = area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
  b = area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]];
  if (a == FREE && b == FREE) {
    result = 0;
  }

  return result;
}

//         0 1
//         2 3

void move_right_kvadrat(Area* area, Figure* figure) {
  int code = can_move_right_kvadrat(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]++;
    }
    change_area(area, figure);
    clean_old_kvadrat_right(area, figure);
  }
}

int can_move_right_kvadrat(Area* area, Figure* figure) {
  Color a, b;
  int result = 1;

  a = area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]];
  b = area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
  if (a == FREE && b == FREE) {
    result = 0;
  }

  return result;
}

void move_down_kvadrat(Area* area, Figure* figure) {
  int code = can_move_down_kvadrat(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][1]++;
    }
    change_area(area, figure);
    clean_old_kvadrat_down(area, figure);
  }
}

int can_move_down_kvadrat(Area* area, Figure* figure) {
  Color a, b;
  int result = 1;

  a = area->field[figure->coordinates[2][0]][figure->coordinates[2][1] + 1];
  b = area->field[figure->coordinates[3][0]][figure->coordinates[3][1] + 1];
  if (a == FREE && b == FREE) {
    result = 0;
  }
}