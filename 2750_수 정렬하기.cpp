#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;
	int* numbers = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> numbers[i];
	}

	/*거품 정렬-j번째와 j+1번째 비교해 서로 바꾸는 것을 num번 반복
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
	//삽입 정렬-i번째와 i-1번째 값과 비교하여 j번째 값이
	//더 작을 경우 서로 위치 바꿈. 바꾼 이후 i-2번째 값과도 비교하는 등
	//차례로 비교해 작지 않을 때까지 반복. 이후 i+1번째 값 기준으로 반복
	for (int i = 1; i < num; i++) {
		int temp = numbers[i];//비교하려는 값 저장
		int j = i - 1;
		while (j >= 0 && temp < numbers[j]) {//서로 바꾸어야 하는 경우
			numbers[j + 1] = numbers[j];//앞 index의 값을 당김
			j = j - 1;//index 이동
		}
		numbers[j + 1] = temp;//마지막에 비교한 값 저장
	}

	for (int i = 0; i < num; i++) {
		cout << numbers[i] << "\n";
	}
	delete[] numbers;
	return 0;
}