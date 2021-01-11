//BaekJoon_7576
//토마토
/*
* 제한 시간 : 1s
* 정답 비율 : 31.440%
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> tom[1010];	// pair(x, y), tomato
queue<pair<int, int>> Q;
int d_x[] = { 1, -1, 0, 0 };
int d_y[] = { 0, 0, 1, -1 };

void bfs() {
	int x = 0, y = 0, today = 0, n_x = 0, n_y = 0;
	while (!Q.empty()) {
		x = Q.front().first;
		y = Q.front().second;
		today = tom[x][y].second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			n_x = x + d_x[i];
			n_y = y + d_y[i];
			if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < m) {
				if (tom[n_x][n_y].second == -1) continue;
				if (tom[n_x][n_y].second == 0) {
					tom[n_x][n_y].second = today + 1;
					Q.push(make_pair(n_x, n_y));
				}
				else if (tom[n_x][n_y].second > today + 1)
					tom[n_x][n_y].second = today + 1;
					// Q에는 이미 들어가 있음
			}
		}

	}

	return;
}

int main() {
	int in;
	cin >> m >> n;
	
	bool flag = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &in);
			tom[i].push_back(make_pair(make_pair(i, j), in));
			if (in == 1) Q.push(make_pair(i, j));
			if (in == 0) flag = false;
		}
	}

	if (flag) {
		// 처음부터 모두 익은 상태
		cout << "0" << endl;
		return 0;
	}
	
	// BFS
	bfs();

	// 결과 확인
	int days = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tom[i][j].second == 0) {
				days = -1;
				break;
			}
			if (tom[i][j].second > days) days = tom[i][j].second;
		}
		if (days < 0) break;
	}
	if (days > 0) days--;
	cout << days << endl;

	return 0;
}