#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

Matrix* create_matrix(size_t rows, size_t cols) {
  // Allocate memory for matrix struct
  Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));

  // Check for allocation failure
  if (!matrix) {
    printf("Memory allocation failed.\n");
    return NULL;
  }
  
  // Setting matrix dimensions
  matrix->rows = rows;
  matrix->cols = cols;
  matrix->data = (int *)malloc(rows * cols * sizeof(int));
  
  if (!matrix->data) {
    // Free previously allocated memory to avoid leaks
    free(matrix);
    return NULL;  // Check for allocation failure
  }

  // Optionally initialize all the elements to zero
  for (size_t i = 0; i < rows * cols; i++) {
    matrix->data[i] = 0;
  }

  return matrix;
}

void free_matrix(Matrix* matrix) {
  // Free the allocated memory for the matrix
  if (matrix) {
    free(matrix->data);
    free(matrix);
  }
}

int get_element(Matrix* matrix, size_t row, size_t col) {
  // Checking index validity
  if (row >= matrix->rows || col >= matrix->cols) {
    printf("Index is out of bound or invalid.\n");
    return -1;
  }

  return matrix->data[row * matrix->cols + col];
  
  /*
   * For a matrix with n columns, the elements at row 'r' and column 'c'
   * can be accessed at the index 'r * n + c'. 
   */
}

void set_element(Matrix* matrix, size_t row, size_t col, int value) {
  if (row < matrix->rows && col < matrix->cols) {
    matrix->data[row * matrix->cols + col] = value;
  }
}

Matrix* addition(Matrix *a, Matrix *b) {
  // Check the size of both matrices
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Matrix size mismatch.\n");
    return NULL;
  }
  
  Matrix* result_matrix = create_matrix(a->rows, a->cols);
  if (!result_matrix) return NULL;  // Check for allocation failure
  
  for (size_t i = 0; i < a->rows; i++) {
    for (size_t j = 0; j < a->cols; j++) {
      int value = get_element(a, i, j) + get_element(b, i, j);
      set_element(result_matrix, i, j, value);
    }
  }

  return result_matrix;
}

Matrix* subtraction(Matrix* a, Matrix* b) {
  // Check for the size of both matrices
  if (a->rows != b->rows || a->cols != b->cols) {
    printf("Matrix size mismatch.\n");
    return NULL;
  }

  Matrix* result_matrix = create_matrix(a->rows, a->cols);
  if (!result_matrix) return NULL;  // Checl for allocation failure

  for (size_t i = 0; i < a->rows; i++) {
    for (size_t j = 0; j < a->cols; j++) {
      int value = get_element(a, i, j) + -1 * (get_element(b, i, j));
      set_element(result_matrix, i, j, value);
    }
  }
  return result_matrix;
}

Matrix* negate(Matrix* a) {
  Matrix* result_matrix = create_matrix(a->rows, a->cols);
  if (!result_matrix) return NULL;  // Check for allocation failur

  for (size_t i = 0; i < a->rows; i++) {
    for (size_t j = 0; j < a->cols; j++) {
      int value = -1 * (get_element(a, i, j));
      set_element(result_matrix, i, j, value);
    }
  }

  return result_matrix;
}

Matrix* fixed_multipication(Matrix *a, int multiplier) {
  Matrix* result_matrix = create_matrix(a->rows, a->cols);
  if (!result_matrix) return NULL;  // Check for allocation failure

  for (size_t i = 0; i < a->rows; i++) {
    for (size_t j = 0; j < a->cols; j++) {
      int value = multiplier * (get_element(a, i, j));
      set_element(result_matrix, i, j, value);
    }
  }
  return result_matrix;
} 

Matrix* multipication(Matrix *a, Matrix *b) {
  if (a->cols == b->rows) {
    Matrix* result_matrix = create_matrix(a->rows, b->cols);
    if (!result_matrix) return NULL;  // Check for allocation failure

    for (size_t i = 0; i < a->rows; i++) {
      for (size_t j = 0; j < b->cols; j++) {
        int sum = 0;
        for (size_t k = 0; k < a->cols; k++) {
          int value_1 = get_element(a, i, k);
          int value_2 = get_element(b, k, j);
          sum += value_1 * value_2;
        }
        // Set the accumulated sum to the reuslt matrix
        set_element(result_matrix, i, j, sum);
      }
    }
    return result_matrix;
  } else {
    printf("Matrix index mismatch.\n");
    return NULL;
  }
}
