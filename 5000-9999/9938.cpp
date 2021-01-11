//BaekJoon_9938
//방 청소
/*
* 제한 시간 : 1s
* 정답 비율 : 31.114%
*/

#include <iostream>
using namespace std;

int p[300001];
bool visit[300001];

int find(int node) {
	if (p[node] == node) return node;
	else return p[node] = find(p[node]);
}
void unite(int a, int b) {
	a = find(a);
	b = find(b);
	p[a] = b;
	printf("LADICA\n");
	return;
}

int main() {
	int N, L, a, b;
	scanf("%d %d", &N, &L);

	for (int i = 1; i <= L; i++) {
		p[i] = i;
	}
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);

		if (!visit[a]) {
			visit[a] = true;
			unite(a, b);
		}
		else if (!visit[b]) {
			visit[b] = true;
			unite(b, a);
		}
		else if (!visit[find(p[a])]) {
			// roota에 저장
			visit[find(p[a])] = true;
			unite(a, b);
		}
		else if (!visit[find(p[b])]) {
			// rootb에 저장
			visit[find(p[b])] = true;
			unite(b, a);
		}
		else {
			printf("SMECE\n");
		}
	}

	return 0;
}