#include <iostream>
#include <string>

using namespace std;
//�ƽ�Ű�ڵ� a(97)~z(122)
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string word;
	int testcase;	
	int group = 0;//�׷� �ܾ��� ���� ����
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {		
		bool check = true;//�ش� ���ĺ��� �߰������� ��Ÿ���� �Ǵ��� ����		
		cin >> word;
		for (int j = 0; j < 36; j++) {
			for (unsigned int k = 0; k < word.length(); k++) {
				if ((int)word[k] == j + 97) {
					if (check == false) {
						break;//�������� ���� ���ĺ� ��Ÿ��
					}
					if (k != word.length() - 1 && word[k] != word[k + 1]) {
						check = false;//���ӵ� ���ĺ� ����
					}
				}
				if (k == word.length() - 1) {
					check = true;//������ ������ ���ĺ��� ��Ÿ��					
				}
			}
			if (check == false) {
				break;//�������� ���� ���ĺ� ��Ÿ��
			}			
		}
		if (check == true) {
			group++;//������ ���ĺ��� �����Ͽ� �׷� �ܾ�� Ȯ��
		}
	}
	cout << group;
	return 0;
}