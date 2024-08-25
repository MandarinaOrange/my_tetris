#include <ncurses.h>
#include <stdio.h>
#include <time.h>

#include "brick_game/tetris/figures.h"
#include "gui/cli/simple_view.h"
#define DELAY 3000
#define TIMEOUT 100

int main() {
  /*


  getmaxyx(stdscr, row, col);

  // перемещение курсора в стандартном экране
  //move(row / 2, col / 2);

  //printw("Hello world");  // вывод строки
  refresh();              // обновить экран
  getch();                // ждём нажатия символа
*/



  initscr();
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, TRUE);
  curs_set(0);
  timeout(TIMEOUT);
  // resizeterm(90,90);
  getch();

  Area area;
  int record = 0;
  int speed = 2;

  full_game(&area, &record, speed);


  getch();

  endwin();  // завершение работы с ncurses

  return 0;
}