#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string text;
	getline(cin,text);
	int num = 0;
	int len = text.length();//text의 길이 반환	
	for (int i = 0; i < len; i++) {
		if (text[i] != ' ') {
			num++;//공백이 아닌 문자 만나면 num 증가 후 반복문 종료
			break;
		}
	}	
	for (int i = 1; i < len-1;i++) {
		if (text[i-1] != ' '&&text[i]==' '&&text[i+1]!=' ') {
			num++;//(글자,공백,글자)일 때 num증가
		}
	}
	cout << num;
	return 0;
}