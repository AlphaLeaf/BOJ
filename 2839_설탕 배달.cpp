#include <iostream>

using namespace std;

int main() {
	int kg;
	int num = 0;//ÀüÃ¼ ºÀÁö °³¼ö
	int three = 0;//3kg ºÀÁö ¼ö
	int five = 0;//5kg ºÀÁö ¼ö
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