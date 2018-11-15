#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int M, N, size, row, col;
	int notGrow = 0;//������ �丶�� ����
	int day = 0;//���� ��¥
	cin >> N >> M;
	int** tomato = new int*[M];
	for (int i = 0; i < M; i++) {
		tomato[i] = new int[N];
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				//���� �丶���� ��ǥ ������ ���ʷ� ť�� ����
				q.push(i);
				q.push(j);
			}
			if (tomato[i][j] == 0) {
				notGrow++;
			}
		}
	}
	if (notGrow == 0) {
		//��� �丶�䰡 �;��ִ� �����̹Ƿ� 0����� ����
		cout << 0 << "\n";
		return 0;
	}
	size = q.size();//ť�� ũ��, 1/2�ϸ� ���� �丶�� ������
	while (!q.empty()) {//ť�� �� ������ �ݺ�
		for (int i = 0; i < size / 2; i++) {
			row = q.front();
			q.pop();
			col = q.front();
			q.pop();
			if (row + 1 < M) {//��ǥ�� ������ ���� ���� ���
				if (tomato[row + 1][col] == 0) {//�ش� ��ġ�� �丶�䰡 ���� ���� �丶���� ���
												//���� �ʹ� �丶���� ��ǥ�� ť�� ����
					q.push(row + 1);
					q.push(col);
					//�迭���� �ش� ��ġ �丶�並 ���� �丶��� ����
					tomato[row + 1][col] = 1;
				}
			}
			if (row - 1 >= 0) {
				if (tomato[row - 1][col] == 0) {
					q.push(row - 1);
					q.push(col);
					tomato[row - 1][col] = 1;
				}
			}
			if (col + 1 < N) {
				if (tomato[row][col + 1] == 0) {
					q.push(row);
					q.push(col + 1);
					tomato[row][col + 1] = 1;
				}
			}
			if (col - 1 >= 0) {
				if (tomato[row][col - 1] == 0) {
					q.push(row);
					q.push(col - 1);
					tomato[row][col - 1] = 1;
				}
			}
		}
		size = q.size();//��� �丶�� �Ϸ� ���� �� �ٽ� ���� ���
		day++;//�Ϸ� ����
	}
	//�� �̻� �߰��� ���� �丶�� ���� �� �Ʒ��� �����
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (tomato[i][j] == 0) {//������ �丶�� ���������� ����
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	//���̻� ���� �丶�䰡 ���� ���� �������� �߰��ǹǷ� 1�������
	cout << day - 1 << "\n";
	return 0;
}