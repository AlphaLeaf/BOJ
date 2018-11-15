#include <iostream>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;	
	int* numbers = new int[n];
	for (int i = 0; i < n; i++) {
		numbers[i] = i+1;//1���� �� �������� �� �ֱ�
	}
	numbers[0] = -1;//1�� �Ҽ��� �ƴϹǷ� ����
	int num=2;//������ ��� ���ؼ�
	while (num*num <= n) {//�ߴ� ����
		for (int i = num * 2; i <= n; i += num) {
			numbers[i - 1] = -1;//num�� ����� �� ����
		}
		for (int i = num+1; i <= n; i++) {
			if (numbers[i - 1] != -1) {
				num = numbers[i - 1];
				//�� �������� ������ ��� ���ؼ��� ���� �Ҽ��� ����
				break;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (numbers[i - 1] != -1) {
			cout << numbers[i - 1] << "\n";//�Ҽ��� ���� ���
		}
	}
	delete[] numbers;
	return 0;
}