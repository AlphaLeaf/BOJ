#include <iostream>

using namespace std;

int main() {
	int num;	
	int sum = 0;
	cin >> num;
	char* temp = new char[num + 1];
	cin >> temp;	
	for (int i = 0; i < num; i++) {
		sum += (temp[i] - 48);//�ƽ�Ű�ڵ� -48�ϸ� ���ڷ� ����		
	}
	cout << sum;
	return 0;
}