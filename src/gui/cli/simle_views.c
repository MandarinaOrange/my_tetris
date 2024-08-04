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
    if (j < area->y - 1) printf("\n");
  }
}