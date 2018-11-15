#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int comNum, pairNum, size, nowCom;
	cin >> comNum >> pairNum;
	queue<int> q;
	bool* com = new bool[comNum];//false이면 감염되지 않은 상태
	for (int i = 0; i < comNum; i++) {
		com[i] = false;
	}
	pair<int, int>* p = new pair<int, int>[pairNum];
	int temp1, temp2;
	for (int i = 0; i < pairNum; i++) {
		cin >> temp1 >> temp2;
		//컴퓨터 번호를 '0 ~ comNum-1'로 사용하기 위해 1빼줌
		p[i] = make_pair(temp1 - 1, temp2 - 1);
	}
	q.push(0);
	com[0] = true;
	size = q.size();
	while (!q.empty()) {
		for (int i = 0; i < size; i++) {
			nowCom = q.front();
			q.pop();
			for (int j = 0; j < pairNum; j++) {
				if (p[j].first == nowCom&&!com[p[j].second]) {
					q.push(p[j].second);
					com[p[j].second] = true;
				}
				else if (p[j].second == nowCom&&!com[p[j].first]) {
					q.push(p[j].first);
					com[p[j].first] = true;
				}
			}
		}
		size = q.size();
	}
	int ans = 0;
	for (int i = 0; i < comNum; i++) {
		if (com[i] == true) {
			ans++;
		}
	}
	cout << ans - 1 << "\n";
	//1번 컴퓨터가 감염시킨 숫자만 체크하므로 1 빼줌
	delete[]com;
	delete[]p;
	return 0;
}