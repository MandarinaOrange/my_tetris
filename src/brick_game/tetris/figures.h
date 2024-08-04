#ifndef FIGURES_H
#define FIGURES_H


typedef struct {
    Figure figure;
    int coordinates[4][2]; //4 kletki po 2 koordinati //x y
    Color color;
} Figure_location;

//-----------------------FIGURES----------------------------------
//             1          4      12      34     4        12    
//   1234      234      123      34     12     123        34
//----------------------------------------------------------------

typedef enum {
    PALKA = 0, // ''''
    UGOL_G = 1, // :..
    UGOL_L = 2, // ..:
    KVADRAT = 3, // ::
    VVERH = 4, // .:'
    FUCK = 5, // .:.
    VNIZ = 6  // ':.

} Figure;

typedef enum {
    FREE = 0,
    RED = 1,
    ORANGE = 2,
    YELLOW = 3,
    PINK = 4,
    GREEN = 5,
    BLUE = 6,
    VIOLET = 7,
    BORTIK = 8
} Color;


typedef struct {
    int** field; //free = 0
    int x; //shirina + bortiki
    int y; //visota + bortiki
} Area;



int can_move(Figure_location* figure_location, Area* area);
int can_move_left_right(Figure_location* figure_location, Area* area);

int move_down(Figure_location* figure_location, Area* area);
int move_left(Figure_location* figure_location, Area* area);
int move_right(Figure_location* figure_location, Area* area);




#endif