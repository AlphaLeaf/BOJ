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
	cout << fixed;//�Ҽ��� �Ʒ����� �ڸ��� ����ϵ��� ��
	cout.precision(3);
	for (int i = 0; i < testcase; i++) {
		cout << percent[i]<<"%" << "\n";
	}
	return 0;
}