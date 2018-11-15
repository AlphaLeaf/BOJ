#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
	int x, y, r;
};//x좌표,y좌표,반경을 정보로 가지는 구조체

vector<pair<int, point> > kk;
vector<vector<int> > adj;

bool same(int i, int j) {
	point a = kk[i].second;
	point b = kk[j].second;

	int r = a.r + b.r;//두 점간의 탐지반경의 합
	double dist = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	//받은 두 점간의 거리 계산
	return dist <= (double)r;//거리가 반경 이하인 경우 true 반환
}

vector<bool> visited;//방문여부 체크 배열
void dfs(int here) {
	visited[here] = true;//방문한 지점 체크
	for (int i = 0; i < adj[here].size(); i++) {
		int next = adj[here][i];
		if (!visited[next])//통신이 연결된 곳 전부 순회하며 방문체크
			dfs(next);
	}//완료하면 해당 지점과 통신 연결가능한 곳 전부 방문처리됨
}

int len;
int dfsAll() {
	int cnt = 0;
	visited = vector<bool>(len, false);//visited는 bool타입 벡터 len개를 가지고, false로 초기화
	for (int i = 0; i < len; i++) {
		if (!visited[i]) {//방문하지 않은 경우 발견시
			dfs(i); cnt++;//dfs실행 후 카운트 추가
		}
	}
	return cnt;
}

int main() {

	int T;
	scanf("%d", &T);

	while (T--) {//주어진 테스트케이스만큼 반복
		int n;
		scanf("%d", &n);

		int a, b, c;
		point tmp;//임시 지점(x,y,r)

		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &tmp.x, &tmp.y, &tmp.r);
			kk.push_back(make_pair(i, tmp));//지점 순서와 point정보를 벡터에 넣음
		}

		len = kk.size();//전체 지점 갯수
		adj = vector<vector<int> >(len);//int형 벡터 len개를 원소로 가지는 벡터
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {//모든 지점간 비교
				if (same(i, j)) {//지점간 거리가 반경 이하이면 true 반환
					adj[i].push_back(j);//i번째 지점에 j번째 지점과 통신가능하다는 정보 저장
					adj[j].push_back(i);//j번째 지점에 i번째 지점과 통신가능하다는 정보 저장
				}
			}
		}

		printf("%d\n", dfsAll());

		kk.clear();
		adj.clear();
	}

	return 0;
}
