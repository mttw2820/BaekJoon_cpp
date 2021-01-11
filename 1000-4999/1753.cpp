//BaekJoon_1753
//최단경로
/*
* 제한 시간 : 1s
* 정답 비율 : 22.986%
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

/* vector를 쓰는 것 보다 priority queue가 속도가 빠른 편*/

int v, e, start;
vector<pair<int, int>> conn[20010];
int check[20010];
int minpath[20010] = { 0, };
bool comp(int x, int y) {
	return minpath[x] < minpath[y];
}
void DIJ() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, start));

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();

		if (check[now] == -1) continue;
		check[now] = -1;

		int next = 0;
		for (int i = 0; i < conn[now].size(); i++) {
			next = conn[now][i].first;
			if (check[next] == -1) continue;
			if (minpath[next] == 0 || minpath[next] > minpath[now] + conn[now][i].second) {
				minpath[next] = minpath[now] + conn[now][i].second;
				q.push(make_pair(minpath[next], next));
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (i != start && minpath[i] == 0)
			printf("INF\n");
		else printf("%d\n", minpath[i]);
	}

	return;
}

int main() {
	cin >> v >> e >> start;
	int from, to, weight;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &from, &to, &weight);
		conn[from].push_back(make_pair(to, weight));
	}
	DIJ();

	return 0;
}