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
/*
typedef struct game {
	int size;
	bool ** cell;
	struct game * next;
}game_t;
*/

game_t * createGame  (int s) {
	game_t * gm = (game_t*) malloc(sizeof(game_t));
	gm->next = malloc(sizeof(gm->next));
	if (gm != NULL) {
		gm->size = s;
		gm->cell = (bool**) malloc(sizeof(bool*) * s);
		gm->next->cell = (bool**) malloc(sizeof(bool*) * s);
		for (int i = 0; i < s; i++) {
			gm->cell[i] = (bool*) malloc(sizeof(bool) * s);
			gm->next->cell[i] = (bool*) malloc(sizeof(bool) * s);
			for (int j = 0; j < s; j++)
				gm->cell[i][j] = false;
			}
		gm->cell[0][0] = true;
		gm->cell[1][1] = true;
		gm->cell[1][2] = true;
		gm->cell[2][0] = true;
		gm->cell[2][1] = true;
		gm->cell[s-1][s-1] = true;
		gm->cell[s-2][s-1] = true;
		gm->cell[s-1][s-2] = true;
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
				printf("+ ");
			else printf("- ");
		}
		printf(" \n");
	}
	printf("\n");	
}

int alive (game_t * gm, int x, int y) {
	int counter = 0;
		if (x == 0) {
			if (y == 0) {
				if (gm->cell[x][y+1]==true) counter++;
				if (gm->cell[x+1][y]==true) counter++;
				if (gm->cell[x+1][y+1]==true) counter++;
			}
			else if (y == gm->size-1) {
				if (gm->cell[x][y-1]==true) counter++;
				if (gm->cell[x+1][y]==true) counter++;
				if (gm->cell[x+1][y-1]==true) counter++;
			}
			else {
				if (gm->cell[x][y-1]==true) counter++;
				if (gm->cell[x][y+1]==true) counter++;
				if (gm->cell[x+1][y-1]==true) counter++;
				if (gm->cell[x+1][y]==true) counter++;
				if (gm->cell[x+1][y+1]==true) counter++;
			}
		}
		else if (x == gm->size-1) {
			if (y == 0) {
				if (gm->cell[x][y+1]==true) counter++;
				if (gm->cell[x-1][y]==true) counter++;
				if (gm->cell[x-1][y+1]==true) counter++;
			}
			else if (y == gm->size-1) {
				if (gm->cell[x][y-1]==true) counter++;
				if (gm->cell[x-1][y]==true) counter++;
				if (gm->cell[x-1][y-1]==true) counter++;
			}
			else {
				if (gm->cell[x][y-1]==true) counter++;
				if (gm->cell[x][y+1]==true) counter++;
				if (gm->cell[x-1][y-1]==true) counter++;
				if (gm->cell[x-1][y]==true) counter++;
				if (gm->cell[x-1][y+1]==true) counter++;
			}
		}
		else {
			if (y == 0) {
				if (gm->cell[x-1][y]==true) counter++;
				if (gm->cell[x-1][y+1]==true) counter++;
				if (gm->cell[x+1][y]==true) counter++;
				if (gm->cell[x+1][y+1]==true) counter++;
				if (gm->cell[x][y+1]==true) counter++;
			}
			else if (y == gm->size-1) {
				if (gm->cell[x][y-1]==true) counter++;
				if (gm->cell[x-1][y-1]==true) counter++;
				if (gm->cell[x-1][y]==true) counter++;
				if (gm->cell[x+1][y]==true) counter++;
				if (gm->cell[x+1][y-1]==true) counter++;
			}
			else {
				if (gm->cell[x][y-1]==true) counter++;
				if (gm->cell[x][y+1]==true) counter++;
				if (gm->cell[x-1][y-1]==true) counter++;
				if (gm->cell[x-1][y]==true) counter++;
				if (gm->cell[x-1][y+1]==true) counter++;
				if (gm->cell[x+1][y]==true) counter++;
				if (gm->cell[x+1][y+1]==true) counter++;
				if (gm->cell[x+1][y-1]==true) counter++;
			}
		}
	return counter;
}

void setNextGame (game_t * gm) {
	for (int i = 0; i < gm->size; i++) {
		for (int j = 0; j < gm->size; j++) {
			int counter = alive(gm, i, j);
			if ((gm->cell[i][j] == true && counter == 2) || counter == 3)
				gm->next->cell[i][j] = true;
			else 
				gm->next->cell[i][j] = false;
		}
	}
	for (int i = 0; i < gm->size; i++) {
		for (int j = 0; j < gm->size; j++) 
			gm->cell[i][j] = gm->next->cell[i][j];
		
	}
}

void freeGame(game_t * gm) {
	for (int i=0; i < gm->size; i++) {
		free(gm->next->cell[i]);
		free(gm->cell[i]);
	}
	free(gm->next->cell);
	free(gm->cell);
	free(gm->next);
	free(gm);
}
