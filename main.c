#include <stdio.h>

#define n 5

void show_arr(int arr[n][n]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = j + n * i;
			printf(" %d ", arr[i][j]);
		}
		printf("\n");
	}
}

void swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void show_reverse(int* arr) {

	int middle = n / 2;

	for (int i = 0; i < middle; i++) {
		swap(&arr[i], &arr[n - i  - 1]);
	}
	for (int i = 0; i < n; i++) {
		printf(" %d ",arr[i]);
	}

	printf("\n");
	
}

void fill_by_triangle(int arr[n][n]) {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			arr[i][j] = 0;
			printf(" %d ", arr[i][j]);
		}
		for (int j = n - i; j < n; j++) {
			arr[i][j] = 1;
			printf(" %d ", arr[i][j]);
		}
		printf("\n");
	}
}

void fill_by_snail(int arr[n][n]) {

	int Ibeg = 0, Ifin = 0, Jbeg = 0, Jfin = 0;

	int k = 1;
	int i = 0;
	int j = 0;

	while (k <= n * n) {
		arr[i][j] = k;
		if (i == Ibeg && j < n - Jfin - 1)
			++j;
		else if (j == n - Jfin - 1 && i < n - Ifin - 1)
			++i;
		else if (i == n - Ifin - 1 && j > Jbeg)
			--j;
		else
			--i;

		if ((i == Ibeg + 1) && (j == Jbeg) && (Jbeg != n - Jfin - 1)) {
			++Ibeg;
			++Ifin;
			++Jbeg;
			++Jfin;
		}
		++k;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			printf(" %d ", arr[i][j]);
		printf("\n");
	}
}

int main() {

	int arr_s[n][n];
	int arr[n];
	
	for (int i = 0; i < n; i++) {
		arr[i] = i;
		for (int j = 0; j < n; j++) {
			arr_s[i][j] = j + n * i;
		}
	}

	show_arr(arr_s);
	show_reverse(arr);
	fill_by_triangle(arr_s);
	fill_by_snail(arr_s);

}