//BaekJoon_3780
//네트워크 연결
/*
* 제한 시간 : 1s
* 정답 비율 : 23.501%
*/

#include <iostream>
#include <math.h>
using namespace std;

int p[20001];
int len[20001];

int find(int node) {	
	// root노드와 root노드까지의 거리
	if (p[node] == node) return node;
	else {
		int root = find(p[node]);
		len[node] += len[p[node]];
		return p[node] = root;
	}
}

void unite(int a, int b) {
	len[a] = abs(a - b) % 1000;
	p[a] = b;
}

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int n, a, b;
		char op[3];
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			p[i] = i;
			len[i] = 0;
		}

		while (true) {
			scanf("%s", op);

			if (op[0] - 'O' == 0) break;
			switch(op[0]){
			case 'E' :
				scanf("%d", &a);
				find(a);
				printf("%d\n", len[a]);
				break;
			case 'I' :
				scanf("%d %d", &a, &b);
				unite(a, b);
				break;
			}
		}
	}

	return 0;
}