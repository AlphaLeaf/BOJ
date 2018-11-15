#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int testcase, k, n;
	int room[15][15] = { 0 };
	for (int i = 0; i <= 14; i++) {//Ãþ
		for (int j = 1; j <= 14; j++) {//È£
			if (i == 0) {
				room[i][j] = j;
				continue;
			}
			for (int u = 1; u <= j; u++) {
				room[i][j] += room[i - 1][u];
			}
		}
	}
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> k >> n;
		cout << room[k][n] << "\n";
	}
	return 0;
}