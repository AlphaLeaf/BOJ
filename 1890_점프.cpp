#include<iostream>
//https://blog.naver.com/rk9034/221297664206

using namespace std;

int n;
int map[100][100];
long long dp[100][100];

bool isOk(int row, int col) {
	if (row >= 0 && row < n&&col >= 0 && col < n) {
		return true;
	}
	return false;
}

long long DP(int row, int col) {
	if (!isOk(row, col)) {
		return 0;
	}
	if (map[row][col] == 0) {
		return 1;
	}
	long long& ret = dp[row][col];
	if (ret >= 0) {
		return ret;
	}
	ret = 0;
	ret = DP(row + map[row][col], col) + DP(row, col + map[row][col]);
	return ret;
}

int main() {	
	memset(dp, -1, sizeof(dp));
	cin >> n;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			dp[i][j] = 0;
		}
	}	
	cout << DP(0, 0) << "\n";
	return 0;
}