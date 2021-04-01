#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

int main() {
	int num = 0, in_base, out_base, rank = 0, pos;
	string number;
	char sys[25] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'L', 'M', 'N', 'O', 'P', 'Q'};
	cout << "Enter input number system, output number system and number" << endl;
	cin >> in_base >> out_base >> number;
	/*������� �� ������������ ������� ��������� (��) � ����������*/
	if (in_base != 10) {
		int copy_in_base = 1;
		for (int i = number.size() - 1; i >= 0; i--) { //��������� � ������� ����������� ������� �����
			number[i] = (char)toupper(number[i]); //��������� ��� ��������� ����� � ������� ������� ��� ������������ �������� � ������ ��
			num += ((int)number[i] - ((int)number[i] < 61 ? 48 : 55)) * copy_in_base;
			copy_in_base *= in_base;
		}
	}
	//cout << num;
	/*������� �� ���������� ������� ��������� � ������������ (���� ���������)*/
	if (out_base != 10) {
		int copy_out_base = 1; //��������� ��� ������������ ��������
		int num_copy = num;
		//���������� ������������ �������, ������� ������ �����
		while (num >= copy_out_base) {
			copy_out_base *= out_base;
			rank++;
		}
		copy_out_base /= out_base;
		rank--;

		for (int i = rank; i >= 0; i--) {
			pos = num_copy / copy_out_base;
			num_copy %= copy_out_base;
			copy_out_base /= out_base;
			cout << sys[pos];
		}
	}
	else
		cout << num;
	_getch();
	return 0;
}