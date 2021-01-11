//BaekJoon_2251
//물통
/*
* 제한 시간 : 2s
* 정답 비율 : 47.980%
*/

#include <iostream>
#include <queue>
using namespace std;

void print_ans(int ans[], int c) {
	for (int i = 0; i <= c; i++) {
		if (ans[i] == 1) {
			printf("%d ", i);
		}
	}
	printf("\n");
	return;
}
void pour(int max_a, int max_b, int max_c) {
	int visit[201][201] = { 0, };
	int ans[201] = { 0, };
	queue<pair<int, int>> q; // a와 b의 양을 저장
	q.push(make_pair(0, 0));
	visit[0][0] = 1; ans[max_c] = 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		int c = max_c - (a + b);
		q.pop();

		int na = 0, nb = 0, nc = 0;
		if (a != 0) {
			// a -> b
			if (b != max_b) {
				if (a <= max_b - b) {
					// all in
					na = 0;	nb = a + b; nc = max_c - nb;
					if (visit[na][nb] != 1) {
						visit[na][nb] = 1;
						ans[nc] = 1;
						q.push(make_pair(na, nb));
					}
				}
				else {
					na = a + b - max_b;	nb = max_b;
					if (visit[na][nb] != 1) {
						visit[na][nb] = 1;
						q.push(make_pair(a - (max_b - b), max_b));
					}
				}
			}
			// a -> c
			if (c != max_c) {
				if (a <= max_c - c) {
					na = 0;	 nb = b;
					if (visit[na][nb] != 1) {
						visit[na][nb] = 1;
						ans[max_c - na - nb] = 1;
						q.push(make_pair(na, nb));
					}
				}
			}
		}
		if (b != 0) {
			// b -> a
			if (a != max_a) {
				if (b <= max_a - a) {
					// all in
					na = a + b;  nb = 0;
					if (visit[na][nb] != 1) {
						visit[na][nb] = 1;
						q.push(make_pair(na, nb));
					}
				}
				else {
					na = max_a; nb = a + b - max_a;
					if (visit[na][nb] != 1) {
						visit[na][nb] = 1;
						q.push(make_pair(na, nb));
					}
				}
			}
			// b -> c
			if (c != max_c) {
				if (b <= max_c - c) {
					na = a;	nb = 0; nc = max_c - (na + nb);
					if (visit[na][nb] != 1) {
						visit[na][nb] = 1;
						if (na == 0)
							ans[nc] = 1;
						q.push(make_pair(na, nb));
					}
				}
			}
		}
		if (c != 0) {
			// c -> a
			if (c <= max_a - a) {
				// all in
				na = a + c; nb = b; nc = 0;
				if (visit[na][nb] != 1) {
					visit[na][nb] = 1;
					q.push(make_pair(na, nb));
				}
			}
			else {
				na = max_a;	nb = b;	nc = a + c - max_a;
				if (visit[na][nb] != 1) {
					visit[na][nb] = 1;
					q.push(make_pair(na, nb));
				}
			}
			// c -> b
			if (c <= max_b - b) {
				// all in
				na = a; nb = b + c; nc = 0;
				if (visit[na][nb] != 1) {
					visit[na][nb] = 1;
					if(na == 0) ans[nc] = 1;
					q.push(make_pair(na, nb));
				}
			}
			else {
				na = a; nb = max_b; nc = b + c - max_b;
				if (visit[na][nb] != 1) {
					visit[na][nb] = 1;
					if(na == 0) ans[nc] = 1;
					q.push(make_pair(na, nb));
				}
			}
		}
	}
	print_ans(ans, max_c);
	return;
}
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	pour(a, b, c);

	return 0;
}