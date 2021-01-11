//BaekJoon_17241
//Pineapple Advertising
/*
* 제한 시간 : 1s
* 정답 비율 : 43.820%
*/

#include <iostream>
#include <vector>
#define MAX 200001
using namespace std;

vector<int> conn[MAX];
vector<int> visit(MAX, 0);	// 직접 수령 -2, 냄새 -1

int pineapple(int start) {
	int cnt_new = 0;
	if (visit[start] == -2) { return 0;}	// 피자 받은 적 있음
	if (visit[start] >= 0) {
		// 냄새도 맡은 적 없음
		cnt_new++;
		visit[start] = -2;
	}
	for (int i = 0; i < conn[start].size(); i++) {
		int neighbor = conn[start][i];
		if (visit[neighbor] >= 0) {
			cnt_new++;
			visit[neighbor] = -1;
		}
	}

	return cnt_new;
}

int main() {
	int N, M, Q, a, b;
	scanf("%d %d %d", &N, &M, &Q);

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		conn[a].push_back(b);
		conn[b].push_back(a);
	}

	int new_pineapple = 0;
	for (int i = 0; i < Q; i++) {
		scanf("%d", &a);
		new_pineapple = pineapple(a);
		printf("%d\n", new_pineapple);
	}

	return 0;
}