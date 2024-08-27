#include <ncurses.h>

#include "figures.h"

//после того как изменили координаты нахождения фигурки, нужно поменять цвет
//поля в этих координатах на цвет этой фигурки
void change_area(Area* area, Figure* figure) {
  int a, b, c, d;
  a = figure->coordinates[0][1];
  b = figure->coordinates[1][1];
  c = figure->coordinates[2][1];
  d = figure->coordinates[3][1];
  if (a <= 0 || b <= 0 || c <= 0 || d <= 0) {
    for (int i = 0; i < 4; i++) {
      area->field[figure->coordinates[i][0]][0] = FREE;
    }
  }

  if (a >= 0)
    area->field[figure->coordinates[0][0]][figure->coordinates[0][1]] =
        figure->color;
  if (b >= 0)
    area->field[figure->coordinates[1][0]][figure->coordinates[1][1]] =
        figure->color;
  if (c >= 0)
    area->field[figure->coordinates[2][0]][figure->coordinates[2][1]] =
        figure->color;
  if (d >= 0)
    area->field[figure->coordinates[3][0]][figure->coordinates[3][1]] =
        figure->color;

  if (a == 2 || b == 2 || c == 2 || d == 2) {
    for (int i = 0; i < area->x; i++) {
      area->field[i][0] = BORTIK;
      area->field[i][area->y - 1] = BORTIK;
    }
    for (int i = 0; i < area->y; i++) {
      area->field[0][i] = BORTIK;
      area->field[area->x - 1][i] = BORTIK;
    }
  }
}

void start_area(Area* area) {
  area->x = 12;
  area->y = 22;
  for (int i = 0; i < area->x; i++) {
    area->field[i][0] = BORTIK;
    area->field[i][area->y - 1] = BORTIK;
  }
  for (int i = 0; i < area->y; i++) {
    area->field[0][i] = BORTIK;
    area->field[area->x - 1][i] = BORTIK;
  }
  for (int i = 1; i < area->x - 1; i++) {
    for (int j = 1; j < area->y - 1; j++) {
      area->field[i][j] = FREE;
    }
  }
}

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------
void start_coordinates(Figure* figure) {
  figure->rotation = UP;
  figure->color = VIOLET;
  switch (figure->type) {
    case PALKA:
      start_palka(figure);
      break;
    case UGOL_G:
      start_ugol_g(figure);
      break;
    case UGOL_L:
      start_ugol_l(figure);
      break;
    case KVADRAT:
      start_kvadrat(figure);
      break;
    case VVERH:
      start_vverh(figure);
      break;
    case FUCK:
      start_fuck(figure);
      break;
    case VNIZ:
      start_vniz(figure);
      break;

    default:
      break;
  }
}

void move_down(Area* area, Figure* figure) {
  switch (figure->type) {
    case PALKA:
      move_down_palka(area, figure);
      break;
    case UGOL_G:
      move_down_ugol_g(area, figure);
      break;
    case UGOL_L:
      move_down_ugol_l(area, figure);
      break;
    case KVADRAT:
      move_down_kvadrat(area, figure);
      break;
    case VVERH:
      move_down_vverh(area, figure);
      break;
    case FUCK:
      move_down_fuck(area, figure);
      break;
    case VNIZ:
      move_down_vniz(area, figure);
      break;
    default:
      break;
  }
}

void move_left(Area* area, Figure* figure) {
  switch (figure->type) {
    case PALKA:
      move_left_palka(area, figure);
      break;
    case UGOL_G:
      move_left_ugol_g(area, figure);
      break;
    case UGOL_L:
      move_left_ugol_l(area, figure);
      break;
    case KVADRAT:
      move_left_kvadrat(area, figure);
      break;
    case VVERH:
      move_left_vverh(area, figure);
      break;
    case FUCK:
      move_left_fuck(area, figure);
      break;
    case VNIZ:
      move_left_vniz(area, figure);
      break;
    default:
      break;
  }
}

void move_right(Area* area, Figure* figure) {
  switch (figure->type) {
    case PALKA:
      move_right_palka(area, figure);
      break;
    case UGOL_G:
      move_right_ugol_g(area, figure);
      break;
    case UGOL_L:
      move_right_ugol_l(area, figure);
      break;
    case KVADRAT:
      move_right_kvadrat(area, figure);
      break;
    case VVERH:
      move_right_vverh(area, figure);
      break;
    case FUCK:
      move_right_fuck(area, figure);
      break;
    case VNIZ:
      move_right_vniz(area, figure);
      break;
    default:
      break;
  }
}

void change_rotate_right(Figure* figure) {
  switch (figure->rotation) {
    case UP:
      figure->rotation = RIGHT;
      break;
    case RIGHT:
      figure->rotation = DOWN;
      break;
    case DOWN:
      figure->rotation = LEFT;
      break;
    case LEFT:
      figure->rotation = UP;
      break;

    default:
      break;
  }
}

void change_rotate_left(Figure* figure) {
  switch (figure->rotation) {
    case UP:
      figure->rotation = LEFT;
      break;
    case LEFT:
      figure->rotation = DOWN;
      break;
    case DOWN:
      figure->rotation = RIGHT;
      break;
    case RIGHT:
      figure->rotation = UP;
      break;

    default:
      break;
  }
}

// делаем тестовую фигуру, чтобы посмотреть, не впишется ли она во что-то (в
// текстуру)
void rotate_right(Area* area, Figure* figure) {
  switch (figure->type) {
  case PALKA:
    rotate_right_palka(area, figure);
    break;
  case UGOL_G:
    rotate_right_ugol_g(area, figure);
    break;
  case UGOL_L:
    rotate_right_ugol_l(area, figure);
    break;
  case KVADRAT:
    break;
  case VVERH:
    rotate_right_vverh(area, figure);
    break;
  case FUCK:
    rotate_right_fuck(area, figure);
    break;
  case VNIZ:
    rotate_right_vniz(area, figure);
    break;
  default:
    break;
}
}
void clean_rotate(Area* area, Figure* figure) {
  for (int i = 0; i < 4; i++) { 
    area->field[figure->coordinates[i][0]][figure->coordinates[i][1]] = FREE;
  }
}

