#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
	int x, y, r;
};//x��ǥ,y��ǥ,�ݰ��� ������ ������ ����ü

vector<pair<int, point> > kk;
vector<vector<int> > adj;

bool same(int i, int j) {
	point a = kk[i].second;
	point b = kk[j].second;

	int r = a.r + b.r;//�� ������ Ž���ݰ��� ��
	double dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	//���� �� ������ �Ÿ� ���
	return dist <= (double)r;//�Ÿ��� �ݰ� ������ ��� true ��ȯ
}

vector<bool> visited;//�湮���� üũ �迭
void dfs(int here) {
	visited[here] = true;//�湮�� ���� üũ
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (!visited[next])//����� ����� �� ���� ��ȸ�ϸ� �湮üũ
			dfs(next);
	}//�Ϸ��ϸ� �ش� ������ ��� ���ᰡ���� �� ���� �湮ó����
}

int len;
int dfsAll() {
	int cnt = 0;
	visited = vector<bool>(len, false);//visited�� boolŸ�� ���� len���� ������, false�� �ʱ�ȭ
	for (int i = 0; i < len; i++) {
		if (!visited[i]) {//�湮���� ���� ��� �߽߰�
			dfs(i); cnt++;//dfs���� �� ī��Ʈ �߰�
		}
	}
	return cnt;
}

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {//�־��� �׽�Ʈ���̽���ŭ �ݺ�
		int n;
		scanf("%d", &n);

		int a, b, c;
		point tmp;//�ӽ� ����(x,y,r)

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &tmp.x, &tmp.y, &tmp.r);
			kk.push_back(make_pair(i, tmp));//���� ������ point������ ���Ϳ� ����
		}

		len = kk.size();//��ü ���� ����
		adj = vector<vector<int> >(len);//int�� ���� len���� ���ҷ� ������ ����
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {//��� ������ ��
				if (same(i, j)) {//������ �Ÿ��� �ݰ� �����̸� true ��ȯ
					adj[i].push_back(j);//i��° ������ j��° ������ ��Ű����ϴٴ� ���� ����
					adj[j].push_back(i);//j��° ������ i��° ������ ��Ű����ϴٴ� ���� ����
				}
			}
		}

		printf("%d\n", dfsAll());

		kk.clear();
		adj.clear();
	}

	return 0;
}
