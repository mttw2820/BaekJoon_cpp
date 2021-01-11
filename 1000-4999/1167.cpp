//BaekJoon_1167
//트리의 지름
/*
* 제한 시간 : 2s
* 정답 비율 : 36.916%
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

int n;
vector<pair<int, int>> tree[100010];
int check[100010] = { 0, };
pair<int, int> bfs(int start) {
	queue<pair<int, int>> q;	//노드 번호, 번호까지 거리
	q.push(make_pair(start, 0));

	int fnode = 0, fdist = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();

		if (check[now] == -1) continue;
		check[now] = -1;
		if (fdist < dist) {
			fnode = now;
			fdist = dist;
		}

		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i].first;
			if (check[next] == -1) continue;
			q.push(make_pair(next, dist + tree[now][i].second));
		}
	}

	return make_pair(fnode, fdist);
}

int main() {
	cin >> n;
	int node, a, b;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &node);
		while (true) {
			scanf("%d", &a);
			if (a == -1) break;
			scanf("%d", &b);
			tree[node].push_back(make_pair(a, b));
		}
	}

	pair<int, int> ans;
	ans = bfs(node);
	for (int i = 0; i <= 100000; i++)
		check[i] = 0;
	ans = bfs(ans.first);

	cout << ans.second << endl;

	return 0;
}