#include <iostream>

using namespace std;

int main() {
	double a;
	double b;
	double answer;
	cin >> a >> b;
	answer = a / b;	
	cout << answer << endl;
	cout.precision(10);//어느정도 자리까지 표시할지 결정하는 부분
	cout << answer << endl;
	return 0;
}