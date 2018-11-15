#include <iostream>
#include <string>

using namespace std;

int main() {
	string word;	
	string sample[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	cin >> word;
	for (int i = 0; i < 8; i++){
		int check = word.find(sample[i]);
		if (check >= 0) {						
			word.erase(check, sample[i].length());//발견한 크로아티아 알파벳 지움
			//erase(지우기 시작하는 번호, 지울 문자 갯수)
			word.insert(check, "@");//지운 위치에 @삽입
			//insert(넣을 위치 번호, 넣을 문자)
			//word.replace(check,sample[i].length(),"@"); 과 동일함
			i--;	//같은 문자 더 있는지 체크하기		
		}
	}	
	cout << word.length();
	return 0;
}