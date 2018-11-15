#include <iostream>

using namespace std;

int main() {
	int num;
	int plus = 1;//바깥쪽으로 이동할때마다 추가되는 번호 수
	int route = 0;//현재 라인의 최대 방 번호
	cin >> num;
	//안쪽에서부터 1,6,12,18,24(6*(n-1), n=1일땐 1)
	//한 변당 n-1개인 6각형으로 생각하기
	for (int i = 1;; i++) {
		route += plus;
		plus += plus == 1 ? 5 : 6;
		if (route >= num) {
			cout << i;
			return 0;
		}
	}	
}