#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int M, N, size, row, col;
	int notGrow = 0;//안익은 토마토 갯수
	int day = 0;//지난 날짜
	cin >> N >> M;
	int** tomato = new int*[M];
	for (int i = 0; i < M; i++) {
		tomato[i] = new int[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				//익은 토마토의 좌표 성분을 차례로 큐에 넣음
				q.push(i);
				q.push(j);
			}
			if (tomato[i][j] == 0) {
				notGrow++;
			}
		}
	}
	if (notGrow == 0) {
		//모든 토마토가 익어있는 상태이므로 0출력후 종료
		cout << 0 << "\n";
		return 0;
	}
	size = q.size();//큐의 크기, 1/2하면 익은 토마토 갯수임
	while (!q.empty()) {//큐가 빌 때까지 반복
		for (int i = 0; i < size / 2; i++) {
			row = q.front();
			q.pop();
			col = q.front();
			q.pop();
			if (row + 1 < M) {//좌표가 범위를 넘지 않은 경우
				if (tomato[row + 1][col] == 0) {//해당 위치의 토마토가 익지 않은 토마토인 경우
												//새로 익는 토마토의 좌표값 큐에 넣음
					q.push(row + 1);
					q.push(col);
					//배열에서 해당 위치 토마토를 익은 토마토로 변경
					tomato[row + 1][col] = 1;
				}
			}
			if (row - 1 >= 0) {
				if (tomato[row - 1][col] == 0) {
					q.push(row - 1);
					q.push(col);
					tomato[row - 1][col] = 1;
				}
			}
			if (col + 1 < N) {
				if (tomato[row][col + 1] == 0) {
					q.push(row);
					q.push(col + 1);
					tomato[row][col + 1] = 1;
				}
			}
			if (col - 1 >= 0) {
				if (tomato[row][col - 1] == 0) {
					q.push(row);
					q.push(col - 1);
					tomato[row][col - 1] = 1;
				}
			}
		}
		size = q.size();//모든 토마토 하루 익은 후 다시 갯수 계산
		day++;//하루 지남
	}
	//더 이상 추가로 익을 토마토 없을 때 아래로 진행됨
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (tomato[i][j] == 0) {//안익은 토마토 남아있으면 종료
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	//더이상 익을 토마토가 없는 날이 마지막에 추가되므로 1빼줘야함
	cout << day - 1 << "\n";
	return 0;
}