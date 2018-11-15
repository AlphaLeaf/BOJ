#include <iostream>
#include <string>

using namespace std;
//아스키코드로 소문자에서 32빼면 대문자
//a(97)~z(122), A(65)~Z(90)
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string word;
	int lower_alpha[36] = { 0 };//소문자인 알파벳별 개수
	int upper_alpha[36] = { 0 };//대문자인 알파벳별 개수
	int alpha[36];//알파벳별 개수
	int max = 0;//최대 갯수
	int check = -1;//최대 갯수인 알파벳 체크
	cin >> word;		
	for (int i = 97; i <= 122; i++) {
		for (unsigned int j = 0; j < word.length(); j++) {
			if ((int)word[j] == i) {
				lower_alpha[i - 97]++;
			}
		}
	}
	for (int i = 65; i <= 90; i++) {
		for (unsigned int j = 0; j < word.length(); j++) {
			if ((int)word[j] == i) {
				upper_alpha[i - 65]++;
			}
		}
	}
	for (int i = 0; i < 36; i++) {
		alpha[i] = lower_alpha[i] + upper_alpha[i];
		if (alpha[i] > max) {
			max = alpha[i];
		}
	}
	for (int i = 0; i < 36; i++) {
		if (check==-1&&alpha[i] == max) {
			check = i;
			continue;
		}
		else if (alpha[i] == max) {
			cout << '?';
			return 0;
		}		
	}
	cout << (char)(check + 65);
	return 0;
}