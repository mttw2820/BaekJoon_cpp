//BaekJoon_1260
//DFS와 BFS
/*
* 제한 시간 : 2s
* 정답 비율 : 31.546%
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
vector<int> d_check(1001, 0);
vector<int> b_check(1001, 0);

void DFS(int now) {
	// check
	d_check[now] = -1;
	cout << now << " ";
	// go deep
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (d_check[next] != -1) {
			d_check[next] = -1;
			DFS(next);
		}
	}
	return;
}

void BFS(int start) {
	queue<int> Q;
	Q.push(start);
	b_check[start] = -1;
	while (!Q.empty()) {
		int now = Q.front();
		cout << now << " ";
		Q.pop();
		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i];
			if (b_check[next] != -1) {
				Q.push(next);
				b_check[next] = -1;
			}
		}
	}
	return;
}
int main() {
	int n, m, start;
	cin >> n >> m >> start;

	int s, e;
	for (int i = 0; i < m; i++) {
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 작은거 순서대로 정렬
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	
	// DFS
	DFS(start);
	cout << endl;
	// BFS
	BFS(start);
	cout << endl;

	return 0;
}