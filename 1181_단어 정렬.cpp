#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, string>a, pair<int, string>b) {
	if (a.second.length() == b.second.length()) {
		return a < b;//���ʿ� �� ���� ���� ������(������)
	}
	else {
		return a.second.length() < b.second.length();
		//���ʿ� �� ���� ���� ������(���� �� ��)
	}
}

int main() {
	int n;
	pair<int, string>temp;
	vector<pair<int, string>>v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp.second;
		temp.first = temp.second.length();
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		if (i > 0 && v[i].second == v[i - 1].second) {
			continue;//���� ���ڿ��� ������ ��� ������� �ʰ� �ѱ�
		}
		cout << v[i].second << "\n";
	}
	return 0;
}