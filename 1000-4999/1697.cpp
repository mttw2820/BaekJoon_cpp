//BaekJoon_1697
//숨바꼭질
/*
* 제한 시간 : 2s
* 정답 비율 : 24.762%
*/

#include <iostream>
#include <queue>
using namespace std;

int visit[100001] = { 0, };

int main() {
	int start, dest;
	scanf("%d %d", &start, &dest);

	if (start == dest) {
		printf("0\n");
		return 0;
	}

	int ans = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	visit[start] = -1;
	while (!q.empty()) {
		int now = q.front().first;
		int step = q.front().second;
		q.pop();

		// 종료조건
		if (now == dest) {
			ans = step;
			break;
		}

		int left = now - 1;
		int right = now + 1;
		int tele = now * 2;
		if (left >= 0 && visit[left]!= -1) {
			visit[left] = -1;
			q.push(make_pair(left, step + 1));
		}
		if (right <= 100000 && visit[right]!=-1) {
			q.push(make_pair(right, step + 1));
		}
		if (now != 0 && tele <= 100000 && visit[tele]!=-1) {
			q.push(make_pair(tele, step + 1));
		}
	}

	printf("%d\n", ans);

	return 0;
}