#include <iostream>

using namespace std;

int selfnum(int num) {
	int ans = num;
	while (num / 10 != 0) {
		ans += num % 10;
		num = num / 10;
	}
	ans += num;
	return ans;//'���� ��+�� �ڸ��� ��'�� ��ȯ
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num[10000];
	for (int i = 0; i < 10000; i++) {
		num[i] = i+1;//�迭�� 1~10000���� ����, ���������� ���� �ѹ��� ���� ����.
	}
	int testnum = 1;//�ʱ� ������ ���� ��
	int check;
	while (testnum <= 10000) {
		check = selfnum(testnum);//check�� testnum�� �����ڷ� ������ ����
		while (true) {			
			if (check > 10000) {//10000���� �۰ų� ���� ���� �ѹ� ���ϴ� ����
				break;
			}
			num[check - 1] = 0;//�����ڰ� ������ �ش� ���ڴ� �迭���� 0���� ����.
			check = selfnum(check);//10000�ʰ��� ������ �ݺ� üũ
		}
		testnum++;//������ ���� �� ����
	}
	for (int i = 0; i < 10000; i++) {
		if (num[i] != 0) {
			cout << num[i] << "\n";//������ ���� �ѹ� ���
		}
	}
	return 0;
}