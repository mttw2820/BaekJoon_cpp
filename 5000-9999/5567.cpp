//BaekJoon_5567
//결혼식
/*
* 제한 시간 : 1s
* 정답 비율 : 42.291%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int sang = 1;
vector<int> friends[510];
int dist[510] = { 0, };

int BFS() {
	int cnt = 0;
	queue<int> q;
	int visit[510] = { 0, };
	q.push(sang);

	int num = 0;
	while ((num++) <= 2) {
		int curLen = q.size();
		for (int i = 0; i < curLen; i++) {	// 거리가 num인 경우
			int now = q.front();
			q.pop();
			if (visit[now] == -1) continue;
			visit[now] = -1;
			cnt++;

			for (int i = 0; i < friends[now].size(); i++) {
				int next = friends[now][i];
				if (visit[next] == 0) q.push(next);
			}
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	// 상근이와 거리가 1 OR 2 인 동기
	int ans = BFS();
	cout << ans - 1 << endl;

	return 0;
}