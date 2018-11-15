#include <iostream>

using namespace std;
//단순하게 순서대로 가면서 갯수 세면 시간초과 발생

int gcd(int a, int b);

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int testcase, m, n, x, y, num, one, two, max;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {		
		cin >> m >> n >> x >> y;
		one = x;//첫번째 숫자
		two = x % n == 0 ? n : x % n;//두번째 숫자
		num = x;//햇수
		max = m * n / gcd(m, n);//최소공배수 구하기
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

int gcd(int a, int b) {//유클리드 호제법을 이용해 최대공약수 구하기
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}
	int c;
	while (b) {//나누어 떨어질 때까지 실행
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}