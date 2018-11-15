#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num[10] = { 0 };
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a * b*c;
	while(sum>0){
		num[sum % 10]++;
		sum = sum / 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}