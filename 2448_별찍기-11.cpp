#include <iostream>

using namespace std;

char map[3072][6143] = { ' ', };//col=1024*(5+1)-1

void print_star(int row, int col, int num) {
	if (num == 3) {
		map[row][col] = '*';
		map[row + 1][col - 1] = '*';
		map[row + 1][col + 1] = '*';
		for (int i = col - 2; i <= col + 2; i++) {
			map[row + 2][i] = '*';
		}
		return;
	}
	print_star(row, col, num / 2);
	print_star(row+num / 2, col + num / 2, num / 2);
	print_star(row+num / 2, col - num / 2, num / 2);	
}

int main() {	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int num;
	cin >> num;
	print_star(0,num/3*3-1,num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num * 2-1; j++) {			
			if (map[i][j] == '\0') {
				cout << ' ';
			}
			else {
				cout << map[i][j];
			}
		}
		cout << "\n";
	}
}