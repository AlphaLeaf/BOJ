#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	double avg;
	int avg_temp = 0;
	int mid, many, range;
	int max = -4001;
	int min = 4001;	
	cin >> n;
	short* numbers = new short[n];
	short* sorted_numbers = new short[n];
	short count[8001] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		avg_temp += numbers[i];
		if (numbers[i] > max) {
			max = numbers[i];
		}
		if (numbers[i] < min) {
			min = numbers[i];
		}
		count[numbers[i] + 4000]++;
	}
	avg = (double)avg_temp / (double)n;
	range = max - min;		
	int num = 0;//���ĵ� �迭 index
	int many_num = 0;//���� ���� ��Ÿ���� ���� ����Ƚ��
	int many_numbers = 0;//���� ���� �����ϴ� ������ ����
	for (int i = 0; i < 8001; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				sorted_numbers[num] = i - 4000;
				num++;				
			}
			if (many_num < count[i]) {
				//���� ���� ���� �ִ� ���ڸ� ���� �߽߰�
				many_num = count[i];
				many_numbers = 1;
				many = i - 4000;
			}
			else if (many_num == count[i]) {
				//������ �߰��� �ֺ󰪰� ������ ���� �ִ� ���� �߽߰�
				many_numbers++;
			}
		}
	}
	mid = sorted_numbers[n / 2];
	if (many_numbers > 1) {//�ֺ��� ������ �ִ� ���
		int check = 0;
		for (int i = 0; i < 8001; i++) {
			if (count[i] == many_num&&check==1) {
				//�ι�°�� ���� �ֺ� �߽߰� ����
				many = i - 4000;
				break;
			}
			else if (count[i] == many_num) {
				check = 1;//���� ���� �ֺ� �߽߰� ����				
			}
		}
	}
	cout << (int)round(avg) << "\n";
	cout << mid << "\n";
	cout << many << "\n";
	cout << range << "\n";
	return 0;
}