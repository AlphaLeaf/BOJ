#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	queue<int> q;
	int N, size;
	cin >> N;
	int** home = new int*[N];
	for (int i = 0; i < N; i++) {
		home[i] = new int[N];
	}
	string temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		for (int j = 0; j < N; j++) {
			home[i][j] = temp[j] - '0';
		}
	}
	int partNum = 2;//������ ���� ��ȣ, ���� �� ���� ���� 1��
	int row, col;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (home[i][j] == 1) {//���� ���� ��ȣ�� ���� ���� �� �߽߰�
				q.push(i);
				q.push(j);
				size = q.size();
				while (!q.empty()) {//�� ���� ����� ��� ���� ��ȣ ����
					row = q.front();
					q.pop();
					col = q.front();
					q.pop();
					home[row][col] = partNum;
					for (int k = 0; k < size / 2; k++) {
						if (row - 1 >= 0 && home[row - 1][col] == 1) {
							q.push(row - 1);
							q.push(col);
							home[row - 1][col] = partNum;
						}
						if (row + 1 < N&&home[row + 1][col] == 1) {
							q.push(row + 1);
							q.push(col);
							home[row + 1][col] = partNum;						
						}
						if (col - 1 >= 0 && home[row][col - 1] == 1) {
							q.push(row);
							q.push(col - 1);
							home[row][col - 1] = partNum;
						}
						if (col + 1 < N&&home[row][col + 1] == 1) {
							q.push(row);
							q.push(col + 1);
							home[row][col + 1] = partNum;
						}
					}
					size = q.size();
				}
				partNum++;//���� ������ �Ѿ
			}
		}
	}
	cout << partNum - 2 << "\n";//���� �� ���
	int* numbers = new int[partNum - 2];//������ �� ����
	for (int i = 0; i < partNum - 2; i++) {
		numbers[i] = 0;//������ �� ���� �ʱ�ȭ
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (home[i][j] != 0) {
				numbers[home[i][j] - 2]++;
				//��ü �� �迭���� �� ������ �� ã�� �ϳ��� ������
			}
		}
	}
	sort(numbers, numbers + partNum - 2);//�������� ����
	for (int i = 0; i < partNum - 2; i++) {
		cout << numbers[i] << "\n";
	}
	for (int i = 0; i < N; i++) {
		delete[]home[i];
	}
	delete[]home;
	delete[]numbers;
	return 0;
}