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
			numbers[i] = i + 1;//1부터 끝 범위까지 수 넣기
		}
		numbers[0] = -1;//1은 소수가 아니므로 제거
		int num = 2;//제거할 배수 기준수
		while (num*num <= 2 * n) {//중단 조건
			for (int i = num * 2; i <= 2 * n; i += num) {
				numbers[i - 1] = -1;//num의 배수인 수 제거
			}
			for (int i = num + 1; i <= 2 * n; i++) {
				if (numbers[i - 1] != -1) {
					num = numbers[i - 1];
					//그 다음으로 제거할 배수 기준수를 다음 소수로 결정
					break;
				}
			}
		}
		for (int i = n + 1; i <= 2 * n; i++) {			
			if (numbers[i - 1] != -1) {
				answer++;//소수 갯수 증가
			}
		}
		cout << answer << "\n";
		//delete[] numbers;//사용한 배열 삭제
	}
	return 0;
}