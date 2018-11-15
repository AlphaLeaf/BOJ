#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	queue<int> q;
	int N, size;
	cin >> N;
	int** home = new int*[N];
	for (int i = 0; i < N; i++) {
		home[i] = new int[N];
	}
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++) {
			home[i][j] = temp[j] - '0';
		}
	}
	int partNum = 2;//단지별 붙일 번호, 아직 안 붙인 곳은 1임
	int row, col;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (home[i][j] == 1) {//아직 단지 번호가 붙지 않은 집 발견시
				q.push(i);
				q.push(j);
				size = q.size();
				while (!q.empty()) {//그 집과 연결된 모든 집에 번호 붙임
					row = q.front();
					q.pop();
					col = q.front();
					q.pop();
					home[row][col] = partNum;
					for (int k = 0; k < size / 2; k++) {
						if (row - 1 >= 0 && home[row - 1][col] == 1) {
							q.push(row - 1);
							q.push(col);
							home[row - 1][col] = partNum;
						}
						if (row + 1 < N&&home[row + 1][col] == 1) {
							q.push(row + 1);
							q.push(col);
							home[row + 1][col] = partNum;						
						}
						if (col - 1 >= 0 && home[row][col - 1] == 1) {
							q.push(row);
							q.push(col - 1);
							home[row][col - 1] = partNum;
						}
						if (col + 1 < N&&home[row][col + 1] == 1) {
							q.push(row);
							q.push(col + 1);
							home[row][col + 1] = partNum;
						}
					}
					size = q.size();
				}
				partNum++;//다음 단지로 넘어감
			}
		}
	}
	cout << partNum - 2 << "\n";//단지 수 출력
	int* numbers = new int[partNum - 2];//단지별 집 갯수
	for (int i = 0; i < partNum - 2; i++) {
		numbers[i] = 0;//단지별 집 갯수 초기화
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (home[i][j] != 0) {
				numbers[home[i][j] - 2]++;
				//전체 집 배열에서 각 단지별 집 찾아 하나씩 더해줌
			}
		}
	}
	sort(numbers, numbers + partNum - 2);//오름차순 정렬
	for (int i = 0; i < partNum - 2; i++) {
		cout << numbers[i] << "\n";
	}
	for (int i = 0; i < N; i++) {
		delete[]home[i];
	}
	delete[]home;
	delete[]numbers;
	return 0;
}