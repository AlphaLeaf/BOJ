#include <iostream>

using namespace std;

int main() {
	int num;	
	int sum = 0;
	cin >> num;
	char* temp = new char[num + 1];
	cin >> temp;	
	for (int i = 0; i < num; i++) {
		sum += (temp[i] - 48);//아스키코드 -48하면 숫자로 나옴		
	}
	cout << sum;
	return 0;
}