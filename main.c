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
  Matrix* result = multiplication(m1, m2);  // Calculates the multiplication of given matrices

  // Print the final result 
  for (size_t i = 0; i < result->rows; i++) {
    for (size_t j = 0; j < result->cols; j++) {
      printf("%d ", get_element(result, i, j));
    }
    printf("\n");
  }

  // Another matrix to calculate its determinant
  Matrix* m3 = create_matrix(3, 3);

  set_element(m3, 0, 0, 2); 
  set_element(m3, 0, 1, -1);
  set_element(m3, 0, 2, 5);
  
  set_element(m3, 1, 0, 0);
  set_element(m3, 1, 1, 3);
  set_element(m3, 1, 2, 6);
  
  set_element(m3, 2, 0, 3);
  set_element(m3, 2, 1, 12);
  set_element(m3, 2, 2, 4);

  double det_m3 = determinant(m3);

  if (det_m3 != -1) {
    printf("\nDeterminant of m3: %.2f\n", det_m3);
  }

  // Free the allocated memory used for the matrices 
  free_matrix(m1);
  free_matrix(m2);
  free_matrix(result);

  return 0;
}
