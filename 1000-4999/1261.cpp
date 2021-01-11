//BaekJoon_1261
//알고스팟
/*
* 제한 시간 : 1s
* 정답 비율 : 39.170%
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 99999
using namespace std;

int n, m;
vector<string> vec;
queue<pair<int, int>> q;
int cnt[110][110] = { 0, };
int d_x[] = { 0, 0, 1, -1 };
int d_y[] = { 1, -1, 0, 0 };

void algosPOT() {
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < m + 1; j++)
			cnt[i][j] = INF;
	}

	q.push(make_pair(0, 0));
	cnt[0][0] = 0;

	// 빈방에서 빈방으로 이동할 때는 cnt그대로
	// 벽에서 빈방으로 이동할 때도 cnt 그대로
	// 그 외에는 cnt+1보다 작으면 이동, 아니면 냅두기
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int n_x, n_y;
		for (int i = 0; i < 4; i++) {
			n_x = x + d_x[i];
			n_y = y + d_y[i];
			if (n_x < 0 || n_x >= n || n_y < 0 || n_y >= m) continue;
			// 방으로 이동하는 경우
			if (vec[n_x][n_y] == '0' && cnt[x][y] < cnt[n_x][n_y]) {
				cnt[n_x][n_y] = cnt[x][y];
				q.push(make_pair(n_x, n_y));
			}
			else if (cnt[x][y] + 1 < cnt[n_x][n_y]) {
				cnt[n_x][n_y] = cnt[x][y] + 1;
				q.push(make_pair(n_x, n_y));
			}
		}
	}

	// 출력
	cout << cnt[n - 1][m - 1] << endl;
	return;
}
int main() {
	cin >> m >> n;
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(temp);
	}
	algosPOT();

	return 0;
}