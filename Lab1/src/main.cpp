#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Matrix/matrix.hpp"
using namespace std;

int input(int left_boarder, int right_boarder, string label);

int main() {
  system("clear");
	srand(time(NULL));
	int n_row1, n_col1, n_row2, n_col2, choice;
  int** mtx1;
	int** mtx2;

	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	cout << "Введите размеры первой матрицы\n";
  n_row1 = 10;//input(0, 50, "Кол-во столбцов");
  n_col1 = 10;//input(0, 50, "Кол-во строк");

	cout << "Введите размеры второй матрицы\n";
  n_row2 = 10;//input(0, 50, "Кол-во столбцов");
  n_col2 = 10;//input(0, 50, "Кол-во строк");

  cout << "Выберите способ заполнения матриц\n" <<
    "1 - Вручную \n2 - Случайным образом\n";
	choice = 2;//input(1, 2, "Кол-во строк");

	switch (choice) {
	case 1:
    mtx1 = Matrix_enter_matrix(n_row1, n_col1);
    mtx2 = Matrix_enter_matrix(n_row2, n_col2);

    Matrix_print_matrix(mtx1, n_row1, n_col1, "\nМатрица 1\n\n");
    Matrix_print_matrix(mtx2, n_row2, n_col2, "\nМатрица 2\n\n");
		break;
	case 2:
    mtx1 = Matrix_get_random_matrix(n_row1, n_col1);
    mtx2 = Matrix_get_random_matrix(n_row2, n_col2);

    Matrix_print_matrix(mtx1, n_row1, n_col1, "\nМатрица 1\n\n");
    Matrix_print_matrix(mtx2, n_row2, n_col2, "\nМатрица 2\n\n");
		break;
	}

  Matrix_multiply(mtx1, mtx2, n_row1, n_col1, n_row2, n_col2);

  Matrix_delete_matrix(mtx1, n_row1);
  Matrix_delete_matrix(mtx2, n_row2);

  return 0;
}

int input(int left_boarder, int right_boarder, string label) {
  int number;
  do {
    cout << label << '\n';
    cin >> number;
	} while (number < left_boarder || number > right_boarder);
  return number;
}
