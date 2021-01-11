//BaekJoon_1937
//욕심쟁이 판다
/*
* 제한 시간 : 2s
* 정답 비율 : 29.661%
*/

#include <iostream>
using namespace std;

int n;
int bamboo[500][500];
int dp[500][500] = { 0, };
int d_x[] = { 1, -1, 0, 0 };
int d_y[] = { 0, 0, 1, -1 };

int bfs(int x, int y) {
	if (dp[x][y] != 0) return dp[x][y];

	int now = bamboo[x][y];
	int ans = 0;
	int n_x = 0, n_y = 0;
	for (int i = 0; i < 4; i++) {
		n_x = x + d_x[i];
		n_y = y + d_y[i];
		if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < n) {
			if (now < bamboo[n_x][n_y])
				ans = ans > bfs(n_x, n_y) ? ans : bfs(n_x, n_y);
		}
	}
	dp[x][y] = ans + 1;
	return dp[x][y];
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> bamboo[i][j];
	}

	int MAX = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = bfs(i, j);
			if (temp > MAX) MAX = temp;
		}
	}
	cout << MAX << endl;
	

	return 0;
}