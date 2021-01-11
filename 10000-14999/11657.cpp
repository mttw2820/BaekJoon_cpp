//BaekJoon_11657
//타임머신
/*
* 제한 시간 : 1s
* 정답 비율 : 30.443%
*/

#include <iostream>
#include <vector>
#define INF 9999999
using namespace std;

struct machine {
	int start;
	int end;
	int cost;
};

int n, m;
vector<machine> vec;
int time[550] = { 0, };
int negative[550] = { 0, };

bool negative_cycle() {
	bool flag = false;
	for (int i = 0; i < m; i++) {
		int from = vec[i].start;
		int to = vec[i].end;
		int cost = vec[i].cost;
		if (time[from] == INF) continue;
		if (time[to] > time[from] + cost) {
			time[to] = time[from] + cost;
			flag = true;
			break;
		}
	}
	return flag;
}
void timemachine() {
	time[1] = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < m; i++) {
			int from = vec[i].start;
			int to = vec[i].end;
			int cost = vec[i].cost;
			if (time[from] == INF) continue;
			if (time[to] > time[from] + cost)
				time[to] = time[from] + cost;
		}
	}
	// negative cycle 확인
	if (negative_cycle()) cout << "-1" << endl;
	else {
		for (int i = 2; i <= n; i++) {
			if (time[i] == INF) cout << "-1" << endl;
			else cout << time[i] << endl;
		}
	}
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		time[i] = INF;

	int a, b, c;
	machine scan;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		scan.start = a; scan.end = b; scan.cost = c;
		vec.push_back(scan);
	}

	timemachine();

	return 0;
}