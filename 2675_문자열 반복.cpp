#include <iostream>
#include <string>

using namespace std;

int main() {
	int testcase;
	int num;
	string text;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> num >> text;
		for (int j = 0; j < (signed int)text.length(); j++) {
			for (int k = 0; k < num; k++) {
				cout << text[j];
			}
		}
		cout << "\n";
	}
	return 0;
}