#include "figures.h"

void start_palka(Figure* figure) {
  figure->coordinates[0][0] = 3;
  figure->coordinates[0][1] = 0;
  figure->coordinates[1][0] = 4;
  figure->coordinates[1][1] = 0;
  figure->coordinates[2][0] = 5;
  figure->coordinates[2][1] = 0;
  figure->coordinates[3][0] = 6;
  figure->coordinates[3][1] = 0;

  figure->rotation = UP;
  
}

void clean_old_palka_down(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
    case DOWN:
      for (int i = 0; i < 4; i++) {
        if (figure->coordinates[0][1] == 1) {
          area->field[figure->coordinates[i][0]]
                     [figure->coordinates[i][1] - 1] = BORTIK;
        } else {
          area->field[figure->coordinates[i][0]]
                     [figure->coordinates[i][1] - 1] = FREE;
        }
      }
      break;
    case RIGHT:
    case LEFT:
      if (figure->coordinates[0][1] == 1) {
        area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
            BORTIK;
      } else {
        area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
            FREE;
      }
      break;

    default:
      break;
  }
}

void clean_old_palka_left(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
    case DOWN:
      area->field[figure->coordinates[3][0]+1][figure->coordinates[3][1]] = FREE;
      break;
    case RIGHT:
    case LEFT:
    for (int i = 0; i < 4; i++) {
      area->field[figure->coordinates[i][0]+1][figure->coordinates[i][1]] = FREE;
    }
      break;

    default:
      break;
  }
}

void clean_old_palka_right(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
    case DOWN:
      area->field[figure->coordinates[0][0]-1][figure->coordinates[0][1]] = FREE;
      break;
    case RIGHT:
    case LEFT:
    for (int i = 0; i < 4; i++) {
      area->field[figure->coordinates[i][0]-1][figure->coordinates[i][1]] = FREE;
    }
      break;

    default:
      break;
  }
}

//    1
//    2     1 2 3 4
//    3
//    4

void move_left_palka(Area* area, Figure* figure) {
  int code = can_move_left_palka(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      (figure->coordinates[i][0])--;
    }
    change_area(area, figure);
    clean_old_palka_left(area, figure);
  }
}

int can_move_left_palka(Area* area, Figure* figure) {
  int result = 1;
  Color a;

  switch (figure->rotation) {
    case UP:
    case DOWN:
      a =
          area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      if (a == FREE) result = 0;
      break;
    case RIGHT:
    case LEFT:
      a =
          area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      Color b =
          area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]];
      Color c =
          area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]];
      Color d =
          area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]];
      if (!a && !b && !c && !d) result = 0;
      break;

    default:
      break;
  }

  return result;
}

void move_right_palka(Area* area, Figure* figure) {
  int code = can_move_right_palka(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]++;
    }
    change_area(area, figure);
    clean_old_palka_right(area, figure);
  }
}

int can_move_right_palka(Area* area, Figure* figure) {
  int result = 1;
  Color a;

  switch (figure->rotation) {
    case UP:
    case DOWN:
      a =
          area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (a == FREE) result = 0;
      break;
    case RIGHT:
    case LEFT:
      a =
          area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]];
      Color b =
          area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]];
      Color c =
          area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]];
      Color d =
          area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (!a && !b && !c && !d) result = 0;
      break;

    default:
      break;
  }

  return result;
}

int move_down_palka(Area* area, Figure* figure) {
  int code = can_move_down_palka(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      (figure->coordinates[i][1])++;
    }
    change_area(area, figure);
    clean_old_palka_down(area, figure);
  }
  return code;
}

int can_move_down_palka(Area* area, Figure* figure) {
  int result = 1;


  switch (figure->rotation) {
    Color a;
    case RIGHT:
    case LEFT:
      a =
          area->field[figure->coordinates[3][0]][figure->coordinates[3][1]+1];
      if (a == FREE) result = 0;
      break;
    case UP:
    case DOWN:
      a =
          area->field[figure->coordinates[0][0]][figure->coordinates[0][1]+1];
      Color b =
          area->field[figure->coordinates[1][0]][figure->coordinates[1][1]+1];
      Color c =
          area->field[figure->coordinates[2][0]][figure->coordinates[2][1]+1];
      Color d =
          area->field[figure->coordinates[3][0]][figure->coordinates[3][1]+1];
      if (!a && !b && !c && !d) result = 0;
      break;

    default:
      break;
  }

  return result;
}

