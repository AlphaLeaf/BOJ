#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);//입출력 방식 빠르게
	ios_base::sync_with_stdio(false);//단, 이 방식 쓰면 c스타일의 입출력 불가
	int num;
	int a, b;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		cout << a + b << "\n";
	}	
	return 0;
}