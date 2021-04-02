#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

void swap(uint16_t* var1, uint16_t* var2) {
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

void cocktailSort(uint16_t* arr, int size) {
	int left_lim = 0, right_lim = size - 1, count = 0;
	while (left_lim <= right_lim) {
		for (int i = left_lim; i < right_lim; i++)
			if (arr[i] > arr[i + 1])
				swap(&arr[i], &arr[i + 1]);
		right_lim--;
		for (int i = right_lim; i > left_lim; i--)
			if (arr[i] < arr[i - 1])
				swap(&arr[i], &arr[i - 1]);
		left_lim++;
		count++;
	}
	cout << "Number of iterations: " << count << endl;
}

int main() {
	srand(time(NULL));
	int16_t size, max;
	cout << "Enter the size of array and maximum possible number" << endl;
	cin >> size >> max;
	uint16_t* array = (uint16_t*) calloc (size, sizeof(int));
	for (int i = 0; i < size; i++) {
		array[i] = rand() % max;
		cout << array[i] << " ";
	}
	cout << endl;
	cocktailSort(array, size);
	for (int i = 0; i < size; i++) 
		cout << array[i] << " ";
	free(array);
	_getch();
	return 0;
}