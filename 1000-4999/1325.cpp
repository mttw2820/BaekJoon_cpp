#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<int> trust[], int start) {
	queue<int> q;
	bool visit[10001] = { false };
	q.push(start); visit[start] = true;
	int cnt = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int len = trust[now].size();
		for (int i = 0; i < len; i++) {
			int next = trust[now][i];
			if (!visit[next]) {
				cnt++;
				visit[next] = true;
				q.push(next);
			}
		}
	}
	return cnt;
}

bool sortfunc(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	else return p1.second > p2.second;
}
int main() {
	int n, m, a, b;
	vector<int> trust[10001];
	vector<pair<int, int>> hackable;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		trust[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		hackable.push_back(make_pair(i, bfs(trust, i)));
	}
	sort(hackable.begin(), hackable.end(), sortfunc);
	int max_cnt = hackable[0].second;
	for (int i = 0; i <= n; i++) {
		if (hackable[i].second == max_cnt)
			printf("%d ", hackable[i].first);
		else break;
	}
	printf("\n");
	return 0;
}