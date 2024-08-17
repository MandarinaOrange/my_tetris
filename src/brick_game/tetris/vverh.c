#include "figures.h"

void start_vverh(Figure* figure) {
  figure->coordinates[0][0] = 4;
  figure->coordinates[0][1] = 0;
  figure->coordinates[1][0] = 5;
  figure->coordinates[1][1] = 0;
  figure->coordinates[2][0] = 5;
  figure->coordinates[2][1] = -1;
  figure->coordinates[3][0] = 6;
  figure->coordinates[3][1] = -1;

  figure->rotation = UP;
}

void clean_old_vverh_down(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
      area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
          FREE;
      area->field[figure->coordinates[2][0]][figure->coordinates[2][1] - 1] =
          FREE;
      area->field[figure->coordinates[3][0]][figure->coordinates[3][1] - 1] =
          FREE;
      break;
    case RIGHT:
      area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
          FREE;
      area->field[figure->coordinates[2][0]][figure->coordinates[2][1] - 1] =
          FREE;
      break;
    case DOWN:
      area->field[figure->coordinates[1][0]][figure->coordinates[1][1] - 1] =
          FREE;
      area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
          FREE;
      area->field[figure->coordinates[3][0]][figure->coordinates[3][1] - 1] =
          FREE;
      break;
    case LEFT:
      area->field[figure->coordinates[1][0]][figure->coordinates[1][1] - 1] =
          FREE;
      area->field[figure->coordinates[3][0]][figure->coordinates[3][1] - 1] =
          FREE;
      break;

    default:
      break;
  }
}

//       2 3          0           1 0        3
//     0 1            1 2       3 2          2 1
//                      3                      0

void clean_old_vverh_left(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
      area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case RIGHT:
      area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]] =
          FREE;
      area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case DOWN:
      area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]] =
          FREE;
      break;
    case LEFT:
      area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]] =
          FREE;
      break;

    default:
      break;
  }
}

void clean_old_vverh_right(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
      area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]] =
          FREE;
      break;
    case RIGHT:
      area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case DOWN:
      area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case LEFT:
      area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]] =
          FREE;
      area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]] =
          FREE;
      break;

    default:
      break;
  }
}

void move_left_vverh(Area* area, Figure* figure) {
  int code = can_move_left_vverh(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]--;
    }
    change_area(area, figure);
    clean_old_vverh_left(area, figure);
  }
}

int can_move_left_vverh(Area* area, Figure* figure) {
  Color a, b, c;
  int result = 1;
  switch (figure->rotation) {
    case UP:
      a = area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case RIGHT:
      a = area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]];
      b = area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      c = area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case DOWN:
      a = area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]];
      b = area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case LEFT:
      a = area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]];
      c = area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;

    default:
      break;
  }
  return result;
}

//       2 3          0           1 0        3
//     0 1            1 2       3 2          2 1
//                      3                      0

void move_right_vverh(Area* area, Figure* figure) {
  int code = can_move_right_vverh(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]++;
    }
    change_area(area, figure);
    clean_old_vverh_right(area, figure);
  }
}

int can_move_right_vverh(Area* area, Figure* figure) {
  Color a, b, c;
  int result = 1;
  switch (figure->rotation) {
    case UP:
      a = area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]];
      b = area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case RIGHT:
      a = area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]];
      c = area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case DOWN:
      a = area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case LEFT:
      a = area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]];
      b = area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]];
      c = area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;

    default:
      break;
  }
  return result;
}

void move_down_vverh(Area* area, Figure* figure) {
  int code = can_move_down_vverh(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][1]++;
    }
    change_area(area, figure);
    clean_old_vverh_down(area, figure);
  }
}

int can_move_down_vverh(Area* area, Figure* figure) {
  Color a, b, c;
  int result = 1;
  switch (figure->rotation) {
    case UP:
      a = area->field[figure->coordinates[1][0]][figure->coordinates[1][1] + 1];
      b = area->field[figure->coordinates[0][0]][figure->coordinates[0][1] + 1];
      c = area->field[figure->coordinates[3][0]][figure->coordinates[3][1] + 1];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case RIGHT:
      a = area->field[figure->coordinates[1][0]][figure->coordinates[1][1] + 1];
      b = area->field[figure->coordinates[3][0]][figure->coordinates[3][1] + 1];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case DOWN:
      a = area->field[figure->coordinates[0][0]][figure->coordinates[0][1] + 1];
      b = area->field[figure->coordinates[2][0]][figure->coordinates[2][1] + 1];
      c = area->field[figure->coordinates[3][0]][figure->coordinates[3][1] + 1];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case LEFT:
      a = area->field[figure->coordinates[0][0]][figure->coordinates[0][1] + 1];
      b = area->field[figure->coordinates[2][0]][figure->coordinates[2][1] + 1];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;

    default:
      break;
  }
  return result;
}
//       2 3          0           1 0        3
//     0 1            1 2       3 2          2 1
//                      3                      0