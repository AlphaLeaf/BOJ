#include <iostream>

using namespace std;

int main() {
	int m, n;
	int check = 0;//�Ҽ� ���� üũ
	int sum = 0;//�Ҽ��� ��
	int min = -1;//�Ҽ��� �ּڰ�
	cin >> m >> n;
	for (int i = m; i <= n; i++) {
		if (i == 1) {			
			continue;
		}
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				check = 1;//�Ҽ��� �ƴ��� Ȯ��
				break;
			}
		}
		if (check == 1) {//�Ҽ��� �ƴ� ��� ���� ���� �Ѿ
			check = 0;
			continue;
		}
		sum += i;
		if (min == -1) {
			min = i;//���� ù��° ���� �׳� �ֱ�
		}
		else if (i < min) {
			min = i;//���� �ּڰ����� ������ ����
		}
	}
	if (sum == 0) {
		cout << -1 << "\n";
		return 0;
	}
	cout << sum << "\n" << min << "\n";
	return 0;
}