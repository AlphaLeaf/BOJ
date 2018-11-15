#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int num;
	int n = 1;//num의 자릿수
	cin >> num;
	while (num / pow(10, n) >= 1) {
		n++;
	}
	int* sorted_number = new int[n];
	for (int i = 0; i < n; i++) {//각 자릿수를 배열에 넣기
		sorted_number[i] = num % 10;
		num /= 10;
	}
	for (int i = 0; i < n; i++) {//내림차순 정렬
		for (int j = i+1; j < n; j++) {
			if (sorted_number[i] < sorted_number[j]) {
				int temp = sorted_number[i];
				sorted_number[i] = sorted_number[j];
				sorted_number[j] = temp;
			}
		}
	}
	num = 0;
	for (int i = 0; i < n; i++) {//정렬된 배열을 다시 숫자로 합치기		
		num += sorted_number[i];
		if (i != n - 1) {
			num *= 10;
		}
	}
	cout << num << "\n";
	delete[] sorted_number;
	return 0;
}