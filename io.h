#ifndef IO_H_
#define IO_H_
#include "png.h"

void show(int** matrix_1, int row, int col);
int** create_matrix(int row, int col);
void free_matrix(int** matrix_2, int** matrix_1, int row, int col);
int** recreate(int** matrix_1, int** image, int row, int col);
void print(int** image, int row, int col, int generation);
void free_image(int** image, int row, int col);
#endif
