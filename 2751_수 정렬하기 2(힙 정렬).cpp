#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* numbers = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	for (int i = 1; i < n; i++) {
		int m = i;
		do {
			int root = (m - 1) / 2;//���� node�� ����node ��ȣ�� ����
			if (numbers[root] < numbers[m]) {//���� node�� ���� node���� ũ�� ���� �ٲ�
				int temp = numbers[m];
				numbers[m] = numbers[root];
				numbers[root] = temp;
			}
			m = root;//���� node�� �̵�
		} while (m != 0);//�ֻ��� node ����
	}
	for (int i = n - 1; i >= 0; i--) {//�ѹ� ����ø��� Ʈ���� ũ�� ����
		//i�� numbers�� ����ȣ->ó�� ��ȣ
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		//���� �ֻ��� node�� �ִ� ���� ū ���� �� �ڷ� ����
		int root = 0;	
		int m;
		do {
			m = 2 * root + 1;//���� node�� ù��° node�� ��ȣ
			if (m < i - 1 && numbers[m] < numbers[m + 1]) {
				//������ ��尡 �ƴϰ�, ���� ��尡 ���� ��庸�� ū ���� ���
				m++;//���� ���� �̵�
			}
			if (m < i&&numbers[root] < numbers[m]) {
				//�ش� ��尡 root ��庸�� ū ��� ���� �ٲ�
				temp = numbers[m];
				numbers[m] = numbers[root];
				numbers[root] = temp;
			}
			root = m;
		} while (m < i);
	}
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << "\n";
	}
	return 0;	
}