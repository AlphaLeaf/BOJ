#include <iostream>
#include <cmath>

using namespace std;

int main() {
	double num;
	int speed;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int testcase;
	double x, y;//x(���� ��ġ),y(��ǥ ��ġ)
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		speed = 0;
		cin >> x >> y;
		double dist = y - x;
		while (++speed) {
			if (dist < pow(speed, 2)) {
				num = 2 * (speed - 1) - 1;
				dist = dist - pow(speed-1, 2);//�ӵ� �ٲ�鼭 �̵��� �� �����Ÿ�
				dist /= (speed - 1);//�ӵ� �����ϸ鼭 �̵��ؾ� �ϴ� �Ÿ�
				dist = ceil(dist);//ceil(�ø� �Լ�), floor(���� �Լ�), round(�ݿø� �Լ�)
				num += dist;
				break;
			}
		}
		cout << num << "\n";		
	}
	return 0;
}

