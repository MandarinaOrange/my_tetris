#include "figures.h"

//после того как изменили координаты нахождения фигурки, нужно поменять цвет
//поля в этих координатах на цвет этой фигурки
void change_area(Area* area, Figure* figure) {
  area->field[figure->coordinates[0][0]][figure->coordinates[0][1]] =
      figure->color;
  area->field[figure->coordinates[1][0]][figure->coordinates[1][1]] =
      figure->color;
  area->field[figure->coordinates[2][0]][figure->coordinates[2][1]] =
      figure->color;
  area->field[figure->coordinates[3][0]][figure->coordinates[3][1]] =
      figure->color;
}

void start_area(Area* area) {
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
  switch (figure->type) {
    case PALKA:
      start_palka(figure);
      break;
    case UGOL_G:
      figure->coordinates[0][0] = 3;
      figure->coordinates[0][1] = -1;
      figure->coordinates[1][0] = 3;
      figure->coordinates[1][1] = 0;
      figure->coordinates[2][0] = 4;
      figure->coordinates[2][1] = 0;
      figure->coordinates[3][0] = 5;
      figure->coordinates[3][1] = 0;
      break;
    case UGOL_L:
      figure->coordinates[0][0] = 3;
      figure->coordinates[0][1] = 0;
      figure->coordinates[1][0] = 4;
      figure->coordinates[1][1] = 0;
      figure->coordinates[2][0] = 5;
      figure->coordinates[2][1] = 0;
      figure->coordinates[3][0] = 5;
      figure->coordinates[3][1] = -1;
      break;
      /*ase KVADRAT:
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
        break;*/

    default:
      break;
  }
}

int move_down(Figure* figure, Area* area) {
  int result = can_move(figure, area);

  if (!result) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][1]++;
    }
  }
  change_area(area, figure);
  clean_old_down(area, figure);
  return result;
}

int move_left(Figure* figure, Area* area) {
  int result = can_move_left_right(-1, figure, area);
  if (!result) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]--;
    }
  }

  return result;
}

int move_right(Figure* figure, Area* area) {
  int result = can_move_left_right(1, figure, area);
  if (!result) {
    for (int i = 0; i < 4; i++) {
      figure->coordinates[i][0]++;
    }
  }

  return result;
}