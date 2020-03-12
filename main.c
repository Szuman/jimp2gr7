#include "game.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char**argv) {
	game_t * gm;
	int size = argc > 1 ? atoi(argv[1]) : 10;
	int N = argc > 2 ? atoi(argv[2]) : 4;
	gm = createGame(size);
	printf("Size = %d\n", gm->size);
	printf("\e[1;1H\e[2J");
	printToScreen(gm);
	int n = 1;
	while (n < N) {
		sleep (1);
		printf("\e[1;1H\e[2J");
		setNextGame(gm);
		printToScreen(gm);
		n++;
	}
	freeGame(gm);
	printf("Done !!!\n");
	return 0;
}

