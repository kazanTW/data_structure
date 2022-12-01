#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    short int vert;
    short int horiz;
    } offsets;

typedef struct {
    short int row;
    short int col;
    short int dir;
    } element;

offsets move[8];
