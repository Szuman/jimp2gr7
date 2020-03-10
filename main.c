#include "game.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

int main (int argc, char**argv) {
	game_t * gm;
	int size = argc > 1 ? atoi(argv[1]) : 10;
	gm = createGame(size);
	printf("Size = %d\n", gm->size);
	printToScreen(gm);
	freeGame(gm);
	printf("Done \n");
	return 0;
}

