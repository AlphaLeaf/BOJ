#include <iostream>

using namespace std;

int main() {
	double a;
	double b;
	double answer;
	cin >> a >> b;
	answer = a / b;	
	cout << answer << endl;
	cout.precision(10);//������� �ڸ����� ǥ������ �����ϴ� �κ�
	cout << answer << endl;
	return 0;
}