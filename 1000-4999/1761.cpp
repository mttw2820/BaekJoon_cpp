//BaekJoon_1761
//정점들의 거리
/*
* 제한 시간 : 2s
* 정답 비율 : 36.185%
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 40010
using namespace std;

int n, m;
vector<pair<int, int>> tree[MAX];
int check[MAX] = { 0, };
pair<int, int> parent[MAX];
int depth[MAX] = { 0, };

void make_tree_bfs() {
	queue<int> q;
	q.push(1);	// 임의로 루트가 1이라고 한다.
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (check[now] == -1) continue;
		check[now] = -1;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i].first;
			if (check[next] == -1) continue;
			parent[next].first = now;
			parent[next].second = tree[now][i].second;
			depth[next] = depth[now] + 1;
			q.push(next);
		}
	}
	return;
}

int LCA(int nodeA, int nodeB) {
	int dist = 0;
	if (depth[nodeA] > depth[nodeB]) {// nodeB의 depth가 더 크게 만든다.
		int temp = nodeA;
		nodeA = nodeB;
		nodeB = temp;
	}
	while (depth[nodeA] != depth[nodeB]) {
		dist += parent[nodeB].second;
		nodeB = parent[nodeB].first;
	}
	while(nodeA != nodeB) {
		dist += (parent[nodeA].second + parent[nodeB].second);
		nodeA = parent[nodeA].first;
		nodeB = parent[nodeB].first;
	}
	return dist;
}
int main() {
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	make_tree_bfs();
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		int ans = LCA(a, b);
		cout << ans << endl;
	}
	
	return 0;
}