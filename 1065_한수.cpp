#include <iostream>

using namespace std;

bool ishan(int num) {
	int bet;//АЃАн
	int before, after;
	if (num / 10 == 0) {
		return true;
	}
	if (num / 100 == 0) {
		return true;
	}
	before = num % 10;
	num = num / 10;
	after = num % 10;
	num = num / 10;
	bet = after - before;
	while (true) {
		if (after + bet != num % 10) {
			return false;
		}		
		after = num % 10;
		num = num / 10;
		if (num == 0) {
			return true;
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int input;
	int num=0;
	cin >> input;
	for (int i = 0; i < input; i++) {
		if (ishan(i + 1)) {
			num++;
		}
	}
	cout << num;
	return 0;
}