//BaekJoon_5014
//스타트링크
/*
* 제한 시간 : 1s
* 정답 비율 : 34.304%
*/

#include <iostream>
#include <queue>
using namespace std;

int visit[1000001] = { 0, };

int main() {
	queue<pair<int, int>> q;
	int height, now, dest, up, down;
	scanf("%d %d %d %d %d", &height, &now, &dest, &up, &down);

	if (now == dest) {
		printf("0\n");
		return 0;
	}

	q.push(make_pair(now, 0));
	while (!q.empty()) {
		int h = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (h == dest) break;

		int next = -1;
		if ((h + up <= height) && (visit[h + up] == 0)) {
			next = h + up;
			visit[next] = cnt + 1;
			q.push(make_pair(next, cnt + 1));
		}
		if ((h - down > 0) && (visit[h - down] == 0)) {
			next = h - down;
			visit[next] = cnt + 1;
			q.push(make_pair(next, cnt + 1));
		}
	}
	if (visit[dest] == 0)
		printf("use the stairs\n");
	else printf("%d\n", visit[dest]);

	return 0;
}