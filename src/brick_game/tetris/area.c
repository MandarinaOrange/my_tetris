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
      start_ugol_g(figure);
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
  switch (figure->type) {
    case PALKA:
      move_down_palka(area, figure);
      break;
    case UGOL_G:
      move_down_ugol_g(area, figure);
      break;
    case UGOL_L:
      break;
      /*case KVADRAT:

        break;
      case VVERH:

        break;
      case FUCK:

        break;
      case VNIZ:*/


    default:
      break;
  }
}

void move_left(Figure* figure, Area* area) {
  switch (figure->type) {
    case PALKA:
      move_left_palka(area, figure);
      break;
    case UGOL_G:
      move_left_ugol_g(area, figure);
      break;
    case UGOL_L:
      break;
      /*case KVADRAT:

        break;
      case VVERH:

        break;
      case FUCK:

        break;
      case VNIZ:*/


    default:
      break;
  }
}

void move_right(Figure* figure, Area* area) {
  switch (figure->type) {
    case PALKA:
      move_right_palka(area, figure);
      break;
    case UGOL_G:
      move_right_ugol_g(area, figure);
      break;
    case UGOL_L:
      break;
      /*case KVADRAT:

        break;
      case VVERH:

        break;
      case FUCK:

        break;
      case VNIZ:*/


    default:
      break;
  }
}