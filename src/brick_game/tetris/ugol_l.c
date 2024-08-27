#include "figures.h"

void start_ugol_l(Figure* figure) {
  figure->coordinates[0][0] = 4;
  figure->coordinates[0][1] = 0;
  figure->coordinates[1][0] = 5;
  figure->coordinates[1][1] = 0;
  figure->coordinates[2][0] = 6;
  figure->coordinates[2][1] = 0;
  figure->coordinates[3][0] = 6;
  figure->coordinates[3][1] = -1;

  figure->rotation = UP;
}

void clean_old_ugol_l_down(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
      area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
          FREE;
      area->field[figure->coordinates[1][0]][figure->coordinates[1][1] - 1] =
          FREE;
      area->field[figure->coordinates[3][0]][figure->coordinates[3][1] - 1] =
          FREE;
      break;
    case RIGHT:
      area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
          FREE;
      area->field[figure->coordinates[3][0]][figure->coordinates[3][1] - 1] =
          FREE;
      break;
    case DOWN:
      area->field[figure->coordinates[0][0]][figure->coordinates[0][1] - 1] =
          FREE;
      area->field[figure->coordinates[1][0]][figure->coordinates[1][1] - 1] =
          FREE;
      area->field[figure->coordinates[2][0]][figure->coordinates[2][1] - 1] =
          FREE;
      break;
    case LEFT:
      area->field[figure->coordinates[2][0]][figure->coordinates[2][1] - 1] =
          FREE;
      area->field[figure->coordinates[3][0]][figure->coordinates[3][1] - 1] =
          FREE;
      break;

    default:
      break;
  }
}

//         4           1                 4 3
//     1 2 3           2       3 2 1       2
//                     3 4     4           1

void clean_old_ugol_l_left(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
      area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]] =
          FREE;
      area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case RIGHT:
      area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case DOWN:
      area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case LEFT:
      area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]] =
          FREE;
      break;

    default:
      break;
  }
}

void clean_old_ugol_l_right(Area* area, Figure* figure) {
  switch (figure->rotation) {
    case UP:
      area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case RIGHT:
      area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]] =
          FREE;
      break;
    case DOWN:
      area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]] =
          FREE;
      area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]] =
          FREE;
      break;
    case LEFT:
      area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]] =
          FREE;
      area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]] =
          FREE;
      area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]] =
          FREE;
      break;

    default:
      break;
  }
}

//         4           1                 4 3
//     1 2 3           2       3 2 1       2
//                     3 4     4           1

void move_left_ugol_l(Area* area, Figure* figure) {
  int code = can_move_left_ugol_l(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]--;
    }
    change_area(area, figure);
    clean_old_ugol_l_left(area, figure);
  }
}

int can_move_left_ugol_l(Area* area, Figure* figure) {
  Color a, b, c;
  int result = 1;
  switch (figure->rotation) {
    case UP:
      a = area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case RIGHT:
      a = area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]];
      c = area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case DOWN:
      a = area->field[figure->coordinates[2][0] - 1][figure->coordinates[2][1]];
      b = area->field[figure->coordinates[3][0] - 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case LEFT:
      a = area->field[figure->coordinates[0][0] - 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[1][0] - 1][figure->coordinates[1][1]];
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

void move_right_ugol_l(Area* area, Figure* figure) {
  int code = can_move_right_ugol_l(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]++;
    }
    change_area(area, figure);
    clean_old_ugol_l_right(area, figure);
  }
}

int can_move_right_ugol_l(Area* area, Figure* figure) {
  Color a, b, c;
  int result = 1;
  switch (figure->rotation) {
    case UP:
      a = area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]];
      b = area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case RIGHT:
      a = area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]];
      c = area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case DOWN:
      a = area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]];
      b = area->field[figure->coordinates[3][0] + 1][figure->coordinates[3][1]];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case LEFT:
      a = area->field[figure->coordinates[1][0] + 1][figure->coordinates[1][1]];
      b = area->field[figure->coordinates[2][0] + 1][figure->coordinates[2][1]];
      c = area->field[figure->coordinates[0][0] + 1][figure->coordinates[0][1]];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;

    default:
      break;
  }
  return result;
}

void move_down_ugol_l(Area* area, Figure* figure) {
  int code = can_move_down_ugol_l(area, figure);

  if (code == 0) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][1]++;
    }
    change_area(area, figure);
    clean_old_ugol_l_down(area, figure);
  }
}

//         4           1                 4 3
//     1 2 3           2       3 2 1       2
//                     3 4     4           1

int can_move_down_ugol_l(Area* area, Figure* figure) {
  Color a, b, c;
  int result = 1;
  switch (figure->rotation) {
    case UP:
      a = area->field[figure->coordinates[1][0]][figure->coordinates[1][1] + 1];
      b = area->field[figure->coordinates[2][0]][figure->coordinates[2][1] + 1];
      c = area->field[figure->coordinates[0][0]][figure->coordinates[0][1] + 1];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case RIGHT:
      a = area->field[figure->coordinates[2][0]][figure->coordinates[2][1] + 1];
      b = area->field[figure->coordinates[3][0]][figure->coordinates[3][1] + 1];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;
    case DOWN:
      a = area->field[figure->coordinates[0][0]][figure->coordinates[0][1] + 1];
      b = area->field[figure->coordinates[1][0]][figure->coordinates[1][1] + 1];
      c = area->field[figure->coordinates[3][0]][figure->coordinates[3][1] + 1];
      if (a == FREE && b == FREE && c == FREE) {
        result = 0;
      }
      break;
    case LEFT:
      a = area->field[figure->coordinates[0][0]][figure->coordinates[0][1] + 1];
      b = area->field[figure->coordinates[3][0]][figure->coordinates[3][1] + 1];
      if (a == FREE && b == FREE) {
        result = 0;
      }
      break;

    default:
      break;
  }
  return result;
}

void rotate_right_ugol_l(Area* area, Figure* figure) {
  Figure test_figure;
  test_figure.rotation = figure->rotation;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      test_figure.coordinates[i][j] = figure->coordinates[i][j];
    }
  }
  test_rotate_right_ugol_l(&test_figure);
  int code = 0;
  /*for (int i = 0; i < 4; i++) {
    if (area->field[test_figure.coordinates[i][0]][test_figure.coordinates[i][1]] != FREE) code = 1;
  }*/

  if (code == 0) {
    clean_rotate(area, figure);
    test_rotate_right_ugol_l(figure);
    change_rotate_right(figure);
    change_area(area, figure);
  }

}

void test_rotate_right_ugol_l(Figure* figure) {
  switch(figure->rotation) {
    case UP:
      figure->coordinates[0][0]++;
      figure->coordinates[0][1]--; 
      figure->coordinates[2][0]--;
      figure->coordinates[2][1]++;
      figure->coordinates[3][1] += 2;
      break;
    case RIGHT:
      figure->coordinates[0][0]++;
      figure->coordinates[0][1]++; 
      figure->coordinates[2][0]--;
      figure->coordinates[2][1]--;
      figure->coordinates[3][0] -= 2; 
      break;
    case DOWN:
      figure->coordinates[0][0]--;
      figure->coordinates[0][1]++; 
      figure->coordinates[2][0]++;
      figure->coordinates[2][1]--;
      figure->coordinates[3][1] -= 2;
      break; 
    case LEFT:
      figure->coordinates[0][0]--;
      figure->coordinates[0][1]--; 
      figure->coordinates[2][0]++;
      figure->coordinates[2][1]++;
      figure->coordinates[3][0] += 2; 
      break;
    default:
      break;
 
  }
}