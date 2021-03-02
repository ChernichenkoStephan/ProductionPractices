#pragma once

struct Matrix {
  int** value;
  int n_row;
  int n_col;
};

/**
 * Matrix multiplecation function
 *
 * Matrix multiplecation using Stroossen method
 *
 * @param l_mtx is first matrix with free size
 * @param r_mtx is second matrix with free size
 */
Matrix* Matrix_multiply(Matrix l_mtx, Matrix r_mtx);

/**
 * Simple print function with label
 *
 * @param mtx matrix to print
 * @param label that will be printed before matrix
 */
void Matrix_print_matrix(Matrix mtx, std::string label);

/**
 * Simple create matrix function, that fills it with random values
 *
 * @param n_row new matrix height
 * @param n_col new matrix width
 * @return new filled matrix
 */
Matrix* Matrix_get_random_matrix(int n_row, int n_col);

/**
* Memory allocation
*
* @param  new matrix height
* @param  new matrix width
* @return new empty matrix
 */
Matrix* Matrix_get_empty_matrix(int n_row, int n_col);

/**
 * Memory clear function
 */
void Matrix_delete_matrix(Matrix* mtx);

/**
 * Simple create matrix function, that fills it with entered values
 *
 * @param  new matrix height
 * @param  new matrix width
 * @return new filled matrix
 */
Matrix* Matrix_enter_matrix(int n_row, int n_col);

/**
 * Reducing matrices to the required size
 *
 * Reduces matrix to the required size
 * by making copy with data from imported matrix,
 * used for squar matrices only
 *
 * @param i_mtx
 * @param mtx_size
 * @return new matrix with data from i_mtx
 */
Matrix* Matrix_get_sized_matrix(Matrix i_mtx, int mtx_size);

/**
 * Dividing matrices into submatrices and filling them in
 *
 * Dividing matrices into submatrices and filling them in,
 * by making copy with data from imported matrix
 *
 * @param i_mtx input matrix for data
 * @param n_row height of new matrix
 * @param n_col width of new matrix
 * @param i_offset row offset to fill new matrix
 * @param j_offset column offset to fill new matrix
 * @return new filled submatrix
 */
Matrix* Matrix_get_filled_submatrix(Matrix i_mtx, int n_row, int n_col, int i_offset, int j_offset);

/**
 * Matrix copy function
 *
 * Matrix copy function, that uses Matrix_get_filled_submatrix for copy
 *
 * @param i_mtx input matrix for data
 * @param n_row height of new matrix
 * @param n_col width of new matrix
 * @return new filled matrix
 */
Matrix* Matrix_get_filled_matrix(Matrix i_mtx, int n_row, int n_col);

/**
 * Returns fixed height (rows number)
 *
 * Checks boarder of not zero data and returns it's boarder
 * Simular to Matrix_get_fixed_width(Matrix)
 *
 * @return not zero data height boarder
 */
int Matrix_get_fixed_height(Matrix mtx);

/**
 * Returns fixed width (columns number)
 *
 * Checks boarder of not zero data and returns it's boarder
 * Simular to Matrix_get_fixed_height(Matrix)
 *
 * @return not zero data width boarder
 */
int Matrix_get_fixed_width(Matrix mtx);
