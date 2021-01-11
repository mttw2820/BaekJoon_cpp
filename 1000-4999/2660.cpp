//BaekJoon_2660
//회장뽑기
/*
* 제한 시간 : 1s
* 정답 비율 : 54.643%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> frnd[55];

int bfs(int start, int size) {
	int visited[55] = { 0, };
	queue <pair<int, int>> q;
	q.push(make_pair(start, 0));

	int score = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int sc = q.front().second;
		q.pop();
		if (visited[now] == -1) continue;
		visited[now] = -1;
		score = sc;

		for (int i = 0; i<frnd[now].size(); i++) {
			int next = frnd[now][i];
			if (visited[next] != -1) {
				q.push(make_pair(next, sc + 1));
			}
		}
	}

	return score;
}
int main() {
	int n, a, b;
	scanf("%d", &n);
	while (true) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1) break;
		frnd[a].push_back(b);
		frnd[b].push_back(a);
	}

	int min_score = 50;
	int cnt = 0;
	vector<int> result(50, 0);
	for (int i = 1; i <= n; i++) {
		//bfs로 score 내기
		int score = bfs(i, n);
		if (min_score > score) {
			min_score = score;
			cnt = 0;
			result[cnt++] = i;
		}
		else if (min_score == score) {
			result[cnt++] = i;
		}
	}

	printf("%d %d\n", min_score, cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	return 0;
}