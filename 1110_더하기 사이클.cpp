#include <iostream>

using namespace std;

int main() {
	int num;
	int temp;
	cin >> num;
	int start = num;
	int test = 0;
	do {
		temp = num % 10 + num / 10;		
		num = (num % 10) * 10 + temp % 10;		
		test++;
	} while (num != start);
	cout << test;
	return 0;
}