//BaekJoon_2178
//미로 탐색
/*
* 제한 시간 : 1s
* 정답 비율 : 37.511%
*/

#include <iostream>
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool visit[101][101];
int maze[101][101] = { 0, };
int n, m;
int ans = 10000;

void getOut(int x, int y, int cnt) {
	visit[x][y] = true;
	if (x == n-1 && y == m-1) {
		if (ans > cnt) ans = cnt;
		visit[x][y] = false;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int to_x = x + dx[i];
		int to_y = y + dy[i];
		if (to_x <0 || to_x == n || to_y <0 || to_y == m) continue;
		if (maze[to_x][to_y] == 0 || visit[to_x][to_y]) continue;
		getOut(to_x, to_y, cnt + 1);
	}
	visit[x][y] = false;
	return;
}

int main() {
	char c[101];
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c;
		for (int j = 0; j < m; j++) {
			maze[i][j] = c[j] - '0';
		}
	}
	
	getOut(0, 0, 1);
	cout << ans << endl;

	return 0;
}