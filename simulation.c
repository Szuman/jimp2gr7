#include <stdlib.h>
#include <stdio.h>
#include "simulation.h"

int count_neighbor(int** matrix_1, int curr_row, int curr_col, int row, int col)
{
	if (curr_row < 0 || curr_row >= row || curr_col < 0 || curr_col >= col || matrix_1[curr_row][curr_col] != 1)
		return 0;
	else 
		return 1;
    
}

int getneighbor_moore(int** matrix_1, int curr_row, int curr_col, int row, int col) 
{
	int neighbor = 0;
	neighbor += count_neighbor(matrix_1, curr_row - 1, curr_col - 1, row, col);
	neighbor += count_neighbor(matrix_1, curr_row - 1, curr_col, row, col);
	neighbor += count_neighbor(matrix_1, curr_row - 1, curr_col + 1, row, col);
	neighbor += count_neighbor(matrix_1, curr_row, curr_col - 1, row, col);
	neighbor += count_neighbor(matrix_1, curr_row, curr_col + 1, row, col);
	neighbor += count_neighbor(matrix_1, curr_row + 1, curr_col - 1, row, col);
	neighbor += count_neighbor(matrix_1, curr_row + 1, curr_col, row, col);
	neighbor += count_neighbor(matrix_1, curr_row + 1, curr_col + 1, row, col);

	return neighbor;
}

int getneighbor_neumann(int** matrix_1, int curr_row, int curr_col, int row, int col)
{
	int neighbor = 0;
	neighbor += count_neighbor(matrix_1, curr_row, curr_col + 1, row, col);
	neighbor += count_neighbor(matrix_1, curr_row, curr_col - 1, row, col);
	neighbor += count_neighbor(matrix_1, curr_row - 1, curr_col, row, col);
	neighbor += count_neighbor(matrix_1, curr_row + 1, curr_col, row, col);

	return neighbor;
}

void calculate_n(int** matrix_1, int** matrix_2, int row, int col, int choice)
{
	int neighbor = 0;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (choice == 0) 
				neighbor = getneighbor_neumann(matrix_1, i, j, row, col);

			else if (choice == 1) 
				neighbor = getneighbor_moore(matrix_1, i, j, row, col);

			if (neighbor == 3) 
				matrix_2[i][j] = 1;

			else if (neighbor == 2 && matrix_1[i][j] == 1) 
				matrix_2[i][j] = 1;

			else 
				matrix_2[i][j] = 0;

		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) 
			matrix_1[i][j] = matrix_2[i][j];
	}
}
