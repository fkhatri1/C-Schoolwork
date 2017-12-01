/*Faysal Khatri*/
/*07-02-2017*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"


int main() {
	
	matrix_t* myMatrix = new_matrix(2, 2);
	matrix_t* myMatrix2 = new_matrix(4, 2);
	matrix_t* myMatrix3;
	matrix_t* myMatrix4;

	
	set_value(myMatrix, 1, 1, 5);
	set_value(myMatrix, 1, 2, 6);
	set_value(myMatrix, 2, 1, 7);
	set_value(myMatrix, 2, 2, 8);
	print_matrix(myMatrix);
	
	
	set_value(myMatrix2, 1, 1, 5);
	set_value(myMatrix2, 1, 2, 6);
	set_value(myMatrix2, 2, 1, 7);
	set_value(myMatrix2, 2, 2, 8);
	print_matrix(myMatrix2);
	
	printf("Trying to add matrices...\n\n");
	myMatrix3 = add_matrices(myMatrix, myMatrix2);
	print_matrix(myMatrix3);	
	
	printf("Trying to transpose...\n\n");
	myMatrix4 = transpose(myMatrix2);	
	print_matrix(myMatrix4);
	return 0;
	
}