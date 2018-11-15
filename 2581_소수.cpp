#include <iostream>

using namespace std;

int main() {
	int m, n;
	int check = 0;//소수 여부 체크
	int sum = 0;//소수의 합
	int min = -1;//소수중 최솟값
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (i == 1) {			
			continue;
		}
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				check = 1;//소수가 아님을 확인
				break;
			}
		}
		if (check == 1) {//소수가 아닌 경우 다음 수로 넘어감
			check = 0;
			continue;
		}
		sum += i;
		if (min == -1) {
			min = i;//가장 첫번째 수는 그냥 넣기
		}
		else if (i < min) {
			min = i;//현재 최솟값보다 작으면 변경
		}
	}
	if (sum == 0) {
		cout << -1 << "\n";
		return 0;
	}
	cout << sum << "\n" << min << "\n";
	return 0;
}