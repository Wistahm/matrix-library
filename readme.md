# Matrix Library

A simple library written in C for matrix calculations such as addition, subtraction, multiplication, finding the determinant, etc. To find out more, check out the table of content below.

## Content
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)

## Installation
To use this library in you project, follow these steps:

1. **Clone the repository**:
```git clone https://github.com/Wistahm/matrix-library.git```

2. Include the Header file:
```#include "matrix.h"```

3. Compile with the source file:
```gcc main.c matrix.c -o my_program```

## Usage
After including the library, you can create matrices and perform operations. Here's a brief overview of how to use the main functions:

1. Creating a matrix:
```Matrix* matrix = create_matrix(rows, cols);```

2. Setting the matrix elements:
```set_element(matrix, 0, 0, 4);```

3. Calculatin the determinate:
```double det = determinant(matrix);```

4. Freeing memory:
```free_matrix(matrix);```

## Examples
Here are some examples of how to use this library:

### Example 1: Calculate the deteminant of a 2x2 matrix
```
#include "matrix.h"

int main() {
    Matrix *mat = create_matrix(2, 2);
    
    set_element(mat, 0, 0, 1);
    set_element(mat, 0, 1, 2);
    set_element(mat, 1, 0, 3);
    set_element(mat, 1, 1, 4);

    double det = determinant(mat);
    if (det != -1) {
        printf("Determinant: %.2f\n", det);
    }

    free_matrix(mat);
    
    return 0;
}
```

### Example 2: Calculate the multiplication of two matrices
```
#include "matrix.h"

int main() {
    Matrix *mat1 = create_matrix(2, 2);
    Matrix *mat2 = create_matrix(2, 2);    

    set_element(mat1, 0, 0, 1);
    set_element(mat1, 0, 1, 2);
    set_element(mat1, 1, 0, 3);
    set_element(mat1, 1, 1, 4);

    set_element(mat2, 0, 0, 5);
    set_element(mat2, 0, 1, 6);
    set_element(mat2, 1, 0, 7);
    set_element(mat2, 1, 1, 8);

    Matrix* result = multiplication(mat1, mat2);

    // Print out the result
    for (size_t i = 0; i < result->rows; i++) {
        for (size_t j = 0; j < result->cols; j++) {
            printf("%d ", get_element(result, i, j));
        }
        printf("\n");
    } 

    free_matrix(mat1);
    free_matrix(mat2);    

    return 0;
}
```

If you like, feel free to contribute to this library and submit a pull request.
Regards!
