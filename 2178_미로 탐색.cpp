#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, row, col, size;
	string temp;
	int walk = 1;//이동 횟수
	queue<int> q;
	cin >> N >> M;//N은 행 수, M은 열 수
	int** maze = new int*[N];//미로 상태 나타내는 배열
	bool** visit = new bool*[N];//방문 여부 나타내는 배열
	for (int i = 0; i < N; i++) {
		maze[i] = new int[M];
		visit[i] = new bool[M];
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;		
		for (int j = 0; j <M; j++) {			
			maze[i][j] = temp[j] - '0';//string을 int로 변환
			visit[i][j] = false;
		}
	}
	q.push(0);
	q.push(0);
	visit[0][0] = true;
	//(0,0)위치에서 출발, 지난 이후 0으로 바꾸어 못 가게함
	size = q.size();
	while (true) {
		for (int i = 0; i < size / 2; i++) {			
			row = q.front();
			q.pop();
			col = q.front();
			q.pop();			
			if (row == N - 1 && col == M - 1) {//도착지에 도달시 종료
				cout << walk << "\n";
				return 0;
			}
			//다음 위치로 가능한 4방향 탐색
			if (row + 1 < N&&maze[row + 1][col] == 1 && !visit[row + 1][col]) {
				q.push(row + 1);
				q.push(col);
				visit[row + 1][col] = true;
			}
			if (row - 1 >= 0 && maze[row - 1][col] == 1 && !visit[row - 1][col]) {
				q.push(row - 1);
				q.push(col);
				visit[row - 1][col] = true;
			}
			if (col + 1 < M&&maze[row][col + 1] == 1 && !visit[row][col + 1]) {
				q.push(row);
				q.push(col + 1);
				visit[row][col + 1] = true;
			}
			if (col - 1 >= 0 && maze[row][col - 1] == 1 && !visit[row][col - 1]) {
				q.push(row);
				q.push(col - 1);
				visit[row][col - 1] = true;
			}
		}
		walk++;
		size = q.size();
	}	
}