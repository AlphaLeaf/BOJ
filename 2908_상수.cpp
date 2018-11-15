#include <iostream>

using namespace std;

int main() {
	int num1, num2, new_num1, new_num2;
	cin >> num1 >> num2;
	new_num1 = num1 % 10 * 100;
	num1 /= 10;
	new_num1 += num1 % 10 * 10;
	num1 /= 10;
	new_num1 += num1;

	new_num2 = num2 % 10 * 100;
	num2 /= 10;
	new_num2 += num2 % 10 * 10;
	num2 /= 10;
	new_num2 += num2;

	if (new_num1 > new_num2) {
		cout << new_num1;
	}
	else {
		cout << new_num2;
	}
	return 0;
}