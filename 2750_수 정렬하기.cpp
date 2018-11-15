#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int* numbers = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> numbers[i];
	}

	/*��ǰ ����-j��°�� j+1��° ���� ���� �ٲٴ� ���� num�� �ݺ�
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (numbers[j] > numbers[j + 1]) {
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
	*/
	//���� ����-i��°�� i-1��° ���� ���Ͽ� j��° ����
	//�� ���� ��� ���� ��ġ �ٲ�. �ٲ� ���� i-2��° ������ ���ϴ� ��
	//���ʷ� ���� ���� ���� ������ �ݺ�. ���� i+1��° �� �������� �ݺ�
	for (int i = 1; i < num; i++) {
		int temp = numbers[i];//���Ϸ��� �� ����
		int j = i - 1;
		while (j >= 0 && temp < numbers[j]) {//���� �ٲپ�� �ϴ� ���
			numbers[j + 1] = numbers[j];//�� index�� ���� ���
			j = j - 1;//index �̵�
		}
		numbers[j + 1] = temp;//�������� ���� �� ����
	}

	for (int i = 0; i < num; i++) {
		cout << numbers[i] << "\n";
	}
	delete[] numbers;
	return 0;
}