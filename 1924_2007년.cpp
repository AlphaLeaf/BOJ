#include <iostream>

using namespace std;

int main() {
	int month;
	int day;
	int num=0;
	int yobi;
	cin >> month >> day;
	for (int i = 1; i < month; i++) {
		switch (i) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
			num += 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			num += 30;
			break;
		case 2:
			num += 28;
			break;
		}
	}
	num += day;	
	yobi = num % 7;
	switch (yobi) {
	case 1:
		cout << "MON";
		break;
	case 2:
		cout << "TUE";
		break;
	case 3:
		cout << "WED";
		break;
	case 4:
		cout << "THU";
		break;
	case 5:
		cout << "FRI";
		break;
	case 6:
		cout << "SAT";
		break;
	case 0:
		cout << "SUN";
		break;
	}
	return 0;
}