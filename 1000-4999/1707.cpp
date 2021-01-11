//BaekJoon_1707
//�̺� �׷���
/*
* ���� �ð� : 2s
* ���� ���� : 22.271%
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[20010];
vector<int> check(20010, 0);

void dfs(int now, int team) {
	check[now] = team;
	int next_team = 3 - team;	// ���� 1�̸� 2, 2�̸� 1�� �ٲ��
	for (int i = 0; i < graph[now].size(); i++) {
		int next = graph[now][i];
		if (check[next] == 0) {
			dfs(next, next_team);
		}
	}
	return;
}

bool check_bipartite_graph(int v) {
	bool flag = true;

	for (int i = 0; i < v; i++) {
		int this_end = check[i];

		for (int j = 0; j < graph[i].size(); j++) {
			int other_end = check[graph[i][j]];
		
			if (this_end == other_end) {	
				// ������ ��尡 check�� �ϳ��� ������ binary ����
				flag = false;
				return flag;
			}
		}
	}
	return flag;
}
int main() {
	int testcase;
	cin >> testcase;
	while (testcase != 0) {
		int v, e, n, m;
		cin >> v >> e;

		for (int i = 0; i < e; i++) {
			cin >> n >> m;
			graph[n].push_back(m);
			graph[m].push_back(n);
		}

		//dfs
		/* ���� ��Ұ� �������� �� �ִ� */
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0)
				dfs(i, 1);
		}

		//check
		bool is_bi = check_bipartite_graph(v);
		if (is_bi) cout << "YES" << endl;
		else cout << "NO" << endl;

		// �ʱ�ȭ �۾�
		for (int i = 1; i <= v; i++) {
			graph[i].erase(graph[i].begin(), graph[i].end());
			check[i] = 0;
		}
		testcase--;
	}

	return 0;
}