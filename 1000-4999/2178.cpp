//BaekJoon_2178
//미로 탐색
/*
* 제한 시간 : 1s
* 정답 비율 : 33.681%
*/

#include <iostream>
using namespace std;

int n, m;
int map[105][105] = { 0, };
int dp[105][105] = { 0 };
int d_x[5] = { -1, 0, 1, 0 };
int d_y[5] = { 0, 1, 0, -1 };
void explore(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int n_x = x + d_x[i];
		int n_y = y + d_y[i];
		if (n_x<1 || n_x>n || n_y<1 || n_y>m) continue;
		if (map[n_x][n_y] == 0) continue;
		if (dp[n_x][n_y] == 0 || dp[n_x][n_y] > dp[x][y] + 1) {
			dp[n_x][n_y] = dp[x][y] + 1;
			explore(n_x, n_y);
		}
	}
	return;
}
int main() {
	char temp[101];
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", temp);
		for (int j = 1; j <= m; j++) {
			map[i][j] = temp[j - 1] - '0';
		}
	}
	dp[1][1] = 1;
	explore(1, 1);
	cout << dp[n][m] << endl;

	return 0;
}