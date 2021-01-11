//BaekJoon_11438
//LCA 2
/*
* 제한 시간 : 1.5s
* 정답 비율 : 32.366%
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100010
using namespace std;

/* DP를 사용한 LCA */
int n, m;
vector<int> tree[MAX];
int parent[MAX][100] = { 0, };
int depth[MAX] = { 0, };
int check[MAX] = { 0, };

void make_tree_bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (check[now] == -1) continue;
		check[now] = -1;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			if (check[next] != -1) {
				parent[next][0] = now;
				depth[next] = depth[now] + 1;
				q.push(next);
			}
		}
	}
	return;
}

int make_DP() {
	int i = 0;
	bool flag = true;
	for (i = 1; i * 2 < n; i++) {
		flag = true;
		for (int j = 1; j <= n; j++) {
			if (parent[j][i - 1] != 0) {
				parent[j][i] = parent[parent[j][i - 1]][i - 1];
				flag = false;
			}
		}
		if (flag) break;
	}
	return i;
}

int LCA(int nodeA, int nodeB, int max_p) {
	if (depth[nodeA] > depth[nodeB]) {
		int temp = nodeA;
		nodeA = nodeB;
		nodeB = temp;
	}
	while (depth[nodeA] != depth[nodeB]) {
		// nodeB 움직이기
		for (int i = max_p; i >= 0; i--) {
			if (parent[nodeB][i] == 0) continue;
			if (depth[nodeA] > depth[parent[nodeB][i]]) continue;
			nodeB = parent[nodeB][i];
			break;
		}
	}

	while (nodeA != nodeB) {
		for (int i = max_p; i >= 0; i--) {
			if (parent[nodeA][i] == 0 || parent[nodeB][i]==0) continue;
			if (i!=0 && parent[nodeA][i] == parent[nodeB][i]) continue;
			nodeA = parent[nodeA][i];
			nodeB = parent[nodeB][i];
			break;
		}
	}
	return nodeA;
}

int main() {
	cin >> n;
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b);
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	make_tree_bfs();
	int power = make_DP();
	cin >> m;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		int ans = LCA(a, b, power);
		printf("%d\n", ans);
	}

	return 0;
}