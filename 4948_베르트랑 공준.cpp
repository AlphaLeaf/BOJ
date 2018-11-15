#include <iostream>

using namespace std;

int main() {
	int n;
	int answer;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		answer = 0;
		int* numbers = new int[2 * n];
		for (int i = 0; i < 2 * n; i++) {
			numbers[i] = i + 1;//1���� �� �������� �� �ֱ�
		}
		numbers[0] = -1;//1�� �Ҽ��� �ƴϹǷ� ����
		int num = 2;//������ ��� ���ؼ�
		while (num*num <= 2 * n) {//�ߴ� ����
			for (int i = num * 2; i <= 2 * n; i += num) {
				numbers[i - 1] = -1;//num�� ����� �� ����
			}
			for (int i = num + 1; i <= 2 * n; i++) {
				if (numbers[i - 1] != -1) {
					num = numbers[i - 1];
					//�� �������� ������ ��� ���ؼ��� ���� �Ҽ��� ����
					break;
				}
			}
		}
		for (int i = n + 1; i <= 2 * n; i++) {			
			if (numbers[i - 1] != -1) {
				answer++;//�Ҽ� ���� ����
			}
		}
		cout << answer << "\n";
		//delete[] numbers;//����� �迭 ����
	}
	return 0;
}