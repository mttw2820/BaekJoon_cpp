//BaekJoon_9205
//맥주 마시면서 걸어가기
/*
* 제한 시간 : 1s
* 정답 비율 : 34.215%
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#define MAX 999999999
using namespace std;

struct node {
	int x;
	int y;

	int man_dist(node n) {
		return abs(n.x - x) + abs(n.y - y);
	}
};

int dist[110][110] = { 0, };

// 점 사이 최소 거리
void setDist(vector<node> vec, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			dist[i][j] = vec[i].man_dist(vec[j]);
	}
}

void bfs(int size) {
	int visit[110] = { 0, };
	int start = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(start, 1));

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (visit[now] != 0) continue;
		visit[now] = cnt;

		for (int i = 0; i < size; i++) {
			if (visit[i] == 0 && dist[now][i] <= 1000) {
				q.push(make_pair(i, cnt + 1));
			}
		}
	}
	if (visit[size - 1] == 0) printf("sad\n");
	else printf("happy\n");

}

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase-- != 0) {
		int n, x, y;
		scanf("%d", &n);
		vector<node> vec(n + 2);


		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &vec[i].x, &vec[i].y);
		}
		setDist(vec, n + 2);
		bfs(n + 2);
	}

	return 0;
}