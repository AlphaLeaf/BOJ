#include <iostream>

using namespace std;

int main() {
	int num;
	int up = 1;//분자
	int down = 1;//분모
	bool flag = true;//true(우상향 이동), false(좌하향 이동)
	cin >> num;
	for (int i = 1; i < num; i++) {
		if (flag) {//우 상향 상태
			if (up == 1) {
				down++;
				flag = !flag;//좌 하향으로 변경
				continue;
			}
			up--;
			down++;
		}
		if (!flag) {//좌 하향 상태
			if (down == 1) {
				up++;
				flag = !flag;//우 상향으로 변경
				continue;
			}
			up++;
			down--;
		}
	}
	cout << up << '/' << down;
	return 0;
}