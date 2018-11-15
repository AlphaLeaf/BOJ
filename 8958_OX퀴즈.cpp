#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int test;
	char result[80];
	int score = 0;
	int plusScore = 1;
	cin >> test;
	for (int i = 0; i < test; i++) {
		cin >> result;
		for (int j = 0; j < 80; j++) {
			if (result[j] == 'O') {
				score += plusScore;
				plusScore++;
			}
			else if (result[j] == 'X') {
				plusScore = 1;
			}
			else {
				break;
			}
		}
		cout << score<<"\n";
		score = 0;
		plusScore = 1;
	}
}