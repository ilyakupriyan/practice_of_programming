#include <iostream>
#include <conio.h>
#include <time.h>

using namespace std;

void swap (int* var1, int* var2) {
	int temp = *var1;
	*var1 = *var2;
	*var2 = temp;
}

void bubbleSort(int* array) {
	int flag = 0;
	for (int i = 0; i < 9; i++) {
		flag = 0;
		for (int a = 0; a < 9 - i; a++) {
			if (array[a] > array[a + 1]) {
				swap(&array[a], &array[a + 1]);
				flag = 1;
			}
		}
		if (!flag)
			break;
	}
		
}

int main() {
	srand(time(NULL));
	int mass[10];
	for (int i = 0; i <= 9; i++) {
		mass[i] = rand() % 50;
		cout << mass[i] << " ";
	}
	cout << endl;
	bubbleSort(mass);
	for (int i = 0; i <= 9; i++) {
		cout << mass[i] << " ";
	}
	_getch();
	return 0;
}