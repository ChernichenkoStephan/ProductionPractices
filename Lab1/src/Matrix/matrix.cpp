#include <iostream>

#include "matrix.hpp"

void Matrix_print_matrix(Matrix mtx, std::string label) {
  std::cout << label << std::endl;
  for (int i = 0; i < mtx.n_row; i++) {
      for (int j = 0; j < mtx.n_col; j++)
        std::cout << mtx.value[i][j] << " ";
      std::cout << std::endl;
  }
}

Matrix* Matrix_get_random_matrix(int n_row, int n_col) {
  Matrix* mtx = new Matrix();
  mtx->n_row = n_row;
  mtx->n_col = n_col;
  mtx->value = new int* [n_row];
  for (int i = 0; i < n_row; i++) {
    mtx->value[i] = new int[n_col];
    for (int j = 0; j < n_col; j++)
      mtx->value[i][j] = rand() % 10;
  }
  return mtx;
}

Matrix* Matrix_get_empty_matrix(int n_row, int n_col) {
  Matrix* mtx = new Matrix();
  mtx->n_row = n_row;
  mtx->n_col = n_col;
  mtx->value = new int* [n_row];
  for (int i = 0; i < n_row; i++)
      mtx->value[i] = new int[n_col];
  return mtx;
}

void Matrix_delete_matrix(Matrix* mtx) {
  for (int i = 0; i < mtx->n_row; i++)
		delete[] mtx->value[i];
  delete[] mtx->value;
  delete[] mtx;
}

Matrix* Matrix_enter_matrix(int n_row, int n_col) {
  Matrix* mtx = new Matrix();
  mtx->n_row = n_row;
  mtx->n_col = n_col;
  mtx->value = new int* [n_row];
  for (int i = 0; i < n_row; i++) {
    mtx->value[i] = new int[n_col];
    for (int j = 0; j < n_col; j++)
      std::cin >> mtx->value[i][j];
  }
  return mtx;
}

Matrix* Matrix_get_sized_matrix(Matrix i_mtx, int mtx_size) {
  Matrix* mtx = new Matrix();
  mtx->n_row = mtx_size;
  mtx->n_col = mtx_size;
  mtx->value = new int* [mtx_size];

	for (int i = 0; i < mtx_size; i++) {
		mtx->value[i] = new int[mtx_size];
		for (int j = 0; j < mtx_size; j++)
			mtx->value[i][j] = 0;
	}

  for (int i = 0; i < i_mtx.n_row; i++)
		for (int j = 0; j < i_mtx.n_col; j++)
			mtx->value[i][j] = i_mtx.value[i][j];

  return mtx;
}

Matrix* Matrix_get_filled_submatrix(Matrix i_mtx, int n_row, int n_col, int i_offset, int j_offset) {
  Matrix* mtx = new Matrix();
  mtx->n_row = n_row;
  mtx->n_col = n_col;
  mtx->value = new int* [n_row];

  for (int i = 0; i < n_row; i++) {
      mtx->value[i] = new int[n_col];
      for (int j = 0; j < n_col; j++)
        mtx->value[i][j] = i_mtx.value[i + i_offset][j + j_offset];
  }
  return mtx;
}

Matrix* Matrix_get_filled_matrix(Matrix i_mtx, int n_row, int n_col) {
  return Matrix_get_filled_submatrix(i_mtx, n_row, n_col, 0, 0);
}

int Matrix_get_fixed_height(Matrix mtx) {
  int height = 100, x = 0;

  for (int i = 0; i < mtx.n_row; i++) {
    x = 0;
    for (int j = 0; j < mtx.n_col; j++) {
      if (mtx.value[i][j] != 0) {
        x++;
        height = 100;
      }
    }
    if (x == 0 && i < height) {
      height = i;
    }
  }

  return height;
}

int Matrix_get_fixed_width(Matrix mtx) {
  int width = 100, x = 0;

  for (int i = 0; i < mtx.n_row; i++) {
    x = 0;
    for (int j = 0; j < mtx.n_col; j++) {
      if (mtx.value[j][i] != 0) {
        x++;
        width = 100;
      }
    }
    if (x == 0 && i < width) {
      width = i;
    }
  }
  return width;
}

Matrix* Matrix_multiply(Matrix l_mtx, Matrix r_mtx) {
  int mtx_size = 2;
  // Intermediate matrix size
  while (mtx_size < l_mtx.n_row || mtx_size < r_mtx.n_row ||
         mtx_size < l_mtx.n_col || mtx_size < r_mtx.n_col)
    mtx_size *= 2;
  int half_mtx_size = mtx_size / 2;

  // Reducing matrices to the required size
  Matrix* sized_mtx1 = Matrix_get_sized_matrix(l_mtx, mtx_size);
  Matrix* sized_mtx2 = Matrix_get_sized_matrix(r_mtx, mtx_size);

  std::cout << "Приведенные матрицы\n";
  Matrix_print_matrix(*sized_mtx1, "\nМатрица 1\n\n");
  Matrix_print_matrix(*sized_mtx2, "\nМатрица 2\n\n");

  // Dividing matrices into submatrices and filling them in
  Matrix* help_mtx1 = Matrix_get_filled_submatrix(*sized_mtx1, half_mtx_size,
                                                  half_mtx_size, 0, 0);
  Matrix* help_mtx2 = Matrix_get_filled_submatrix(*sized_mtx1, half_mtx_size,
                                                  half_mtx_size, 0, half_mtx_size);
  Matrix* help_mtx3 = Matrix_get_filled_submatrix(*sized_mtx1, half_mtx_size,
                                                  half_mtx_size, half_mtx_size, 0);
  Matrix* help_mtx4 = Matrix_get_filled_submatrix(*sized_mtx1, half_mtx_size,
                                                  half_mtx_size, half_mtx_size, half_mtx_size);
  Matrix* help_mtx5 = Matrix_get_filled_submatrix(*sized_mtx2, half_mtx_size,
                                                  half_mtx_size, 0, 0);
  Matrix* help_mtx6 = Matrix_get_filled_submatrix(*sized_mtx2, half_mtx_size,
                                                  half_mtx_size, 0, half_mtx_size);
  Matrix* help_mtx7 = Matrix_get_filled_submatrix(*sized_mtx2, half_mtx_size,
                                                  half_mtx_size, half_mtx_size, 0);
  Matrix* help_mtx8 = Matrix_get_filled_submatrix(*sized_mtx2, half_mtx_size,
                                                  half_mtx_size, half_mtx_size, half_mtx_size);

  // Calculation of intermediate matrix values
  Matrix* intermediate_mtx1 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* intermediate_mtx2 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* intermediate_mtx3 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* intermediate_mtx4 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* intermediate_mtx5 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* intermediate_mtx6 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* intermediate_mtx7 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);

  // Calculation of intermediate matrix values
  for (int i = 0; i < half_mtx_size; i++) {
    for (int j = 0; j < half_mtx_size; j++) {
      intermediate_mtx1->value[i][j] = 0;
      intermediate_mtx2->value[i][j] = 0;
      intermediate_mtx3->value[i][j] = 0;
      intermediate_mtx4->value[i][j] = 0;
      intermediate_mtx5->value[i][j] = 0;
      intermediate_mtx6->value[i][j] = 0;
      intermediate_mtx7->value[i][j] = 0;
      for (int z = 0; z < half_mtx_size; z++) {
        intermediate_mtx1->value[i][j] += (help_mtx1->value[i][z] + help_mtx4->value[i][z]) *
                                          (help_mtx5->value[z][j] + help_mtx8->value[z][j]);
        intermediate_mtx2->value[i][j] += (help_mtx3->value[i][z] + help_mtx4->value[i][z]) *
                                           help_mtx5->value[z][j];
        intermediate_mtx3->value[i][j] +=  help_mtx1->value[i][z] * (help_mtx6->value[z][j] -
                                           help_mtx8->value[z][j]);
        intermediate_mtx4->value[i][j] +=  help_mtx4->value[i][z] * (help_mtx7->value[z][j] -
                                           help_mtx5->value[z][j]);
        intermediate_mtx5->value[i][j] += (help_mtx1->value[i][z] + help_mtx2->value[i][z]) *
                                          help_mtx8->value[z][j];
        intermediate_mtx6->value[i][j] += (help_mtx3->value[i][z] - help_mtx1->value[i][z]) *
                                          (help_mtx5->value[z][j] + help_mtx6->value[z][j]);
        intermediate_mtx7->value[i][j] += (help_mtx2->value[i][z] - help_mtx4->value[i][z]) *
                                          (help_mtx7->value[z][j] + help_mtx8->value[z][j]);
          }
        }
      }

  Matrix* help_mtx9  = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* help_mtx10 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* help_mtx11 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  Matrix* help_mtx12 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);

  // Counting the values of auxiliary matrices from intermediate
  for (int i = 0; i < half_mtx_size; i++) {
    for (int j = 0; j < half_mtx_size; j++) {
      help_mtx9->value[i][j]  = intermediate_mtx1->value[i][j] + intermediate_mtx4->value[i][j] -
          intermediate_mtx5->value[i][j] + intermediate_mtx7->value[i][j];
      help_mtx10->value[i][j] = intermediate_mtx3->value[i][j] + intermediate_mtx5->value[i][j];
      help_mtx11->value[i][j] = intermediate_mtx2->value[i][j] + intermediate_mtx4->value[i][j];
      help_mtx12->value[i][j] = intermediate_mtx1->value[i][j] - intermediate_mtx2->value[i][j] +
          intermediate_mtx3->value[i][j] + intermediate_mtx6->value[i][j];
        }
      }

  Matrix* preresult_mtx = Matrix_get_empty_matrix(mtx_size, mtx_size);

  // Entering information from auxiliary matrices into the resulting
  for (int i = 0; i < half_mtx_size; i++) {
    for (int j = 0; j < half_mtx_size; j++) {
      preresult_mtx->value[i][j] = help_mtx9->value[i][j];
      preresult_mtx->value[i][j + half_mtx_size] = help_mtx10->value[i][j];
      preresult_mtx->value[i + half_mtx_size][j] = help_mtx11->value[i][j];
      preresult_mtx->value[i + half_mtx_size][j + half_mtx_size] = help_mtx12->value[i][j];
    }
  }

  // Aligning the bounds of the resulting matrix
  int sized_mtx_n_row = Matrix_get_fixed_height(*preresult_mtx);
  int sized_mtx_n_col = Matrix_get_fixed_width(*preresult_mtx);

  // Getting the resulting matrix
  Matrix* result_mtx = Matrix_get_filled_matrix(*preresult_mtx, sized_mtx_n_row, sized_mtx_n_col);

  Matrix_delete_matrix(sized_mtx1);
  Matrix_delete_matrix(sized_mtx2);
  Matrix_delete_matrix(preresult_mtx);
  Matrix_delete_matrix(help_mtx1);
  Matrix_delete_matrix(help_mtx2);
  Matrix_delete_matrix(help_mtx3);
  Matrix_delete_matrix(help_mtx4);
  Matrix_delete_matrix(help_mtx5);
  Matrix_delete_matrix(help_mtx6);
  Matrix_delete_matrix(help_mtx7);
  Matrix_delete_matrix(help_mtx8);
  Matrix_delete_matrix(help_mtx9);
  Matrix_delete_matrix(help_mtx10);
  Matrix_delete_matrix(help_mtx11);
  Matrix_delete_matrix(help_mtx12);
  Matrix_delete_matrix(intermediate_mtx1);
  Matrix_delete_matrix(intermediate_mtx2);
  Matrix_delete_matrix(intermediate_mtx3);
  Matrix_delete_matrix(intermediate_mtx4);
  Matrix_delete_matrix(intermediate_mtx5);
  Matrix_delete_matrix(intermediate_mtx6);
  Matrix_delete_matrix(intermediate_mtx7);

  return result_mtx;
}
