#include <stdio.h>

#include "figures.h"

int game_start() {
  int level = 0;
  for (int i = 0; i < 22; i++) {
    for (int j = 0; j < 12; j++) {
      if (i == 0 || i == 21 || j == 0 || j == 11) {
        printf("%d", 8);
      } else if (i == 7 && j == 3) {
        printf("CHOOSE");
        j += 5;
      } else if (i == 9 && j == 5) {
        printf("THE");
        j += 2;
      } else if (i == 11 && j == 4) {
        printf("LEVEL");
        j += 4;
      } else {
        printf(" ");
      }
      if (j == 11) printf("\n");
    }
  }

  scanf("%d", &level);
  return level;
}

int game_move_down(Area* area, Figure* figure) {
  int result = 1;
  switch (figure->type) {
    case PALKA:
      result = can_move_down_palka(area, figure);
      break;
    case UGOL_G:
      result = can_move_down_ugol_g(area, figure);
      break;
    case UGOL_L:
      result = can_move_down_ugol_l(area, figure);
      break;
    case KVADRAT:
      result = can_move_down_kvadrat(area, figure);
      break;
    case VVERH:
      result = can_move_down_vverh(area, figure);
      break;
    case FUCK:
      result = can_move_down_fuck(area, figure);
      break;
    case VNIZ:
      result = can_move_down_vniz(area, figure);
      break;
    default:
      break;
  }
  return result;
}

// int field[12][22]

int game_area_scan(Area* area) {
  int result = 0;
  int flag = 0;

  for (int i = 1; i < 21; i++) {
    flag = 0;
    for (int j = 1; j < 11; j++) {
      if (area->field[j][i] == FREE) {
        flag = 1;
      }
    }
    if (flag == 0) {
      for (int j = 1; j < 11; j++) {
        area->field[j][i] = FREE;
      }
      game_area_fall(area, i);
      result = 1;
    }
    flag = 0;
  }
  return result;
}

void game_area_fall(Area* area, int row) {
  for (int i = row - 1; row > 0; row--) {
    for (int j = 1; j < 11; j++) {
      area->field[j][i + 1] = area->field[j][i];
    }
  }
}
