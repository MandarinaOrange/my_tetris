#include <ncurses.h>
#include <panel.h>

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
  // curs_set(0);
  wclear(window);
  wrefresh(window);

  for (int j = 0; j < area->y; j++) {
    for (int i = 0; i < area->x; i++) {
      if (area->field[i][j] == 0) {
        waddch(window, ' ');
      } else {
        // wprintw(window, "%c", area->field[i][j]);
        waddch(window, area->field[i][j]);
      }
    }
    if (j < area->y - 1) wprintw(window, "\n");
  }
  wrefresh(window);
}



void ncdraw_windows(WINDOW **tetris, WINDOW **play_area, WINDOW **menu, WINDOW **next_figure, WINDOW **score, Area *area) {

  printw("OK\n");

  *tetris = newwin(24, 60, 4, 4);
  *play_area = derwin(*tetris, 22, 13, 1, 1);
  *menu = derwin(*tetris, 4, 25, 2, 28);
  *next_figure = derwin(*tetris, 5, 20, 7, 30);
  *score = derwin(*tetris, 4, 25, 15, 28);
  box(*menu, 0, 0);
  box(*next_figure, 0, 0);
  box(*score, 0, 0);
  box(*tetris, 0, 0);
  mvwprintw(*menu, 1, 1, "MENU");
  mvwprintw(*next_figure, 1, 1, "NEXT");
  mvwprintw(*score, 1, 1, "SCORE");
  ncdraw_area(area, *play_area);
  wrefresh(*tetris);
  printw("OK\n");
    int code = 'y';
  int change_fig = 0;
  while (code != 'q') {
    code = getch();
  }
}

int ncpause(int* code, WINDOW* tetris) {
  WINDOW* pause = derwin(tetris, 3, 15, 10, 24);
  PANEL* panel = new_panel(pause);
  box(panel_window(panel), 0, 0);
  mvwaddnstr(panel_window(panel), 1, 1, "PAUSE", 3);
  update_panels();
  doupdate();

  show_panel(panel);
  while (*code != 'c') {
    *code = getch();
  }
  return del_panel(panel);
  return 0;
}
