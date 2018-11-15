#include <iostream>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;	
	int* numbers = new int[n];
	for (int i = 0; i < n; i++) {
		numbers[i] = i+1;//1부터 끝 범위까지 수 넣기
	}
	numbers[0] = -1;//1은 소수가 아니므로 제거
	int num=2;//제거할 배수 기준수
	while (num*num <= n) {//중단 조건
		for (int i = num * 2; i <= n; i += num) {
			numbers[i - 1] = -1;//num의 배수인 수 제거
		}
		for (int i = num+1; i <= n; i++) {
			if (numbers[i - 1] != -1) {
				num = numbers[i - 1];
				//그 다음으로 제거할 배수 기준수를 다음 소수로 결정
				break;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (numbers[i - 1] != -1) {
			cout << numbers[i - 1] << "\n";//소수인 수만 출력
		}
	}
	delete[] numbers;
	return 0;
}