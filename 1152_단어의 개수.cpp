#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string text;
	getline(cin,text);
	int num = 0;
	int len = text.length();//text�� ���� ��ȯ	
	for (int i = 0; i < len; i++) {
		if (text[i] != ' ') {
			num++;//������ �ƴ� ���� ������ num ���� �� �ݺ��� ����
			break;
		}
	}	
	for (int i = 1; i < len-1;i++) {
		if (text[i-1] != ' '&&text[i]==' '&&text[i+1]!=' ') {
			num++;//(����,����,����)�� �� num����
		}
	}
	cout << num;
	return 0;
}