#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, row, col, size;
	string temp;
	int walk = 1;//�̵� Ƚ��
	queue<int> q;
	cin >> N >> M;//N�� �� ��, M�� �� ��
	int** maze = new int*[N];//�̷� ���� ��Ÿ���� �迭
	bool** visit = new bool*[N];//�湮 ���� ��Ÿ���� �迭
	for (int i = 0; i < N; i++) {
		maze[i] = new int[M];
		visit[i] = new bool[M];
	}
	for (int i = 0; i < N; i++) {
		cin >> temp;		
		for (int j = 0; j <M; j++) {			
			maze[i][j] = temp[j] - '0';//string�� int�� ��ȯ
			visit[i][j] = false;
		}
	}
	q.push(0);
	q.push(0);
	visit[0][0] = true;
	//(0,0)��ġ���� ���, ���� ���� 0���� �ٲپ� �� ������
	size = q.size();
	while (true) {
		for (int i = 0; i < size / 2; i++) {			
			row = q.front();
			q.pop();
			col = q.front();
			q.pop();			
			if (row == N - 1 && col == M - 1) {//�������� ���޽� ����
				cout << walk << "\n";
				return 0;
			}
			//���� ��ġ�� ������ 4���� Ž��
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