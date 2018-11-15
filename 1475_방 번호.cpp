#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	int num[10] = { 0 };
	cin >> n;
	if (n == 0) {
		cout << 1;
		return 0;
	}
	while (n != 0) {
		num[n % 10]++;
		n = n / 10;
	}
	double temp = (double)(num[6] + num[9]) / 2;
	num[6] = (int)ceil(temp);
	num[9] = (int)ceil(temp);
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (max < num[i]) {
			max = num[i];
		}
	}
	cout << max;
	return 0;
}