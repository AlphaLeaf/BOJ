#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int num;
	int n = 1;//num�� �ڸ���
	cin >> num;
	while (num / pow(10, n) >= 1) {
		n++;
	}
	int* sorted_number = new int[n];
	for (int i = 0; i < n; i++) {//�� �ڸ����� �迭�� �ֱ�
		sorted_number[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i < n; i++) {//�������� ����
		for (int j = i+1; j < n; j++) {
			if (sorted_number[i] < sorted_number[j]) {
				int temp = sorted_number[i];
				sorted_number[i] = sorted_number[j];
				sorted_number[j] = temp;
			}
		}
	}
	num = 0;
	for (int i = 0; i < n; i++) {//���ĵ� �迭�� �ٽ� ���ڷ� ��ġ��		
		num += sorted_number[i];
		if (i != n - 1) {
			num *= 10;
		}
	}
	cout << num << "\n";
	delete[] sorted_number;
	return 0;
}