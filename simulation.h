#ifndef SIMULATION_MANAGER_H_
#define SIMULATION_MANAGER_H_

int count_neighbor(int** matrix_1, int curr_row, int curr_col, int row, int col);

int getneighbor_neumann(int** matrix_1, int curr_row, int curr_col, int row, int col);

int getneighbor_moore(int** matrix_1, int curr_row, int curr_col, int row, int col);

void calculate_n(int** matrix_1, int** matrix_2, int row, int col, int choice);

#endif
