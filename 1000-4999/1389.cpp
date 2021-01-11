//BaekJoon_1389
//케빈 베이컨의 6단계 법칙
/*
* 제한 시간 : 2s
* 정답 비율 : 53.615%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> conn[110];

int bacon(int start) {
	int sum_bacon = 0, level = 0;
	int visit[110] = { 0, };
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int curSize = q.size();
		for (int i = 0; i < curSize; i++) {
			int now = q.front();
			q.pop();
			if (visit[now] == -1) continue;
			// 새로운 노드 - 거리를 더한다
			visit[now] = -1;
			sum_bacon += level;

			for (int j = 0; j < conn[now].size(); j++) {
				// 연결된 노드 중 방문하지 않은 노드를 q에 push
				int next = conn[now][j];
				if (visit[next] == -1) continue;
				q.push(next);
			}
		}
		level++;
	}

	return sum_bacon;
}

int main() {
	int N, M, a, b;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}

	// 모든 유저들의 케빈 베이컨 수를 구한다.
	int min_node = 0, min_bacon = 99999999999;
	for (int i = 1; i <= N; i++) {
		int bac = bacon(i);
		if (bac < min_bacon) {
			min_node = i;
			min_bacon = bac;
		}
	}
	printf("%d\n", min_node);

	return 0;
}