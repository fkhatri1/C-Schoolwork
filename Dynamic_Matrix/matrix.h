/*Faysal Khatri*/
/*06-02-2017*/

	/*
	 * matrix_t is a struct which contains a pointer topLeft. 
	 * toLeft points to index 0 of an array of int pointers which point to index 0 of each row.
	 */
	typedef struct matrix_t {
		int rows;
		int cols;
		int ** topLeft;
	} matrix_t;

	matrix_t* new_matrix(int rows, int cols);
	void zero_matrix(matrix_t* matrix);
	void print_matrix(matrix_t* matrix);
	int get_value(const matrix_t * matrix, int row, int col);
	void set_value(matrix_t * matrix, int row, int col, int value);
	matrix_t * add_matrices(const matrix_t * matrix1, const matrix_t * matrix2);
	matrix_t * transpose(const matrix_t * matrix);