#include <iostream>
#include <math.h>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int t, n;
	int num[10000];
	int one, two;//������ ��Ƽ�� ù��°, �ι�°
	int len;//one�� two�� ��
	int soNum = 0;//1~10000������ �Ҽ� ����
	int next = 2;//������ ������ ��� ���ؼ�
	for (int i = 0; i < 10000; i++) {
		num[i] = i + 1;
	}
	num[0] = 0;
	while (next*next <= 10000) {
		for (int i = next * 2; i <= 10000; i += next) {
			num[i - 1] = 0;
		}
		for (int i = next + 1; i <= 10000; i++) {
			if (num[i - 1] != 0) {
				next = num[i - 1];
				break;
			}
		}
	}//num�迭�� 10000������ �Ҽ� ����
	for (int i = 0; i < 10000; i++) {
		if (num[i] != 0) {
			soNum++;
		}
	}
	int* soNumbers = new int[soNum];
	int check = 0;
	for (int i = 0; i < 10000; i++) {
		if (num[i] != 0) {
			soNumbers[check] = num[i];
			check++;
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		len = 10000;
		cin >> n;
		for (int j = 0; j < soNum; j++) {
			if (soNumbers[j] > n) {
				break;
			}
			for (int k = j; k < soNum; k++) {
				if (soNumbers[j] + soNumbers[k] > n) {
					break;
				}
				if (soNumbers[j] + soNumbers[k] == n && len > abs(soNumbers[j] - soNumbers[k])) {
					len = abs(soNumbers[j] - soNumbers[k]);
					if (soNumbers[j] >= soNumbers[k]) {
						one = soNumbers[k];
						two = soNumbers[j];
					}
					else {
						one = soNumbers[j];
						two = soNumbers[k];
					}
				}
			}
		}
		cout << one << " " << two << "\n";
	}
	return 0;
}