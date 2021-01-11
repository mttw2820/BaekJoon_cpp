//BaekJoon_2252
//줄 세우기
/*
* 제한 시간 : 2s
* 정답 비율 : 51.767%
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> student[32001];	// student[i] : 학생 i 뒤에 서야하는 학생들
int indegree[32001] = { 0, };
queue<int> Q;

int main() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		student[a].push_back(b);
		indegree[b]++;
	}

	// 시작점 찾기
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			Q.push(i);
	}
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();
		cout << now << " ";
		int next = 0;
		for (int i = 0; i < student[now].size(); i++) {
			next = student[now][i];
			indegree[next]--;
			if (indegree[next] == 0) Q.push(next);
		}
	}
	cout << endl;

	return 0;
}