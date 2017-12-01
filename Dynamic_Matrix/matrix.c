/*Faysal Khatri*/
/*07-02-2017*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"



matrix_t* new_matrix(int rows, int cols) {
 /*
  * new_matrix() returns a pointer to a matrix_t struct
  */
  
  
  matrix_t* new_matrix = (matrix_t *) malloc(sizeof(new_matrix)); 
  int matrix[rows][cols];
  
  new_matrix->topLeft = (int*) malloc(sizeof(matrix));
  new_matrix->rows = rows;
  new_matrix->cols = cols;
    
  zero_matrix(new_matrix);
   
  return new_matrix;
  
}

void zero_matrix(matrix_t* matrix) {
  int i=0;
  int j=0;
  int (*ptr)[matrix->cols];
  ptr = matrix->topLeft;
 
  for (i=0; i<matrix->rows; i++) {
	  for (j=0; j<matrix->cols; j++) {
		  ptr[i][j]=0;
	  }
  }
}

void print_matrix(matrix_t* matrix) {
  int i=0;
  int j=0;

  printf("Printing matrix at address %p: \n", (void *) matrix);
  
  for (i=0; i<matrix->rows; i++) {
	  for (j=0; j<matrix->cols; j++) {
		  /* printf("%d,%d: %d\t", i, j, ptr[i][j]); */
		  printf("\t%d", get_value(matrix, i, j));
	  }
	  printf("\n");
  }
}

int get_value(const matrix_t * matrix, int row, int col) {
  int (*ptr)[matrix->cols];
  ptr = matrix->topLeft;
  return ptr[row][col];
}

void set_value(matrix_t * matrix, int row, int col, int value) {
  int (*ptr)[matrix->cols];
  ptr = matrix->topLeft;
  ptr[row-1][col-1] = value;
  
}

matrix_t * add_matrices(const matrix_t * matrix1, const matrix_t * matrix2) {
	int numRows = matrix1->rows;
	int numCols = matrix1->cols;
	
	matrix_t* result = new_matrix(numRows, numCols);
	
	int (*rptr)[numCols];
	int (*ptr1)[numCols];
	int (*ptr2)[numCols];
	int i;
	int j;		

	
	if ( (matrix1->rows != matrix2->rows) || (matrix1->cols != matrix2->cols) ) {
		printf("Matrix dimensions do not match, cannot add. Returning pointer to empty matrix.\n");
		return result;
	}
	
    rptr = result->topLeft;
	ptr1 = matrix1->topLeft;
	ptr2 = matrix2->topLeft;
		
	for (i=0; i<numRows; i++) {
	  for (j=0; j<numCols; j++) {
		  rptr[i][j] = ptr1[i][j] + ptr2[i][j];
	  }
    }
	
	return result;
}

matrix_t * transpose(const matrix_t * matrix) {
	int numRows = matrix->rows;
	int numCols = matrix->cols;
	int i;
	int j;		
	
	matrix_t* result = new_matrix(numCols, numRows);
	
	int (*rptr)[numRows];
	int (*ptr1)[numCols];
	
	rptr = result->topLeft;
	ptr1 = matrix->topLeft;
	
	for (i=0; i<numCols; i++) {
	  for (j=0; j<numRows; j++) {
		  rptr[i][j] = ptr1[j][i];
	  }
    }
	return result;
}




