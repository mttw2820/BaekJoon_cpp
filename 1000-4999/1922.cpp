//BaekJoon_1922
//네트워크 연결
/*
* 제한 시간 : 2s
* 정답 비율 : 54.847%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct net {
	int from;
	int to;
	int cost;
};

struct cmp {
	bool operator()(net n1, net n2) {
		return n1.cost > n2.cost;
	}
};

int n, m;
int network[1010][1010] = { 0, };
int visited[1010] = { 0, };
int cnt_conn = 0;	// 연결된 컴퓨터 수
int total_cost = 0;	// 연결 비용
priority_queue <net, vector<net>, cmp> Q;

/* PRIM's */
int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		network[a][b] = c;
		network[b][a] = c;
	}

	net start;
	start.from = 0; start.to = 1; start.cost = 0;
	Q.push(start);
	while (cnt_conn < n) {
		// 가장 cost가 적은 간선 선택
		net computer = Q.top();
		int s = computer.from;
		int e = computer.to;
		Q.pop();
		
		// visited 확인
		if (visited[e] == -1) continue;

		// 간선 연결
		visited[e] = -1;
		cnt_conn++;
		total_cost += network[s][e];		

		// 가능한 간선 추가
		net next; next.from = e;
		for (int i = 1; i <= n; i++) {
			if (network[e][i] != 0 && visited[i] != -1) {
				next.to = i; next.cost = network[e][i];
				Q.push(next);
			}
		}
	}

	cout << total_cost << endl;
	return 0;
}