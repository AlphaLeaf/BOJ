#include <iostream>

using namespace std;

int main() {
	int num[3];
	int temp;
	cin >> num[0] >> num[1] >> num[2];
	if (num[0] < num[1]) {
		temp = num[1];
		num[1] = num[0];
		num[0] = temp;
	}
	if (num[0] < num[2]) {
		temp = num[2];
		num[2] = num[0];
		num[0] = temp;
	}
	if (num[1] < num[2]) {
		temp = num[2];
		num[2] = num[1];
		num[1] = temp;
	}
	cout << num[1];
	return 0;
}