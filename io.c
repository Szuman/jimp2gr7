#include <stdlib.h>
#include <stdio.h>
#include "io.h"
#include "png.h"

void show(int** matrix_1, int row, int col)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) 
			printf("%d ", matrix_1[i][j]);
		printf("\n");
	}
}

int** create_matrix(int row, int col)
{
	int** matrix_1 = (int**)malloc(row * sizeof(int*));

	for (int i = 0; i < row; i++) 
		matrix_1[i] = (int*)malloc(col * sizeof(int));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			matrix_1[i][j] = 0;
	}

	return matrix_1;
}

void free_matrix(int** matrix_2, int** matrix_1, int row, int col)
{
	for (int i = 0; i < row; i++) {
		free(matrix_2[i]);
		free(matrix_1[i]);
	}
	free(matrix_2);
	free(matrix_1);
}

int** recreate(int** matrix_1, int** image, int row, int col)
{

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (matrix_1[i][j] == 1) 
				image[i][j] = 0;
			
			else
				image[i][j] = 255;
		}
	}
	
	return image;
}

void print(int** image, int row, int col, int generation)
{
	int temp = 0;
	char file_name[20];

	snprintf(file_name, 20, "image/image_%d%s", generation, ".pgm");
	FILE* pgmimg = fopen(file_name, "wb");

	fprintf(pgmimg, "P2\n");

	fprintf(pgmimg, "%d %d\n", col, row);

	fprintf(pgmimg, "255\n");
	int count = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp = image[i][j];

			fprintf(pgmimg, "%d ", temp);
		}
		fprintf(pgmimg, "\n");
	}
	fclose(pgmimg);
}

void free_image(int** image, int row, int col)
{
	for (int i = 0; i < row; i++) 
		free(image[i]);

	free(image);
}
