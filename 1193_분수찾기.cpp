#include <iostream>

using namespace std;

int main() {
	int num;
	int up = 1;//����
	int down = 1;//�и�
	bool flag = true;//true(����� �̵�), false(������ �̵�)
	cin >> num;
	for (int i = 1; i < num; i++) {
		if (flag) {//�� ���� ����
			if (up == 1) {
				down++;
				flag = !flag;//�� �������� ����
				continue;
			}
			up--;
			down++;
		}
		if (!flag) {//�� ���� ����
			if (down == 1) {
				up++;
				flag = !flag;//�� �������� ����
				continue;
			}
			up++;
			down--;
		}
	}
	cout << up << '/' << down;
	return 0;
}