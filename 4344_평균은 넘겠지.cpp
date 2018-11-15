#include <iostream>

using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	double* percent = new double[testcase];
	double sum = 0;
	double avg;
	int n;
	double num = 0;
	for (int i = 0; i < testcase; i++) {
		cin >> n;
		double* score = new double[n];
		for (int j = 0; j < n; j++) {
			cin >> score[j];
			sum += score[j];
		}
		avg = sum / n;		
		for (int j = 0; j < n; j++) {
			if (score[j] > avg) {
				num++;				
			}			
		}		
		percent[i] = num / (double)n * 100;
		num = 0;
		sum = 0;
	}
	cout << fixed;//소숫점 아래부터 자릿수 계산하도록 함
	cout.precision(3);
	for (int i = 0; i < testcase; i++) {
		cout << percent[i]<<"%" << "\n";
	}
	return 0;
}