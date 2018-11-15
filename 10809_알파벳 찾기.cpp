#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;
	cin >> word;
	for (int i = 97; i <= 122; i++) {
		cout << (int)word.find(i) << ' ';
	}
	return 0;
}