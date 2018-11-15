#include <iostream>
#include <math.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t, n;
	int num[10000];
	int one, two;//골드바흐 파티션 첫번째, 두번째
	int len;//one과 two의 차
	int soNum = 0;//1~10000까지의 소수 갯수
	int next = 2;//다음에 제거할 배수 기준수
	for (int i = 0; i < 10000; i++) {
		num[i] = i + 1;
	}
	num[0] = 0;
	while (next*next <= 10000) {
		for (int i = next * 2; i <= 10000; i += next) {
			num[i - 1] = 0;
		}
		for (int i = next + 1; i <= 10000; i++) {
			if (num[i - 1] != 0) {
				next = num[i - 1];
				break;
			}
		}
	}//num배열에 10000이하의 소수 넣음
	for (int i = 0; i < 10000; i++) {
		if (num[i] != 0) {
			soNum++;
		}
	}
	int* soNumbers = new int[soNum];
	int check = 0;
	for (int i = 0; i < 10000; i++) {
		if (num[i] != 0) {
			soNumbers[check] = num[i];
			check++;
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		len = 10000;
		cin >> n;
		for (int j = 0; j < soNum; j++) {
			if (soNumbers[j] > n) {
				break;
			}
			for (int k = j; k < soNum; k++) {
				if (soNumbers[j] + soNumbers[k] > n) {
					break;
				}
				if (soNumbers[j] + soNumbers[k] == n && len > abs(soNumbers[j] - soNumbers[k])) {
					len = abs(soNumbers[j] - soNumbers[k]);
					if (soNumbers[j] >= soNumbers[k]) {
						one = soNumbers[k];
						two = soNumbers[j];
					}
					else {
						one = soNumbers[j];
						two = soNumbers[k];
					}
				}
			}
		}
		cout << one << " " << two << "\n";
	}
	return 0;
}