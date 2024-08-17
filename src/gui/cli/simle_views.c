#include <ncurses.h>

#include "simple_view.h"

void draw_area(Area* area) {
  for (int j = 0; j < area->y; j++) {
    for (int i = 0; i < area->x; i++) {
      if (area->field[i][j] == 0) {
        printf("*");
      } else {
        printf("%d", area->field[i][j]);
      }
    }
    printf("\n");
  }
}

void ncdraw_area(Area* area, WINDOW* window) {
  for (int j = 0; j < area->y; j++) {
    for (int i = 0; i < area->x; i++) {
      if (area->field[i][j] == 0) {
        wprintw(window, "*");
      } else {
        wprintw(window, "%d", area->field[i][j]);
      }
    }
    wprintw(window, "\n");
  }
}