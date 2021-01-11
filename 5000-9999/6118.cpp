//BaekJoon_6118
//숨바꼭질
/*
* 제한 시간 : 1s
* 정답 비율 : 50.026%
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#define INF 9999999
using namespace std;

int n, m;
vector<int> map[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
int check[20005] = { 0, };
void DIJ() {
	int ans_node = 0;
	int max_dist = 0;
	int cnt_same = 0;
	q.push(make_pair(0, 1));
	while (!q.empty()) {
		int now = q.top().second;
		int d = q.top().first;
		q.pop();
		if (check[now] == -1) continue;
		check[now] = -1;
		
		// 거리 확인
		if (max_dist < d) {	// 가장 먼 거리
			max_dist = d;
			cnt_same = 1;
			ans_node = now;
		}
		if (max_dist == d) {
			cnt_same++;
			if (ans_node > now) ans_node = now;
		}

		int next;
		for (int i = 0; i < map[now].size(); i++) {
			next = map[now][i];
			if (check[next] != -1) {
				q.push(make_pair(d + 1, next));
			}
		}
	}
	cout << ans_node << " " << max_dist << " " << cnt_same-1 << endl;
	
	return;
}

int main() {
	cin >> n >> m;
	int b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &b, &c);
		map[b].push_back(c);
		map[c].push_back(b);
	}
	DIJ();
	
	
	return 0;
}