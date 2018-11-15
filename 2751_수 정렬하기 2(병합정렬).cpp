#include <iostream>

using namespace std;

void mergeDivide(int numbers[], int buffer[], int start, int end);
void mergeBond(int numbers[], int buffer[], int start, int mid, int end);

int main() {
	int n;
	cin >> n;
	int* numbers = new int[n];
	int* buffer = new int[n];//��ĥ �� �ӽ÷� �̿��ϴ� ����
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		buffer[i] = numbers[i];
		//1���� ���Ҹ� ���� �迭���� �߻��ϴ� ���� �ذ����� 
		//���⼭ ���� �ʱ�ȭ����
	}
	mergeDivide(numbers, buffer, 0, n-1);
	for (int i = 0; i < n; i++) {		
		cout << buffer[i] << "\n";
	}
	delete[] numbers;
	delete[] buffer;
	return 0;
}

void mergeDivide(int numbers[], int buffer[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;//int�̹Ƿ� �Ҽ��� ���� ó����
		mergeDivide(numbers, buffer, start, mid);
		mergeDivide(numbers, buffer, mid + 1, end);

		mergeBond(numbers, buffer, start, mid, end);
	}
}

void mergeBond(int numbers[], int buffer[], int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;
	//i�� ù��° �κ������� ���ҹ�ȣ
	//j�� �ι�° �κ������� ���ҹ�ȣ
	//k�� ������ ���ҹ�ȣ(���ĵ� ���� ��)
	while (i <= mid && j <= end) {//�� �� �ϳ� �̻� ���ĵ��� ���� ���Ұ� �������
		if (numbers[i] <= numbers[j]) {
			buffer[k] = numbers[i];
			i++;
		}
		else {
			buffer[k] = numbers[j];
			j++;
		}
		k++;
	}

	if (i > mid) {//�ι�° �κ������� ���Ұ� ���ĵ��� �ʰ� ����
		for (int m = j; m <= end; m++, k++) {
			buffer[k] = numbers[m];
		}
	}
	else {//ù��° �κ������� ���Ұ� ���ĵ��� �ʰ� ����
		for (int m = i; m <= mid; m++, k++) {
			buffer[k] = numbers[m];
		}
	}

	for (int m = start; m <= end; m++) {
		numbers[m] = buffer[m];
	}
}
