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
	int num = 0;//정렬된 배열 index
	int many_num = 0;//가장 많이 나타나는 값의 등장횟수
	int many_numbers = 0;//가장 자주 등장하는 숫자의 종류
	for (int i = 0; i < 8001; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				sorted_numbers[num] = i - 4000;
				num++;				
			}
			if (many_num < count[i]) {
				//가장 많은 수가 있는 숫자를 새로 발견시
				many_num = count[i];
				many_numbers = 1;
				many = i - 4000;
			}
			else if (many_num == count[i]) {
				//이전에 발견한 최빈값과 동일한 수가 있는 숫자 발견시
				many_numbers++;
			}
		}
	}
	mid = sorted_numbers[n / 2];
	if (many_numbers > 1) {//최빈값이 여러개 있는 경우
		int check = 0;
		for (int i = 0; i < 8001; i++) {
			if (count[i] == many_num&&check==1) {
				//두번째로 작은 최빈값 발견시 동작
				many = i - 4000;
				break;
			}
			else if (count[i] == many_num) {
				check = 1;//가장 작은 최빈값 발견시 동작				
			}
		}
	}
	cout << (int)round(avg) << "\n";
	cout << mid << "\n";
	cout << many << "\n";
	cout << range << "\n";
	return 0;
}