#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int testcase, h, w, n;
	int room;//방 번호
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		room = 0;
		cin >> h >> w >> n;
		room += (n % h == 0 ? h : n % h) * 100;//몇 층
		room += (int)ceil((double)n / (double)h);//해당 층 방 번호
		cout << room << "\n";
	}
	return 0;
}