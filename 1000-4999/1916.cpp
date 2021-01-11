//BaekJoon_1916
//최소비용 구하기
/*
* 제한 시간 : 0.5s
* 정답 비율 : 32.042%
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct bus {
	int dest;
	int cost;
};

int n, m, city_a, city_b;
vector<bus> connection[1010];
int check[1010] = { 0, };
int prev_city[1010] = { 0, };
long long minpath[1010] = { 0, };

bool comp(int x, int y) {
	return minpath[x] < minpath[y];
}

/*  Dijkstra's  */
void DJ(){
	vector<int> q;
	// 출발점 지정
	q.push_back(city_a);

	while (!q.empty()) {
		sort(q.begin(), q.end(), comp);
		int now = q.front();
		q.erase(q.begin(), q.begin() + 1);

		if (check[now] == -1) continue;
		check[now] = -1;

		bus next;
		for (int i = 0; i < connection[now].size(); i++) {
			next = connection[now][i];
			if (check[next.dest] == 0) {
				if ((minpath[next.dest] == 0) || minpath[now] + next.cost < minpath[next.dest]) {
					minpath[next.dest] = minpath[now] + next.cost;
					prev_city[next.dest] = now;
					q.push_back(next.dest);
				}
			}
		}
	}
	cout << minpath[city_b] << endl;
	return;
}

int main() {
	cin >> n >> m;
	int from, to, cost;
	bus new_bus;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &from, &to, &cost);
		new_bus.dest = to;	new_bus.cost = cost;
		connection[from].push_back(new_bus);
	}
	cin >> city_a >> city_b;
	DJ();

	return 0;
}