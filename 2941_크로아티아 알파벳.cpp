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
			word.erase(check, sample[i].length());//�߰��� ũ�ξ�Ƽ�� ���ĺ� ����
			//erase(����� �����ϴ� ��ȣ, ���� ���� ����)
			word.insert(check, "@");//���� ��ġ�� @����
			//insert(���� ��ġ ��ȣ, ���� ����)
			//word.replace(check,sample[i].length(),"@"); �� ������
			i--;	//���� ���� �� �ִ��� üũ�ϱ�		
		}
	}	
	cout << word.length();
	return 0;
}