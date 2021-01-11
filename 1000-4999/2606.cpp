//BaekJoon_2606
//바이러스
/*
* 제한 시간 : 1s
* 정답 비율 : 40.672%
*/

#include <iostream>
using namespace std;

int com[101][101] = { 0, };
int visit[101] = { 0, };
int n, m, cnt = 0;

void dfs(int now) {
	int next = 0;
	visit[now] = -1;
	
	for (int i = 1; i <= n; i++) {
		if (com[now][i] == 1 && visit[i]>=0) {
			dfs(i);
			cnt++;
		}
	}
	return;
}

int main() {
	int x, y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		com[x][y] = 1;
		com[y][x] = 1;
	}
	dfs(1);
	printf("%d\n", cnt);
	
	return 0;
}