#include <iostream>

using namespace std;

int main() {
	int n;
	double max = 0;
	int max_n;
	double sum = 0;
	cin >> n;
	double* score = new double[n];
	for (int i = 0; i < n; i++) {
		cin >> score[i];
	}
	for (int i = 0; i < n; i++) {
		if (max < score[i]) {
			max = score[i];
			max_n = i;
		}
	}
	for (int i = 0; i < n; i++) {		
		score[i] = score[i] / max * 100;
	}
	for (int i = 0; i < n; i++) {
		sum += score[i];		
	}
	cout << sum / (double)n;
	return 0;
}