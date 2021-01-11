//BaekJoon_1238
//파티
/*
* 제한 시간 : 1s
* 정답 비율 : 43.228%
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#define INF 9999999
using namespace std;

int n, m, x;
vector<pair<int, int>> road[1010];
int check[1010] = { 0, };
int d_result[1010] = { 0, };
int f_result[1010][1010] = { 0, };

/* all node to all node */
void FW() {
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (f_result[i][k] != INF && f_result[k][j] != INF)
					f_result[i][j] = min(f_result[i][j], f_result[i][k] + f_result[k][j]);
			}
		}
	}
	return;
}

/* one node to all node */
void DIJ() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, x));

	while (!q.empty()) {
		int now = q.top().second;
		q.pop();

		if (check[now] != 0) continue;
		check[now] = -1;

		for (int i = 0; i < road[now].size(); i++) {
			int next = road[now][i].first;
			if (d_result[next] == 0 || d_result[next] > d_result[now] + road[now][i].second) {
				d_result[next] = d_result[now] + road[now][i].second;
				if (check[next] == 0)
					q.push(make_pair(d_result[next], next));
			}
		}
	}
	return;
}

int main() {
	cin >> n >> m >> x;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f_result[i][j] = INF;
		}
	}
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		road[a].push_back(make_pair(b, c));
		f_result[a][b] = c;
	}

	FW();
	DIJ();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		if (ans < f_result[i][x] + d_result[i])
			ans = f_result[i][x] + d_result[i];
	}
	cout << ans << endl;

	return 0; 
}