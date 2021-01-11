//BaekJoon_1967
//트리의 지름
/*
* 제한 시간 : 2s
* 정답 비율 : 49.378%
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

int n;
vector<pair<int, int>> tree[10010];
int check[10010] = { 0, };

pair<int, int> bfs(int start) {
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));

	int max_node = 0, max_dist = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int dist = q.front().second;
		q.pop();
		check[now] = -1;
		if (dist > max_dist) {
			max_node = now;
			max_dist = dist;
		}
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i].first;
			if (check[next] == -1) continue;
			q.push(make_pair(next, dist + tree[now][i].second));
		}
	}

	return make_pair(max_node, max_dist);
}
int main() {
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}
	
	pair<int, int> ans;
	ans = bfs(1);
	memset(check, 0, sizeof(check));
	ans = bfs(ans.first);
	cout << ans.second << endl;
	return 0;
}