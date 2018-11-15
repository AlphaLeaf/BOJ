#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double num;
	int speed;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int testcase;
	double x, y;//x(현재 위치),y(목표 위치)
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		speed = 0;
		cin >> x >> y;
		double dist = y - x;
		while (++speed) {
			if (dist < pow(speed, 2)) {
				num = 2 * (speed - 1) - 1;
				dist = dist - pow(speed-1, 2);//속도 바뀌면서 이동할 때 남은거리
				dist /= (speed - 1);//속도 유지하면서 이동해야 하는 거리
				dist = ceil(dist);//ceil(올림 함수), floor(내림 함수), round(반올림 함수)
				num += dist;
				break;
			}
		}
		cout << num << "\n";		
	}
	return 0;
}

