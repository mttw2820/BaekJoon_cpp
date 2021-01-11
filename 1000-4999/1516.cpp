//BaekJoon_1516
//게임 개발
/*
* 제한 시간 : 2s
* 정답 비율 : 46.488%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int build_time[501] = { 0, };
vector<int> next_building[501];
int indegree[501] = { 0, };
int ans[501] = { 0, };

bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1.second < p2.second;
}
int main() {
	cin >> n;
	int prev_building = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &build_time[i]);
		scanf("%d", &prev_building);
		while (prev_building != -1) {
			next_building[prev_building].push_back(i);
			indegree[i]++;
			scanf("%d", &prev_building);
		}
	}

	vector<pair<int, int>> Q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			Q.push_back(make_pair(i, build_time[i]));
	}
	
	int total_time = 0;
	while (!Q.empty()) {
		sort(Q.begin(), Q.end(), comp);
		int now = Q[0].first;
		int time = Q[0].second;
		Q.erase(Q.begin(), Q.begin() + 1);
		
		// 시간
		total_time += time;
		ans[now] = total_time;
		for (int i = 0; i < Q.size(); i++)
			Q[i].second -= time;

		// 다음 건물
		for (int i = 0; i < next_building[now].size(); i++) {
			int next = next_building[now][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				Q.push_back(make_pair(next, build_time[next]));
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}