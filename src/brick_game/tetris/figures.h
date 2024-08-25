#ifndef FIGURES_H
#define FIGURES_H

#include <ncurses.h>

typedef enum {
  PALKA = 0,    // ''''
  UGOL_G = 1,   // :..
  UGOL_L = 2,   // ..:
  KVADRAT = 3,  // ::
  VVERH = 4,    // .:'
  FUCK = 5,     // .:.
  VNIZ = 6      // ':.

} Figure_type;

typedef enum {
  FREE = 0,
  RED = '1',
  ORANGE = '2',
  YELLOW = '3',
  PINK = '4',
  GREEN = '5',
  BLUE = '6',
  VIOLET = 'R',
  BORTIK = '8'
} Color;

typedef enum {
  UP = 0,
  RIGHT = 1,
  DOWN = 2,
  LEFT = 3
} Rotation;

typedef struct {
  Figure_type type;
  int coordinates[4][2];  // 4 kletki po 2 koordinati //x y
  Color color;
  Rotation rotation;
} Figure;


//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------





typedef struct {
  int field[12][22];  // free = 0
  int x;        // shirina + bortiki
  int y;        // visota + bortiki
} Area;



int can_move(Figure* figure_location, Area* area);
int can_move_left_right(int direction, Figure* figure_location, Area* area);

void move_down(Area* area, Figure* figure);
void move_left(Area* area, Figure* figure);
void move_right(Area* area, Figure* figure);

void start_coordinates(Figure* figure_location);
void start_area(Area* area);

void change_area(Area* area, Figure* figure_location);


//--------------ROTATION--------------------
void change_rotate_right(Figure* figure);
void change_rotate_left(Figure* figure);
void rotate_right(Area* area, Figure* figure);
void test_rotate_right(Figure* figure, Figure* test_figure);
//void test_rotate_left(Figure* figure, Figure* test_figure);
void clean_rotate(Area* area, Figure* figure);


//--------------PALKA----------------
void start_palka(Figure* figure);
int move_down_palka(Area* area, Figure* figure);
int can_move_down_palka(Area* area, Figure* figure);
void move_left_palka(Area* area, Figure* figure);
int can_move_left_palka(Area* area, Figure* figure);
void move_right_palka(Area* area, Figure* figure);
int can_move_right_palka(Area* area, Figure* figure);
void rotate_right_palka(Area* area, Figure* figure);
void test_rotate_right_palka(Figure* figure);


//-------------UGOL_G-------------------
void start_ugol_g(Figure* figure);
void clean_old_ugol_g_left(Area* area, Figure* figure);
void clean_old_ugol_g_right(Area* area, Figure* figure);
void move_left_ugol_g(Area* area, Figure* figure);
int can_move_left_ugol_g(Area* area, Figure* figure);
void move_right_ugol_g(Area* area, Figure* figure);
int can_move_right_ugol_g(Area* area, Figure* figure);
void move_down_ugol_g(Area* area, Figure* figure);
int can_move_down_ugol_g(Area* area, Figure* figure);


//--------------UGOL_L---------------------
void start_ugol_l(Figure* figure);
void clean_old_ugol_l_down(Area* area, Figure* figure);
void clean_old_ugol_l_left(Area* area, Figure* figure);
void clean_old_ugol_l_right(Area* area, Figure* figure);
void move_left_ugol_l(Area* area, Figure* figure);
int can_move_left_ugol_l(Area* area, Figure* figure);
void move_right_ugol_l(Area* area, Figure* figure);
int can_move_right_ugol_l(Area* area, Figure* figure);
void move_down_ugol_l(Area* area, Figure* figure);
int can_move_down_ugol_l(Area* area, Figure* figure);




//--------------KVADRAT------------------------
void start_kvadrat(Figure* figure);
void clean_old_kvadrat_down(Area* area, Figure* figure);
void clean_old_kvadrat_left(Area* area, Figure* figure);
void clean_old_kvadrat_right(Area* area, Figure* figure);
void move_left_kvadrat(Area* area, Figure* figure);
int can_move_left_kvadrat(Area* area, Figure* figure);
void move_right_kvadrat(Area* area, Figure* figure);
int can_move_right_kvadrat(Area* area, Figure* figure);
void move_down_kvadrat(Area* area, Figure* figure);
int can_move_down_kvadrat(Area* area, Figure* figure);


//------------------FUCK---------------------------
void start_fuck(Figure* figure);
void clean_old_fuck_down(Area* area, Figure* figure);
void clean_old_fuck_left(Area* area, Figure* figure);
void clean_old_fuck_right(Area* area, Figure* figure);
void move_left_fuck(Area* area, Figure* figure);
int can_move_left_fuck(Area* area, Figure* figure);
void move_right_fuck(Area* area, Figure* figure);
int can_move_right_fuck(Area* area, Figure* figure);
void move_down_fuck(Area* area, Figure* figure);
int can_move_down_fuck(Area* area, Figure* figure);




//---------------------VVERH---------------------------
void start_vverh(Figure* figure);
void clean_old_vverh_down(Area* area, Figure* figure);
void clean_old_vverh_left(Area* area, Figure* figure);
void clean_old_vverh_right(Area* area, Figure* figure);
void move_left_vverh(Area* area, Figure* figure);
int can_move_left_vverh(Area* area, Figure* figure);
void move_right_vverh(Area* area, Figure* figure);
int can_move_right_vverh(Area* area, Figure* figure);
void move_down_vverh(Area* area, Figure* figure);
int can_move_down_vverh(Area* area, Figure* figure);





//----------------------VNIZ------------------------------
void start_vniz(Figure* figure);
void clean_old_vniz_down(Area* area, Figure* figure);
void clean_old_vniz_left(Area* area, Figure* figure);
void clean_old_vniz_right(Area* area, Figure* figure);
void move_left_vniz(Area* area, Figure* figure);
int can_move_left_vniz(Area* area, Figure* figure);
void move_right_vniz(Area* area, Figure* figure);
int can_move_right_vniz(Area* area, Figure* figure);
void move_down_vniz(Area* area, Figure* figure);
int can_move_down_vniz(Area* area, Figure* figure);





//----------------GAME_PLAY-----------------------
int game_start();
int game_move_down(Area* area, Figure* figure);
int game_area_scan(Area* area);
void game_area_fall(Area* area, int row);
int full_game(Area* area, int* record, int speed);
int game_continue(Area* area, Figure* figure, int speed, int* result, int code);
int game_change_figure(Figure* figure, Figure* next_fig, WINDOW* wind, Area* area);


#endif