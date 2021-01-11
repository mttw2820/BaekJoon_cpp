//BaekJoon_11725
//트리의 부모 찾기
/*
* 제한 시간 : 1s
* 정답 비율 : 44.261%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입출력 수가 많아서 cin, cout 사용 시 시간 초과

int parent[100010] = { 0, };	// 각 노드의 부모 노드 저장
vector<int> vec[100010];		// 노드에 연결된 노드 저장
int check[100010] = { 0, };		// 노드 방문 체크

void bfs() {
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (check[now] == -1) continue;
		check[now] = -1;

		for (int i = 0; i < vec[now].size(); i++) {
			int next = vec[now][i];
			if (check[next] != -1) {
				parent[next] = now;
				q.push(next);
			}
		}
	}
	return;
}

void print_parents(int n) {
	for(int i=2;i<=n;i++){
		printf("%d\n", parent[i]);
	}
	return;
}
int main() {
	int n;
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	bfs();
	print_parents(n);

	return 0;
}