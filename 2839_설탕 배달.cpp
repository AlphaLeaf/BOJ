#include <iostream>

using namespace std;

int main() {
	int kg;
	int num = 0;//��ü ���� ����
	int three = 0;//3kg ���� ��
	int five = 0;//5kg ���� ��
	cin >> kg;
	five = kg / 5;
	kg = kg % 5;
	three = kg / 3;
	kg = kg % 3;
	if (kg == 0) {
		num = five + three;
		cout << num;
		return 0;
	}
	while (1) {
		if (five > 0) {
			five--;
			kg += 5;
		}
		three += kg / 3;
		kg = kg % 3;
		if (kg == 0) {
			num = five + three;
			cout << num;
			return 0;
		}
		if (five == 0) {
			cout << -1;
			return 0;
		}
	}
	return 0;
}