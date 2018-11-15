#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, string>a, pair<int, string>b) {
	if (a.second.length() == b.second.length()) {
		return a < b;//왼쪽에 더 작은 값이 오도록(사전순)
	}
	else {
		return a.second.length() < b.second.length();
		//왼쪽에 더 작은 값이 오도록(글자 수 순)
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
			continue;//이전 문자열과 동일한 경우 출력하지 않고 넘김
		}
		cout << v[i].second << "\n";
	}
	return 0;
}