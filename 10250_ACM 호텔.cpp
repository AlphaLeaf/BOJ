#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int testcase, h, w, n;
	int room;//�� ��ȣ
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		room = 0;
		cin >> h >> w >> n;
		room += (n % h == 0 ? h : n % h) * 100;//�� ��
		room += (int)ceil((double)n / (double)h);//�ش� �� �� ��ȣ
		cout << room << "\n";
	}
	return 0;
}