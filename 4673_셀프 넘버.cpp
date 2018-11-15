#include <iostream>

using namespace std;

int selfnum(int num) {
	int ans = num;
	while (num / 10 != 0) {
		ans += num % 10;
		num = num / 10;
	}
	ans += num;
	return ans;//'원래 수+각 자릿수 합'을 반환
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num[10000];
	for (int i = 0; i < 10000; i++) {
		num[i] = i+1;//배열에 1~10000까지 넣음, 최종적으로 셀프 넘버인 수만 남김.
	}
	int testnum = 1;//초기 생성자 역할 수
	int check;
	while (testnum <= 10000) {
		check = selfnum(testnum);//check는 testnum을 생성자로 가지는 숫자
		while (true) {			
			if (check > 10000) {//10000보다 작거나 같은 셀프 넘버 구하는 조건
				break;
			}
			num[check - 1] = 0;//생성자가 있으면 해당 숫자는 배열에서 0으로 만듬.
			check = selfnum(check);//10000초과할 때까지 반복 체크
		}
		testnum++;//생성자 역할 수 갱신
	}
	for (int i = 0; i < 10000; i++) {
		if (num[i] != 0) {
			cout << num[i] << "\n";//구해진 셀프 넘버 출력
		}
	}
	return 0;
}