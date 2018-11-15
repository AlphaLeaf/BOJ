#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point {
	int x, y, R;//R은 통신가능반경
};

int main() {
	queue<Point> q;
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		vector<Point>regions;
		bool* visited = new bool[N] {false};
		Point temp;
		for (int j = 0; j < N; j++) {
			cin >> temp.x >> temp.y >> temp.R;
			regions.push_back(temp);			
		}
		int dist;
		int count = 0;
		for (int j = 0; j < N; j++) {			
			if (visited[j]) {				
				continue;				
			}
			q.push(regions[j]);
			visited[j] = true;
			while (!q.empty()) {//연결 가능한 지점 모두 true로
				temp.x = q.front().x;
				temp.y = q.front().y;
				temp.R = q.front().R;//temp는 기준 지점
				q.pop();
				for (int k = 0; k < N; k++) {
					if (j == k) {
						continue;
					}
					if (!visited[k]) {
						dist = (temp.x - regions[k].x)*(temp.x - regions[k].x) + (temp.y - regions[k].y)*(temp.y - regions[k].y);
						if (dist <= (temp.R + regions[k].R)*(temp.R + regions[k].R)) {
							q.push(regions[k]);							
							visited[k] = true;
						}
					}
				}
			}			
			count++;
		}
		delete[] visited;
		cout << count << "\n";
	}
	return 0;
}