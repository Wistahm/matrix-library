#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

typedef struct {
  size_t rows;
  size_t cols;
  double *data;
} Matrix;

Matrix* create_matrix(size_t rows, size_t cols);
double get_element(Matrix* matrix, size_t row, size_t col);
void set_element(Matrix* matrix, size_t row, size_t col, double value);
Matrix* addition(Matrix* a, Matrix* b);
Matrix* subtraction(Matrix* a, Matrix* b);
Matrix* negate(Matrix* a);
Matrix* fixed_multiplication(Matrix* a, int multiplier);
Matrix* multiplication(Matrix* a, Matrix* b);
void free_matrix(Matrix* matrix);
Matrix* create_minor_matrix(Matrix* matrix, size_t row, size_t col);
double determinant(Matrix* a);
Matrix* create_augmented_matrix(Matrix* a);
void gaussian_elimination(Matrix* augmented);
Matrix* extract_inversion(Matrix* augmented);
Matrix* inversion(Matrix* a);
Matrix* transpose(Matrix* a);

#endif // !MATRIX_H
