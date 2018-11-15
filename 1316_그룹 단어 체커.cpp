#include <iostream>
#include <string>

using namespace std;
//아스키코드 a(97)~z(122)
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string word;
	int testcase;	
	int group = 0;//그룹 단어의 갯수 저장
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {		
		bool check = true;//해당 알파벳이 추가적으로 나타나도 되는지 여부		
		cin >> word;
		for (int j = 0; j < 36; j++) {
			for (unsigned int k = 0; k < word.length(); k++) {
				if ((int)word[k] == j + 97) {
					if (check == false) {
						break;//연속하지 않은 알파벳 나타남
					}
					if (k != word.length() - 1 && word[k] != word[k + 1]) {
						check = false;//연속된 알파벳 끝남
					}
				}
				if (k == word.length() - 1) {
					check = true;//끝까지 연속한 알파벳만 나타남					
				}
			}
			if (check == false) {
				break;//연속하지 않은 알파벳 나타남
			}			
		}
		if (check == true) {
			group++;//연속한 알파벳만 존재하여 그룹 단어로 확정
		}
	}
	cout << group;
	return 0;
}