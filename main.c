#include <stdio.h>
#include "matrix.h"

int main() {
  // Create the matrices
  Matrix* m1 = create_matrix(2, 2);
  Matrix* m2 = create_matrix(2, 3);

  // Set elements and fill the matrices
  set_element(m1, 0, 0, 7);
  set_element(m1, 0, 1, 8);
  set_element(m1, 1, 0, 9);
  set_element(m1, 1, 1, 10);

  set_element(m2, 0, 0, 1);
  set_element(m2, 0, 1, 2);
  set_element(m2, 0, 2, 3);
  set_element(m2, 1, 0, 4);
  set_element(m2, 1, 1, 5);
  set_element(m2, 1, 2, 6);

  // Save the result of calculation into another matrix
  Matrix* result = multipication(m1, m2);

  // Print the final result to the console
  for (size_t i = 0; i < result->rows; i++) {
    for (size_t j = 0; j < result->cols; j++) {
      printf("%d ", get_element(result, i, j));
    }
    printf("\n");
  }

  // Free the allocated memory used for the matrices 
  free_matrix(m1);
  free_matrix(m2);
  free_matrix(result);

  return 0;
}
