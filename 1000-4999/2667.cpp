#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int d_x[] = {1, 0, -1, 0};
int d_y[] = {0, 1, 0, -1};
int n, sum = 0;
int map[26][26] = { {0,0}, };

void house(int x, int y) {
	map[x][y] = 0;
	sum++;
	for (int i = 0; i < 4; i++) {
		int n_x = x + d_x[i];
		int n_y = y + d_y[i];
		if (n_x <0 || n_x == n || n_y <0 || n_y == n) continue;
		if (map[n_x][n_y] == 0) continue;
		house(n_x, n_y);
	}
	return;
}

int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	int cnt = 0, ans[650] = { 0, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				house(i, j);
				ans[cnt++] = sum;
				sum = 0;
			}
		}
	}

	sort(ans, ans + cnt);
	cout << cnt << endl;
	for (int i = 0; i < cnt; i++) {
		cout << ans[i] << endl;
	}


	return 0;
}