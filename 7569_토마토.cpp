#include <iostream>
#include <queue>

using namespace std;

int main() {	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	queue<int> q;
	int N, M, H, size, row, col, height;
	int notGrow = 0;//익지 않은 토마토의 수
	int day = 0;//경과 일수	
	cin >> N >> M >> H;
	int*** tomato = new int**[H];	
	for (int i = 0; i < H; i++) {
		tomato[i] = new int*[M];		
		for (int j = 0; j < M; j++) {
			tomato[i][j] = new int[N];			
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {				
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					q.push(i);
					q.push(j);
					q.push(k);
				}
				else if (tomato[i][j][k] == 0) {
					notGrow++;
				}
			}
		}
	}
	if (notGrow == 0) {//처음부터 다 익어있는 경우
		cout << 0 << "\n";
		return 0;
	}
	size = q.size();
	while (!q.empty()) {
		for (int i = 0; i < size / 3; i++) {
			bool over = true;
			height = q.front();
			q.pop();
			row = q.front();
			q.pop();
			col = q.front();
			q.pop();
			if (col + 1 < N) {
				if (tomato[height][row][col + 1] == 0) {
					over = false;
					q.push(height);
					q.push(row);
					q.push(col + 1);
					tomato[height][row][col + 1] = 1;
				}
			}
			if (col - 1 >= 0) {
				if (tomato[height][row][col - 1] == 0) {
					q.push(height);
					q.push(row);
					q.push(col - 1);
					tomato[height][row][col - 1] = 1;
				}
			}
			if (row + 1 < M) {
				if (tomato[height][row + 1][col] == 0) {
					q.push(height);
					q.push(row + 1);
					q.push(col);
					tomato[height][row + 1][col] = 1;
				}
			}
			if (row - 1 >= 0) {
				if (tomato[height][row - 1][col] == 0) {
					q.push(height);
					q.push(row - 1);
					q.push(col);
					tomato[height][row - 1][col] = 1;
				}
			}
			if (height + 1 < H) {
				if (tomato[height + 1][row][col] == 0) {
					q.push(height + 1);
					q.push(row);
					q.push(col);
					tomato[height + 1][row][col] = 1;
				}
			}
			if (height - 1 >= 0) {
				if (tomato[height - 1][row][col] == 0) {
					q.push(height - 1);
					q.push(row);
					q.push(col);
					tomato[height - 1][row][col] = 1;
				}
			}
		}
		size = q.size();
		day++;
	}		
		
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1 << "\n";
					return 0;
				}
			}
		}
	}
	cout << day - 1 << "\n";
	return 0;
}