#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Matrix/matrix.hpp"
using namespace std;

static int input(int left_boarder, int right_boarder, string label);

int main() {
  system("clear");
	srand(time(NULL));
	int n_row1, n_col1, n_row2, n_col2, choice;
  Matrix* mtx1;
  Matrix* mtx2;

	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	cout << "Введите размеры первой матрицы\n";
  n_row1 = input(0, 50, "Кол-во столбцов");
  n_col1 = input(0, 50, "Кол-во строк");

	cout << "Введите размеры второй матрицы\n";
  n_row2 = input(0, 50, "Кол-во столбцов");
  n_col2 = input(0, 50, "Кол-во строк");

  cout << "Выберите способ заполнения матриц\n" <<
    "1 - Вручную \n2 - Случайным образом\n";
	choice = input(1, 2, "Кол-во строк");

	switch (choice) {
	case 1:
    mtx1 = Matrix_enter_matrix(n_row1, n_col1);
    mtx2 = Matrix_enter_matrix(n_row2, n_col2);
    Matrix_print_matrix(*mtx1, "\nМатрица 1\n\n");
    Matrix_print_matrix(*mtx2, "\nМатрица 2\n\n");
		break;
	case 2:
    mtx1 = Matrix_get_random_matrix(n_row1, n_col1);
    mtx2 = Matrix_get_random_matrix(n_row2, n_col2);
    Matrix_print_matrix(*mtx1, "\nМатрица 1\n\n");
    Matrix_print_matrix(*mtx2, "\nМатрица 2\n\n");
		break;
	}

  Matrix* result_mtx = Matrix_multiply(*mtx1, *mtx2);
  Matrix_print_matrix(*result_mtx, "\nРезультирующая матрица\n\n");

  Matrix_delete_matrix(mtx1);
  Matrix_delete_matrix(mtx2);
  Matrix_delete_matrix(result_mtx);

  return 0;
}

static int input(int left_boarder, int right_boarder, string label) {
  int number;
  do {
    cout << label << '\n';
    cin >> number;
	} while (number < left_boarder || number > right_boarder);
  return number;
}
