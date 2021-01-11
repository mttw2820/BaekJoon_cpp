//BaekJoon_1948
//임계경로
/*
* 제한 시간 : 2s
* 정답 비율 : 28.058%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 가능한 모든 경로 탐색, 모든 경로 이동자가 모이는 시간
   == 최장 시간 */
int n, m;
vector<pair<int, int>> next_city[10010];	// 다음 도시, 거리
vector<pair<int, int>> prev_city[10010];	// 이전 도시, 거리
queue<int> Q;
int Time[10010] = { 0, };

int main() {
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		next_city[a].push_back(make_pair(b, c));
		prev_city[b].push_back(make_pair(a, c));
	}
	int start = 0, end = 0;
	cin >> start >> end;

	// 최장 경로 시간
	Q.push(start);
	while (!Q.empty()) {
		int now = Q.front();
		int t = Time[now];
		Q.pop();

		for (int i = 0; i < next_city[now].size(); i++) {
			int next = next_city[now][i].first;
			int path = next_city[now][i].second;
			if (t + path > Time[next]) {
				Time[next] = t + path;
				Q.push(next);
			}
		}
	}
	int result_time = Time[end];

	// 최장 경로 도로의 수
	int path_cnt = 0;
	Q.push(end);
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		for (int i = 0; i < prev_city[now].size(); i++) {
			int prev = prev_city[now][i].first;
			int path = prev_city[now][i].second;
			if (prev_city[now][i].second == -1) continue;
			if (Time[now] - path == Time[prev]) {
				//한번 지난 path는 다시 count되면 안되니까 지우기
				prev_city[now][i].second = -1;
				path_cnt++;
				Q.push(prev);
			}
		}
	}

	cout << result_time << endl << path_cnt << endl;

	return 0;
}