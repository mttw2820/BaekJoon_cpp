//BaekJoon_1976
//여행 가자
/*
* 제한 시간 : 2s
* 정답 비율 : 40.584%
*/

#include <iostream>
using namespace std;

int parent[210] = { 0, };
int find_root(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = find_root(parent[node]);
}

int main() {
	int n, m, conn;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &conn);
			if (conn == 1) {
				int a = find_root(i);
				int b = find_root(j);
				if (a != b) {
					// union
					parent[b] = a;
				}
			}
		}
	}

	bool flag = true;
	scanf("%d", &conn);
	int root = find_root(conn-1);
	for (int i = 1; i < m; i++) {
		scanf("%d", &conn);
		if (find_root(conn-1) != root) {
			flag = false;
		}
	}

	if (flag) printf("YES\n");
	else printf("NO\n");

	return 0;
}