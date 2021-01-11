//BaekJoon_1922
//��Ʈ��ũ ����
/*
* ���� �ð� : 2s
* ���� ���� : 54.847%
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
int cnt_conn = 0;	// ����� ��ǻ�� ��
int total_cost = 0;	// ���� ���
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
		// ���� cost�� ���� ���� ����
		net computer = Q.top();
		int s = computer.from;
		int e = computer.to;
		Q.pop();
		
		// visited Ȯ��
		if (visited[e] == -1) continue;

		// ���� ����
		visited[e] = -1;
		cnt_conn++;
		total_cost += network[s][e];		

		// ������ ���� �߰�
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