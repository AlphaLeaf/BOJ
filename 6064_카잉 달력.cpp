#include <iostream>

using namespace std;
//�ܼ��ϰ� ������� ���鼭 ���� ���� �ð��ʰ� �߻�

int gcd(int a, int b);

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int testcase, m, n, x, y, num, one, two, max;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {		
		cin >> m >> n >> x >> y;
		one = x;//ù��° ����
		two = x % n == 0 ? n : x % n;//�ι�° ����
		num = x;//�޼�
		max = m * n / gcd(m, n);//�ּҰ���� ���ϱ�
		while (1) {			
			if (one == x && two == y) {
				cout << num << "\n";
				break;
			}
			else if (num >= max) {
				cout << -1 << "\n";
				break;
			}
			two = (two + m) % n == 0 ? n : (two + m) % n;
			num += m;
		}
	}
	return 0;
}

int gcd(int a, int b) {//��Ŭ���� ȣ������ �̿��� �ִ����� ���ϱ�
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	int c;
	while (b) {//������ ������ ������ ����
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}