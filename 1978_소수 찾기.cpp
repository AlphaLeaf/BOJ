#include <iostream>

using namespace std;

int main() {
	int n;
	int check = 0;
	cin >> n;
	int temp;	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp == 1) {
			check++;//1은 소수가 아님
		}
		else {
			for (int j = 2; j < temp; j++) {
				if (temp % j == 0) {					
					check++;//소수 아닐 경우 추가
					break;
				}
			}
		}		
	}		
	cout << n-check;
	return 0;
}