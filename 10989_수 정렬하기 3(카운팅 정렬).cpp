#include <iostream>

using namespace std;

int main() {	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;	
	cin >> n;
	int number;
	int numbers[10001] = { 0 };	
	for (int i = 0; i < n; i++) {
		cin >> number;
		numbers[number]++;//�Է¹��� ���� �ش��ϴ� numbers�迭�� index�� ���� ������Ų��.
	}
	for (int i = 0; i < 10001; i++) {//���� ������ ���ʷ� ����Ƚ���� üũ�Ѵ�.
		if (numbers[i] != 0) {//1�� �̻� ���������� ����Ѵ�.
			for (int j = 0; j < numbers[i]; j++) {//����Ƚ����ŭ ����Ѵ�.
				cout << i << "\n";
			}
		}
	}
	return 0;
}