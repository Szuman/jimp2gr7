#include <stdio.h>
#include <stdlib.h>
#include "simulation.h"
#include "io.h"
#include "png.h"

int main() 
{
	int col;
	int row;
	int** matrix_1;
	int** matrix_2;
	int** image;
	FILE* file = NULL;
	file = fopen("lb.txt", "r");
	fscanf(file, "%d %d", &row, &col);
	int r = 0;
	int c = 0;
	matrix_1 = create_matrix(row, col);
	matrix_2 = create_matrix(row, col);
	image = create_matrix(row, col);

	for (int i = 0; i < row; i++) {

		for (int j = 0; j < col; j++) {
			fscanf(file, "%d", &matrix_1[i][j]);
			if (matrix_1[i][j] != 0 && matrix_1[i][j] != 1) {
				printf("enter 0 or 1 to fill the playing field");
				return -1;
			}
		}
	}

	show(matrix_1, row, col);
	printf("\n");
	char end;
	int generation = 0;
	int choice;
	printf("Choose neighborhood: \n");
	printf("For von Neumann press 0, for Moore press 1\n");
	scanf("%d", &choice);
	if (choice == 0) {
		do {
			image = recreate(matrix_1, image, row, col);
	 		print(image, row, col, generation);
			calculate_n(matrix_1, matrix_2, row, col, choice);
			printf("Generation %d\n", ++generation);
			show(matrix_1, row, col);
			printf("Press q to quit or 1 to continue: ");
			scanf(" %c", &end);
		} while (end != 'q');
	}
	else if (choice == 1) {
		do {
			image = recreate(matrix_1, image, row, col);
			print(image, row, col, generation);
			calculate_n(matrix_1, matrix_2, row, col, choice);
			printf("Generation %d\n", ++generation);
			show(matrix_1, row, col);
			printf("Press q to quit or 1 to continue: ");
			scanf(" %c", &end);
		} while (end != 'q');
	}
	free_matrix(matrix_1, matrix_2, row, col);
	free_image(image, row, col);

	return 0;
}


