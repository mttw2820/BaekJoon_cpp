//BaekJoon_1012
//유기농 배추
/*
* 제한 시간 : 1s
* 정답 비율 : 35.369%
*/

#include <iostream>
#include <vector>
using namespace std;

vector <int> ans;
int d_x[] = { -1, 0, 1, 0 };
int d_y[] = { 0, 1, 0, -1 };
int m, n, c[51][51];
void find(int x, int y) {
	c[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int n_x = x + d_x[i];
		int n_y = y + d_y[i];
		if (n_x < 0 || n_x == m || n_y < 0 || n_y == n) continue;
		if (c[n_x][n_y] == 0) continue;
		find(n_x, n_y);
	}
	return;
}


int main() {
	int ts;
	cin >> ts;

	for (int t = 0; t < ts; t++) 
	{
		int cnt = 0;
		int k, x, y;
		c[55][55] = { 0, };
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			c[x][y] = 1;
		}

		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				if (c[a][b] == 1) {
					find(a, b);
					cnt++;
				}
			}
		}

		ans.push_back(cnt);
	}

	for (int i = 0; i < ts; i++) {
		cout << ans[i] << endl;
	}


	return 0;
}