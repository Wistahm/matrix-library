#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef struct {
  size_t rows;
  size_t cols;
  int *data;
} Matrix;

Matrix* create_matrix(size_t rows, size_t cols);
int get_element(Matrix* matrix, size_t row, size_t col);
void set_element(Matrix* matrix, size_t row, size_t col, int value);
Matrix* addition(Matrix* a, Matrix* b);
Matrix* subtraction(Matrix* a, Matrix* b);
Matrix* negate(Matrix* a);
Matrix* fixed_multiplication(Matrix* a, int multiplier);
Matrix* multiplication(Matrix* a, Matrix* b);
void free_matrix(Matrix* matrix);

#endif // !MATRIX_H
