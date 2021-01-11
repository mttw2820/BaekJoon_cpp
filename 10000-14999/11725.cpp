//BaekJoon_11725
//Ʈ���� �θ� ã��
/*
* ���� �ð� : 1s
* ���� ���� : 44.261%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ����� ���� ���Ƽ� cin, cout ��� �� �ð� �ʰ�

int parent[100010] = { 0, };	// �� ����� �θ� ��� ����
vector<int> vec[100010];		// ��忡 ����� ��� ����
int check[100010] = { 0, };		// ��� �湮 üũ

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