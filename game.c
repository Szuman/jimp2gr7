#include "game.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/*
typedef struct game {
	int size;
	bool ** cell;
}game_t;
*/

game_t * createGame  (int s) {
	game_t * gm = (game_t*) malloc(sizeof(game_t));
	if (gm != NULL) {
		gm->size = s;
		gm->cell = (bool**) malloc(sizeof(bool*) * s);
		for (int i = 0; i < s; i++) {
			gm->cell[i] = (bool*) malloc(sizeof(bool) * s);
			for (int j = 0; j < s; j++)
				gm->cell[i][j] = false;
			}
		gm->cell[0][0] = true;
		gm->cell[s-1][s-1] = true;
		gm->cell[0][s-1] = true;
		gm->cell[s-1][0] = true;
	}	
		return gm;
}

void printToScreen(game_t * gm) {
	printf("\n");
	for (int i = 0; i < gm->size; i++) {
		printf(" ");
		for (int j = 0; j < gm->size; j++) {
			if (gm->cell[i][j] == true)
				printf("$ ");
			else printf("# ");
		}
		printf(" \n");
	}
	printf("\n");	
}


void freeGame(game_t * gm) {
	for (int i=0; i < gm->size; i++)
		free(gm->cell[i]);
	free(gm->cell);
	free(gm);
}



