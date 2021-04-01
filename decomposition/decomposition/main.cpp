#include <iostream>
#include <conio.h>

using namespace std;

int main(void) {
	int num = 0, rank = 0, digit = 1, degree = 1; //degree - 10 в какой-то степени
	cout << "Enter a number ";
	cin >> num;
	int num_copy = num;
	do {
		digit = num / degree;
		if (digit != 0) {
			rank++;
			degree *= 10;
		}
	} while (digit);
	rank--;
	degree /= 10;
	cout << num << " = ";
	for (int i = rank; i >= 0; i--) {
		digit = num_copy / degree;
		cout << digit << "*10^" << i;
		if (i != 0)
			cout << " + ";
		num_copy -= digit * degree;
		degree /= 10;
	}
	_getch();
	return 0;
}
