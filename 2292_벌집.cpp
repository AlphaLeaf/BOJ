#include <iostream>

using namespace std;

int main() {
	int num;
	int plus = 1;//�ٱ������� �̵��Ҷ����� �߰��Ǵ� ��ȣ ��
	int route = 0;//���� ������ �ִ� �� ��ȣ
	cin >> num;
	//���ʿ������� 1,6,12,18,24(6*(n-1), n=1�϶� 1)
	//�� ���� n-1���� 6�������� �����ϱ�
	for (int i = 1;; i++) {
		route += plus;
		plus += plus == 1 ? 5 : 6;
		if (route >= num) {
			cout << i;
			return 0;
		}
	}	
}