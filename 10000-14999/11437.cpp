//BaekJoon_11437
//LCA
/*
* 제한 시간 : 3s
* 정답 비율 : 48.080%
*/

#include <iostream>
#include <vector>
#include <queue>
#define ROOT 1
using namespace std;

/* 부모만 확인하면 되는 케이스 
   -> 각 노드에 대한 부모 번호를 배열로 저장 */
int parent[50010] = { 0, };
int depth[50010] = { 0, };
int check[50010] = { 0, };
vector<int> conn[50010];

void bfs(int start) {
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (check[now] == -1) continue;
		check[now] = -1;
		for (int i = 0; i < conn[now].size(); i++) {
			int next = conn[now][i];
			if (check[next]!=-1) {
				parent[next] = now;
				depth[next] = depth[now] + 1;
				q.push(next);
			}
		}
	}
	return;
}

int LCA(int nodeA, int nodeB) {
	if (depth[nodeA] > depth[nodeB]) {	// depth가 더 작은 걸 nodeA로 둔다.
		int temp = nodeA;
		nodeA = nodeB;
		nodeB = temp;
	}

	while (depth[nodeA] != depth[nodeB]) {
		// nodeB가 depth가 더 크다. -> nodeB의 부모로 이동
		nodeB = parent[nodeB];
	}
	while (nodeA != nodeB) {
		nodeA = parent[nodeA];
		nodeB = parent[nodeB];
	}

	return nodeA;
}

int main() {
	int m, a, b;
	cin >> m;
	for (int i = 0; i < m-1; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}
	
	// 부모 자식 관계 정리
	bfs(ROOT);

	int testcase, ans = 0;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		scanf("%d %d", &a, &b);
		ans = LCA(a, b);
		printf("%d\n", ans);
	}
	return 0;
}