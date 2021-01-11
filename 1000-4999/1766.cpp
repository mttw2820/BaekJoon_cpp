//BaekJoon_1766
//문제집
/*
* 제한 시간 : 2s
* 정답 비율 : 46.815%
*/

#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int n, m;
vector<int> problem[32001];
int indegree[32001] = { 0, };
// 오름차순으로 정렬되는 우선순위 큐
priority_queue<int, vector<int>, greater<int>> Q;


int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		problem[a].push_back(b);
		indegree[b]++;
	}

	// 시작 점 Q에 push
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			Q.push(i);
	}

	while (!Q.empty()) {
		int now = Q.top();
		cout << now << " ";
		Q.pop();
		int next = 0;
		for (int i = 0; i < problem[now].size(); i++) {
			next = problem[now][i];
			indegree[next] --;
			if (indegree[next] == 0)
				Q.push(next);
		}
	}
	cout << endl;

	return 0;
}