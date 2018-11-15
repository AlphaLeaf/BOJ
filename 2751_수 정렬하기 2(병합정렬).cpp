#include <iostream>

using namespace std;

void mergeDivide(int numbers[], int buffer[], int start, int end);
void mergeBond(int numbers[], int buffer[], int start, int mid, int end);

int main() {
	int n;
	cin >> n;
	int* numbers = new int[n];
	int* buffer = new int[n];//합칠 때 임시로 이용하는 공간
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		buffer[i] = numbers[i];
		//1개의 원소를 가진 배열에서 발생하는 문제 해결위해 
		//여기서 버퍼 초기화해줌
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
		int mid = (start + end) / 2;//int이므로 소숫점 버림 처리됨
		mergeDivide(numbers, buffer, start, mid);
		mergeDivide(numbers, buffer, mid + 1, end);

		mergeBond(numbers, buffer, start, mid, end);
	}
}

void mergeBond(int numbers[], int buffer[], int start, int mid, int end) {
	int i = start;
	int j = mid + 1;
	int k = start;
	//i는 첫번째 부분집합의 원소번호
	//j는 두번째 부분집합의 원소번호
	//k는 버퍼의 원소번호(정렬된 집합 들어감)
	while (i <= mid && j <= end) {//둘 다 하나 이상 정렬되지 않은 원소가 남은경우
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

	if (i > mid) {//두번째 부분집합의 원소가 정렬되지 않고 남음
		for (int m = j; m <= end; m++, k++) {
			buffer[k] = numbers[m];
		}
	}
	else {//첫번째 부분집합의 원소가 정렬되지 않고 남음
		for (int m = i; m <= mid; m++, k++) {
			buffer[k] = numbers[m];
		}
	}

	for (int m = start; m <= end; m++) {
		numbers[m] = buffer[m];
	}
}
