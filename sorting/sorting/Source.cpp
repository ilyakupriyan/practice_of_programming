#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

void swap(uint16_t* var1, uint16_t* var2) {
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

void qSort(uint16_t* arr, int left_lim, int right_lim, int* count) {
	if (left_lim < right_lim) {
		int l_lim = left_lim, r_lim = right_lim, //переменные для хранения индексов массива, которые нужно перекинуть на другую сторону от опорного элемента, и границ
			mid = (arr[left_lim] + arr[right_lim]) / 2; //вычисление опорного элемента
		while (l_lim < r_lim) {
			//находим элемент слева от опорного, который нужно перебросить на правую сторону
			while (mid > arr[l_lim]) l_lim++;
			//находим элемент справа от опорного, который нужно перебросить на левую сторону
			while (mid < arr[r_lim]) r_lim--;
			//меняем местами выбранные элементы,если требуется
			if (l_lim <= r_lim) {
				swap(&arr[l_lim], &arr[r_lim]);
				r_lim--;
				l_lim++;
				*count += 1;
			}
		}
		//запускаем рекурсию для двух частей массива
		if (left_lim < r_lim) qSort(arr, left_lim, r_lim, count);
		if (right_lim > l_lim) qSort(arr, l_lim, right_lim, count);
	}
}

int main() {
	srand(time(NULL));
	int16_t size, max;
	int count = 0;
	cout << "Enter the size of array and maximum possible number" << endl;
	cin >> size >> max;
	uint16_t* array = (uint16_t*) calloc (size, sizeof(int));
	for (int i = 0; i < size; i++) {
		array[i] = rand() % max + 1;
		cout << array[i] << " ";
	}
	cout << endl;
	qSort(array, 0, size-1, &count);
	for (int i = 0; i < size; i++) 
		cout << array[i] << " ";
	cout << endl << "Number of iterations of sorting: " << count;
	free(array);
	_getch();
	return 0;
}