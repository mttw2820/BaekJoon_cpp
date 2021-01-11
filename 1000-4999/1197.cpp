//BaekJoon_1197
//�ּ� ���д� Ʈ��
/*
* ���� �ð� : 2s
* ���� ���� : 38.239%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct edge {
	int start;
	int end;
	int cost;
};

struct comp {	// cost�� ���� ������ edge�� priority_queue ����
	bool operator()(edge e1, edge e2) {
		return e1.cost > e2.cost;
	}
};

int v, e;
// ����� �׷��� ���� ����
// pair<���� ���, cost>
vector<pair<int, int>> graph[10010];	
priority_queue<edge, vector<edge>, comp> pq;

/* PRIM's */
void prims() {
	edge temp;	// ������
	temp.start = 0; temp.end = 1; temp.cost = 0;
	pq.push(temp);

	int total_cost = 0;
	int visited[10010] = { 0, };
	while (!pq.empty()) {
		edge now = pq.top();
		int s = now.start;
		int e = now.end;
		int c = now.cost;
		pq.pop();

		if (visited[e] == -1) continue;
		visited[e] = -1;
		total_cost += c;

		// ���� ���� ��� �߰�
		edge next;
		next.start = e;
		for (int i = 0; i < graph[e].size(); i++) {
			if (visited[graph[e][i].first] != -1) {
				next.end = graph[e][i].first;
				next.cost = graph[e][i].second;
				pq.push(next);
			}
		}
	}

	// ��� ���
	cout << total_cost << endl;

	return;
}


int main() {
	cin >> v >> e;
	int a, b, c;
	for (int i = 0; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}

	// Find MST's minimum cost
	prims();

	return 0;
}