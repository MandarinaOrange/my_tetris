#include <ncurses.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../../gui/cli/simple_view.h"
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

int full_game(Area* area, int* record, int speed) {
  int result = 0;

  WINDOW *tetris;
  WINDOW *play_area;
  WINDOW *menu;
  WINDOW *score;
  WINDOW *next_figure;
  start_area(area);
  ncdraw_windows(&tetris, &play_area, &menu, &next_figure, &score, area);


  srand(time(0));
  Figure figure, next_fig;
  game_change_figure(&figure, &next_fig, next_figure, area);
  change_area(area, &figure);
  ncdraw_area(area, play_area);

  int code = 'y';
  int change_fig = 0;
  while (code != 'q') {
    code = getch();
  }
  code = 'y';
  while (code != 'q') {
    if (code == 'p') {
      // ncpause(&code, tetris);
    } else {
      game_continue(area, &figure, speed, &result, code);
      ncdraw_area(area, play_area);
    }
    code = getch();
    //move_down(area, &figure);
    change_fig = game_move_down(area, &figure);
    change_area(area, &figure);
    ncdraw_area(area, play_area);

    if (change_fig == 1) {
      game_change_figure(&figure, &next_fig, next_figure, area);
    }
  }

  if (result > *record) {
    *record = result;
  }
  return result;
}



int game_continue(Area* area, Figure* figure, int speed, int* result, int code) {
  switch (getch()) {
    case 'r':
    case KEY_RIGHT:
      move_right(area, figure);
      break;
    case 'l':
    case KEY_LEFT:
      move_left(area, figure);
      break;
    case 'd':
    case KEY_DOWN:
      move_down(area, figure);
      break;
    case KEY_UP:
      rotate_right(area, figure);

    default:
      break;
  }
  // move_down(area, figure);
  change_area(area, figure);
  return game_move_down(area, figure);
}

int game_change_figure(Figure* figure, Figure* next_fig, WINDOW *wind, Area* area) {

  game_area_scan(area);

  figure->type = UGOL_G;//next_fig->type;
  start_coordinates(figure);
  next_fig->type = rand() % 8;
  mvwprintw(wind, 1, 1, "NEXT IS %d", next_fig->type);
  wrefresh(wind);
}
