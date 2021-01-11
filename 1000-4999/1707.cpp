//BaekJoon_1707
//이분 그래프
/*
* 제한 시간 : 2s
* 정답 비율 : 22.271%
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[20010];
vector<int> check(20010, 0);

void dfs(int now, int team) {
	check[now] = team;
	int next_team = 3 - team;	// 지금 1이면 2, 2이면 1로 바뀐다
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
				// 인접한 노드가 check가 하나라도 같으면 binary 실패
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
		/* 연결 요소가 여러개일 수 있다 */
		for (int i = 1; i <= v; i++) {
			if (check[i] == 0)
				dfs(i, 1);
		}

		//check
		bool is_bi = check_bipartite_graph(v);
		if (is_bi) cout << "YES" << endl;
		else cout << "NO" << endl;

		// 초기화 작업
		for (int i = 1; i <= v; i++) {
			graph[i].erase(graph[i].begin(), graph[i].end());
			check[i] = 0;
		}
		testcase--;
	}

	return 0;
}