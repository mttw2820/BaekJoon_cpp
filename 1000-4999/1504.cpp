//BaekJoon_1504
//특정한 최단 경로
/*
* 제한 시간 : 1s
* 정답 비율 : 23.901%
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <string.h>
#define INF 99999999
using namespace std;

/* node 1 -> node A -> node B -> node N */
/* node 1 -> node B -> node A -> node N */
/* one node to all node */
int n, e;
vector<pair<int, int>> vec[805];
int check[805] = { 0, };
int result[3][805] = { 0, };

void DIJ(int start, int index) {
	for (int i = 1; i <= n; i++)
		result[index][i] = INF;
	memset(check, 0, sizeof(int)*(n + 2));
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));
	result[index][start] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();

		if (check[now] != 0) continue;
		check[now] = -1;

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i].first;
			if (result[index][next] > result[index][now] + vec[now][i].second) {
				result[index][next] = result[index][now] + vec[now][i].second;
				if (check[next] == 0)
					q.push(make_pair(result[index][next], next));
			}
		}
	}
	return;
}

int main() {
	cin >> n >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		vec[a].push_back(make_pair(b, c));
		vec[b].push_back(make_pair(a, c));
	}
	int nodeA, nodeB;
	cin >> nodeA >> nodeB;
	DIJ(1, 0);
	DIJ(nodeA, 1);
	DIJ(nodeB, 2);

	int ans = 0;
	if(result[0][nodeA]!=INF && result[1][nodeB]!= INF && result[2][n]!=INF)
		ans = result[0][nodeA] + result[1][nodeB] + result[2][n];
	if(result[0][nodeB]!=INF && result[2][nodeA]!=INF && result[1][n]!=INF)
		ans = min(ans, result[0][nodeB] + result[2][nodeA] + result[1][n]);
	
	if (ans == 0) cout << "-1" << endl;
	else cout << ans << endl;

	return 0;
}