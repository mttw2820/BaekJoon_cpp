//BaekJoon_9019
//DSLR
/*
* 제한 시간 : 6s
* 정답 비율 : 22.546%
*/

#include <iostream>
#include <queue>
#include <string.h>
#include <string>
#include <algorithm>
#define MAX 10000
using namespace std;

int visit[MAX] = { 0, };
int dist[MAX] = { 0, };
int from[MAX] = { 0, };
char button[MAX];

void init() {
	memset(visit, 0, sizeof(visit));
	memset(dist, 0, sizeof(dist));
	memset(from, 0, sizeof(from));
	memset(button, 0, sizeof(button));
}

void print_result(int end) {
	int temp = end;
	string ans = "";
	while (from[temp] != -1) {
		ans += button[temp];
		temp = from[temp];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}

void calculator(int A, int B) {
	queue<int> q;
	q.push(A);
	from[A] = -1;
	visit[A] = -1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		int d = (now * 2) % MAX;
		if (visit[d] != -1) {
			visit[d] = -1;
			from[d] = now;
			dist[d] = dist[now] + 1;
			button[d] = 'D';
			q.push(d);
		}
		if (d == B) break;

		int s = now - 1;
		if (now == 0) s = MAX - 1;
		if (visit[s] != -1) {
			visit[s] = -1;
			from[s] = now;
			dist[s] = dist[now] + 1;
			button[s] = 'S';
			q.push(s);
		}
		if (s == B) break;

		int l = (now % 1000) * 10 + now / 1000;
		if (visit[l] != -1) {
			visit[l] = -1;
			from[l] = now;
			dist[l] = dist[now] + 1;
			button[l] = 'L';
			q.push(l);
		}
		if (l == B) break;
		int r = (now% 10) * 1000 + now / 10;
		if (visit[r] != -1) {
			visit[r] = -1;
			from[r] = now;
			dist[r] = dist[now] + 1;
			button[r] = 'R';
			q.push(r);
		}
		if (r == B) break;
	}

	// print result
	print_result(B);
	init();
	return;
}

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase-- != 0) {
		int A, B;
		scanf("%d %d", &A, &B);
		if (A == B) printf("\n");
		else calculator(A, B);
	}

	return 0;
}