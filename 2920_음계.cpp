#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num[8];
	int temp;		
	for (int i = 0; i < 8; i++) {
		cin >> num[i];
	}
	temp = num[0];
	for (int i = 1; i < 8; i++) {
		if (temp + 1 != num[i]) {
			break;
		}
		temp = num[i];
		if (i == 7) {			
			cout << "ascending";
			return 0;
		}
	}
	for (int i = 1; i < 8; i++) {
		if (temp - 1 != num[i]) {
			break;
		}
		temp = num[i];
		if (i == 7) {			
			cout << "descending";
			return 0;
		}
	}	
	cout << "mixed";
	return 0;
}