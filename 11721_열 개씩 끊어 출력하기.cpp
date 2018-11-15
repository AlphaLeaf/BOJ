#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char* str = new char[101];
	cin >> str;
	int len = strlen(str);
	for (int i = 0; i < len / 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << str[i * 10 + j];
		}
		cout << "\n";
	}
	for (int i = 0; i < len % 10; i++) {
		cout << str[(len / 10) * 10 + i];
	}
	cout << "\n";
	return 0;
}