//BaekJoon_2056
//작업
/*
* 제한 시간 : 2s
* 정답 비율 : 30.107%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> work[10010];	// 다음 작업 번호, 시간
int work_time[10010] = { 0, };
int indegree[10010] = { 0, };
vector<pair<int, int>> Q_vec;	// 실행 중인 작업 <번호, 남은 시간>

bool sort_by_workTime(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}
int main() {
	cin >> n;
	int m = 0, next = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &work_time[i], &m);

		for (int j = 0; j < m; j++) {
			scanf("%d", &next);
			work[i].push_back(next);
			indegree[next]++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			Q_vec.push_back(make_pair(i, work_time[i]));
		}
	}

	int clock = 0;
	while (!Q_vec.empty()) {
		sort(Q_vec.begin(), Q_vec.end(), sort_by_workTime);
		int min_work = Q_vec[0].first;
		int min_work_time = Q_vec[0].second;
		Q_vec.erase(Q_vec.begin(), Q_vec.begin() + 1);

		// 작업 시간 경과
		clock += min_work_time;
		for (int i = 0; i < Q_vec.size(); i++)
			Q_vec[i].second -= min_work_time;

		// 다음 작업 확인
		int next = 0;
		for (int i = 0; i < work[min_work].size(); i++) {
			next = work[min_work][i];
			indegree[next] --;
			if (indegree[next] == 0) {
				Q_vec.push_back(make_pair(next, work_time[next]));
			}
		}
	}

	cout << clock << endl;

	return 0;
}