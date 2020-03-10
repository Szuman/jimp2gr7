#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct game {
	int size;
	bool ** cell;
}game_t;

game_t * createGame (int s);
void printToScreen (game_t * gm);
void freeGame (game_t * gm);

#endif
