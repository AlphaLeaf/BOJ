#include <iostream>

using namespace std;

int main() {
	int num;
	int starnum = 1;
	cin >> num;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < starnum; j++) {
			cout << "*";
		}
		cout << "\n";
		starnum++;
	}
}