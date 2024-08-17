#include <ncurses.h>
#include <stdio.h>

#include "brick_game/tetris/figures.h"
#include "gui/cli/simple_view.h"

int main() {

  Figure figure;
  figure.type = VNIZ;
  figure.color = VIOLET;
  figure.rotation = UP;
  start_coordinates(&figure);
  Area area;
  area.x = 12;
  area.y = 22;
  start_area(&area);
  start_coordinates(&figure);
  change_area(&area, &figure);

  initscr();
  resizeterm(90,90);

  printf("HELLO world!\n");

  int row, col;

  getmaxyx(stdscr, row, col);

  // перемещение курсора в стандартном экране
  //move(row / 2, col / 2);

  //printw("Hello world");  // вывод строки
  refresh();              // обновить экран
  getch();                // ждём нажатия символа


    WINDOW* tetris = newwin(24, 60, 4, 4);

    WINDOW* play_area = derwin(tetris, 22, 13, 1, 1);

    WINDOW* menu = derwin(tetris, 4, 25, 2, 28);
    WINDOW* next_figure = derwin(tetris, 5, 20, 7, 30);
    WINDOW* score = derwin(tetris, 4, 25, 15, 28);
    box(menu, 0, 0);
    box(next_figure, 0, 0);
    box(score, 0, 0);

    box(tetris, 0, 0);
    mvwprintw(menu, 1, 1, "MENU");
    mvwprintw(next_figure, 1, 1, "NEXT");
    mvwprintw(score, 1, 1, "SCORE");
    ncdraw_area(&area, play_area);
    wrefresh(tetris);













  //ncdraw_area(&area);

  refresh();
  getch();

  endwin();  // завершение работы с ncurses

  return 0;
}