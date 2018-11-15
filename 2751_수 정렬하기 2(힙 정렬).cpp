#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* numbers = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	for (int i = 1; i < n; i++) {
		int m = i;
		do {
			int root = (m - 1) / 2;//현재 node의 상위node 번호를 구함
			if (numbers[root] < numbers[m]) {//하위 node가 상위 node보다 크면 서로 바꿈
				int temp = numbers[m];
				numbers[m] = numbers[root];
				numbers[root] = temp;
			}
			m = root;//상위 node로 이동
		} while (m != 0);//최상위 node 지남
	}
	for (int i = n - 1; i >= 0; i--) {//한번 수행시마다 트리의 크기 감소
		//i는 numbers의 끝번호->처음 번호
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		//현재 최상위 node에 있는 가장 큰 값을 맨 뒤로 보냄
		int root = 0;	
		int m;
		do {
			m = 2 * root + 1;//하위 node중 첫번째 node의 번호
			if (m < i - 1 && numbers[m] < numbers[m + 1]) {
				//마지막 노드가 아니고, 다음 노드가 현재 노드보다 큰 값일 경우
				m++;//다음 노드로 이동
			}
			if (m < i&&numbers[root] < numbers[m]) {
				//해당 노드가 root 노드보다 큰 경우 서로 바꿈
				temp = numbers[m];
				numbers[m] = numbers[root];
				numbers[root] = temp;
			}
			root = m;
		} while (m < i);
	}
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << "\n";
	}
	return 0;	
}