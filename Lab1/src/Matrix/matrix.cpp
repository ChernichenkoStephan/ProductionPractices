#include <iostream>

#include "matrix.hpp"

void Matrix_print_matrix(int** mtx, int n_row, int n_col, std::string label) {
  std::cout << label << '\n';
  for (int i = 0; i < n_row; i++) {
      for (int j = 0; j < n_col; j++)
        std::cout << mtx[i][j] << " ";
      std::cout << '\n';
  }
}

int** Matrix_get_random_matrix(int n_row, int n_col) {
  int** mtx = new int* [n_row];
  for (int i = 0; i < n_row; i++) {
      mtx[i] = new int[n_col];
      for (int j = 0; j < n_col; j++)
        mtx[i][j] = 2;//rand() % 10;
  }
  return mtx;
}

int** Matrix_get_empty_matrix(int n_row, int n_col) {
  int** mtx = new int* [n_row];
  for (int i = 0; i < n_row; i++)
      mtx[i] = new int[n_col];
  return mtx;
}

void Matrix_delete_matrix(int** mtx, int n_row) {
  for (int i = 0; i < n_row; i++)
		delete[] mtx[i];
  delete[] mtx;
}

int** Matrix_enter_matrix(int n_row, int n_col) {
  int** mtx = new int* [n_row];
  for (int i = 0; i < n_row; i++) {
    mtx[i] = new int[n_col];
    for (int j = 0; j < n_col; j++)
      std::cin >> mtx[i][j];
  }
  return mtx;
}

int** Matrix_get_sized_matrix(int** i_mtx, int mtx_size, int n_row, int n_col) {
  int** mtx = new int* [mtx_size];
	for (int i = 0; i < mtx_size; i++)
	{
		mtx[i] = new int[mtx_size];
		for (int j = 0; j < mtx_size; j++)
			mtx[i][j] = 0;
	}
  for (int i = 0; i < n_row; i++)
	{
		for (int j = 0; j < n_col; j++)
			mtx[i][j] = i_mtx[i][j];
	}
  return mtx;
}

int** Matrix_get_filled_submatrix(int** i_mtx, int n_row, int n_col, int i_offset, int j_offset) {
  int** mtx = new int* [n_row];
  for (int i = 0; i < n_row; i++) {
      mtx[i] = new int[n_col];
      for (int j = 0; j < n_col; j++)
        mtx[i][j] = i_mtx[i + i_offset][j + j_offset];
  }
  return mtx;
}

int** Matrix_get_filled_matrix(int** i_mtx, int n_row, int n_col) {
  return Matrix_get_filled_submatrix(i_mtx, n_row, n_col, 0, 0);
}

int Matrix_get_fixed_height(int** mtx, int mtx_size) {
  int height = 100, x = 0;

  for (int i = 0; i < mtx_size; i++) {
    x = 0;
    for (int j = 0; j < mtx_size; j++) {
      if (mtx[i][j] != 0) {
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

int Matrix_get_fixed_width(int** mtx, int mtx_size) {
  int width = 100, x = 0;

  for (int i = 0; i < mtx_size; i++) {
    x = 0;
    for (int j = 0; j < mtx_size; j++) {
      if (mtx[j][i] != 0) {
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

int** Matrix_multiply(int** mtx1, int** mtx2, int n_row1, int n_col1, int n_row2, int n_col2) {
  int mtx_size = 2;
  // Размер промежуточной матрицы
	while (mtx_size < n_row1 || mtx_size < n_row2 || mtx_size < n_col1 || mtx_size < n_col2)
		mtx_size *= 2;
  int half_mtx_size = mtx_size / 2;

  // Приведение матриц к требуемому размеру
  int** sized_mtx1 = Matrix_get_sized_matrix(mtx1, mtx_size, n_row1, n_col1);
  int** sized_mtx2 = Matrix_get_sized_matrix(mtx2, mtx_size, n_row2, n_col2);

	std::cout << "Приведенные матрицы\n";
  Matrix_print_matrix(sized_mtx1, mtx_size, mtx_size, "\nМатрица 1\n\n");
  Matrix_print_matrix(sized_mtx2, mtx_size, mtx_size, "\nМатрица 2\n\n");

  // Разбиение матриц на подматрицы и их заполнение
  int** help_mtx1 = Matrix_get_filled_submatrix(sized_mtx1, half_mtx_size, half_mtx_size, 0, 0);
  int** help_mtx2 = Matrix_get_filled_submatrix(sized_mtx1, half_mtx_size, half_mtx_size, 0, half_mtx_size);
  int** help_mtx3 = Matrix_get_filled_submatrix(sized_mtx1, half_mtx_size, half_mtx_size, half_mtx_size, 0);
  int** help_mtx4 = Matrix_get_filled_submatrix(sized_mtx1, half_mtx_size, half_mtx_size, half_mtx_size, half_mtx_size);
  int** help_mtx5 = Matrix_get_filled_submatrix(sized_mtx2, half_mtx_size, half_mtx_size, 0, 0);
  int** help_mtx6 = Matrix_get_filled_submatrix(sized_mtx2, half_mtx_size, half_mtx_size, 0, half_mtx_size);
  int** help_mtx7 = Matrix_get_filled_submatrix(sized_mtx2, half_mtx_size, half_mtx_size, half_mtx_size, 0);
  int** help_mtx8 = Matrix_get_filled_submatrix(sized_mtx2, half_mtx_size, half_mtx_size, half_mtx_size, half_mtx_size);

  // Вычисление значений промежуточных матриц
  int** intermediate_mtx1 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  int** intermediate_mtx2 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  int** intermediate_mtx3 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  int** intermediate_mtx4 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  int** intermediate_mtx5 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  int** intermediate_mtx6 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
  int** intermediate_mtx7 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);

  // Вычисление значений промежуточных матриц
	for (int i = 0; i < half_mtx_size; i++) {
		for (int j = 0; j < half_mtx_size; j++) {
			intermediate_mtx1[i][j] = 0;
      intermediate_mtx2[i][j] = 0;
      intermediate_mtx3[i][j] = 0;
      intermediate_mtx4[i][j] = 0;
      intermediate_mtx5[i][j] = 0;
      intermediate_mtx6[i][j] = 0;
      intermediate_mtx7[i][j] = 0;
			for (int z = 0; z < half_mtx_size; z++) {
        intermediate_mtx1[i][j] += (help_mtx1[i][z] + help_mtx4[i][z]) * (help_mtx5[z][j] + help_mtx8[z][j]);
        intermediate_mtx2[i][j] += (help_mtx3[i][z] + help_mtx4[i][z]) * help_mtx5[z][j];
        intermediate_mtx3[i][j] +=  help_mtx1[i][z] * (help_mtx6[z][j] - help_mtx8[z][j]);
        intermediate_mtx4[i][j] +=  help_mtx4[i][z] * (help_mtx7[z][j] - help_mtx5[z][j]);
        intermediate_mtx5[i][j] += (help_mtx1[i][z] + help_mtx2[i][z]) * help_mtx8[z][j];
        intermediate_mtx6[i][j] += (help_mtx3[i][z] - help_mtx1[i][z]) * (help_mtx5[z][j] + help_mtx6[z][j]);
        intermediate_mtx7[i][j] += (help_mtx2[i][z] - help_mtx4[i][z]) * (help_mtx7[z][j] + help_mtx8[z][j]);
			}
		}
	}

  int** help_mtx9  = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
	int** help_mtx10 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
	int** help_mtx11 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);
	int** help_mtx12 = Matrix_get_empty_matrix(half_mtx_size, half_mtx_size);

  //Подсчет значений вспомогательных матриц из промежуточных
	for (int i = 0; i < half_mtx_size; i++) {
		for (int j = 0; j < half_mtx_size; j++) {
			help_mtx9[i][j]  = intermediate_mtx1[i][j] + intermediate_mtx4[i][j] - intermediate_mtx5[i][j] + intermediate_mtx7[i][j];
			help_mtx10[i][j] = intermediate_mtx3[i][j] + intermediate_mtx5[i][j];
			help_mtx11[i][j] = intermediate_mtx2[i][j] + intermediate_mtx4[i][j];
			help_mtx12[i][j] = intermediate_mtx1[i][j] - intermediate_mtx2[i][j] + intermediate_mtx3[i][j] + intermediate_mtx6[i][j];
		}
	}

  int** sized_mtx3 = Matrix_get_empty_matrix(mtx_size, mtx_size);

  // Занесение информации из вспомогательных матриц в результирующую
	for (int i = 0; i < half_mtx_size; i++) {
		for (int j = 0; j < half_mtx_size; j++) {
			sized_mtx3[i][j] = help_mtx9[i][j];
			sized_mtx3[i][j + half_mtx_size] = help_mtx10[i][j];
			sized_mtx3[i + half_mtx_size][j] = help_mtx11[i][j];
			sized_mtx3[i + half_mtx_size][j + half_mtx_size] = help_mtx12[i][j];
		}
	}

  // Выравнивание границ результирующей матрицы
  int sized_mtx_n_row = Matrix_get_fixed_height(sized_mtx3, mtx_size);
  int sized_mtx_n_col = Matrix_get_fixed_width(sized_mtx3, mtx_size);

  // Получение результирующей матрицы
	int** result_mtx = Matrix_get_filled_matrix(sized_mtx3, sized_mtx_n_row, sized_mtx_n_col);

  Matrix_print_matrix(result_mtx, sized_mtx_n_row, sized_mtx_n_col, "\nРезультирующая матрица\n\n");

  Matrix_delete_matrix(sized_mtx1, mtx_size);
  Matrix_delete_matrix(sized_mtx2, mtx_size);
  Matrix_delete_matrix(sized_mtx3, mtx_size);
  Matrix_delete_matrix(result_mtx, sized_mtx_n_row);
	Matrix_delete_matrix(help_mtx1, half_mtx_size);
	Matrix_delete_matrix(help_mtx2, half_mtx_size);
	Matrix_delete_matrix(help_mtx3, half_mtx_size);
	Matrix_delete_matrix(help_mtx4, half_mtx_size);
	Matrix_delete_matrix(help_mtx5, half_mtx_size);
	Matrix_delete_matrix(help_mtx6, half_mtx_size);
	Matrix_delete_matrix(help_mtx7, half_mtx_size);
	Matrix_delete_matrix(help_mtx8, half_mtx_size);
	Matrix_delete_matrix(help_mtx9, half_mtx_size);
	Matrix_delete_matrix(help_mtx10, half_mtx_size);
	Matrix_delete_matrix(help_mtx11, half_mtx_size);
	Matrix_delete_matrix(help_mtx12, half_mtx_size);
	Matrix_delete_matrix(intermediate_mtx1, half_mtx_size);
	Matrix_delete_matrix(intermediate_mtx2, half_mtx_size);
	Matrix_delete_matrix(intermediate_mtx3, half_mtx_size);
	Matrix_delete_matrix(intermediate_mtx4, half_mtx_size);
	Matrix_delete_matrix(intermediate_mtx5, half_mtx_size);
	Matrix_delete_matrix(intermediate_mtx6, half_mtx_size);
	Matrix_delete_matrix(intermediate_mtx7, half_mtx_size);
}
