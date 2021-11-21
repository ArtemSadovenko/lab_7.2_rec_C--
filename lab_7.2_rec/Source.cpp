#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void create(int** a, int col, int row, int l, int h, int i, int j);
void print(int** a, int row, int col, int i, int j);
void change(int** a, int row, int col, int j);
int max(int** a, int row, int j, int i, int i_max, int a_max);
int min(int** a, int row, int j, int i, int i_min, int a_min);


void main() {
	srand((unsigned)time(NULL));

	int k = 10;
	int n = 6;

	int l = -15;
	int h = 15;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	create(a, n, k, l, h, 0, 0);

	print(a, k, n, 0, 0);

	change(a, k, n, 1);

	print(a, k, n, 0, 0);

	for (int i = 0; i < k; i++) 
		delete[] a[i]; 
	delete[] a;
}

void create(int** a, int col, int row, int l, int h, int i, int j) {
	a[i][j] = l + rand() % (h - l + 1);
	if (j < col - 1) {
		create(a, col, row, l, h, i, j + 1);
	}
	else if (i < row - 1) {
		create(a, col, row, l, h, i + 1, 0);
	}
	else {
		cout << endl;
	}
}

void print(int** a, int row, int col, int i, int j) {

	if (j == 0) {
		cout << "|";
	}

	cout << setw(4) << a[i][j] << " ";

	if (j == col - 1) {
		cout << "|\n";
	}

	if (j < col - 1) {
		print(a, row, col, i, j + 1);
	}
	else if (i < row - 1) {
		print(a, row, col, i+1, 0);
	}
	else {
		cout << endl;
	}
}


void change(int** a, int row, int col, int j) {
	int i_max;
	int i_min;
	int tmp;
	
	
		i_max = max(a, row, j - 1, 0, 0, a[0][0]);
		i_min = min(a, row, j, 0, 0, a[0][0]);
		tmp = a[i_max][j - 1];
		a[i_max][j - 1] = a[i_min][j];
		a[i_min][j] = tmp; 
	
	
	if (j <= col / 2) {
		change(a, row, col, j + 2);
	}
}

int max(int** a, int row, int j, int i, int i_max, int a_max) {
	if (a[i][j] > a_max) {
		a_max = a[i][j];
		i_max = i;
	}

	if (i < row - 1) {
		return max(a, row, j, i + 1, i_max, a_max);
	}
	else return i_max;
}

int min(int** a, int row, int j, int i, int i_min, int a_min) {
	if (a[i][j] < a_min) {
		a_min = a[i][j];
		i_min = i;
	}

	if (i < row - 1) {
		return min(a, row, j, i + 1, i_min, a_min);
	}
	else return i_min;
}