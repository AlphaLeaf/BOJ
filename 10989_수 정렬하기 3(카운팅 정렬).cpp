#include <iostream>

using namespace std;

int main() {	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;	
	cin >> n;
	int number;
	int numbers[10001] = { 0 };	
	for (int i = 0; i < n; i++) {
		cin >> number;
		numbers[number]++;//입력받은 값에 해당하는 numbers배열의 index의 값을 증가시킨다.
	}
	for (int i = 0; i < 10001; i++) {//작은 수부터 차례로 등장횟수를 체크한다.
		if (numbers[i] != 0) {//1번 이상 등장했으면 출력한다.
			for (int j = 0; j < numbers[i]; j++) {//등장횟수만큼 출력한다.
				cout << i << "\n";
			}
		}
	}
	return 0;
}