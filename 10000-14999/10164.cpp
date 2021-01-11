//BaekJoon_10164
//격자상의 경로
/*
* 제한 시간 : 1s
* 정답 비율 : 33.598%
*/

#include <iostream>
using namespace std;

int n, m, k;
long long path[20][20] = { 0, };
long long count_path(int sx, int sy, int ex, int ey);

int main() {
	cin >> n >> m >> k;
	path[1][1] = 1;
	long long ans = 0;
	if (k == 0 || k == n*m) 
		ans = count_path(1, 1, n, m);
	else {
		int checkpoint_x = k / m + 1;
		int checkpoint_y = 0;
		if (k%m == 0) {
			checkpoint_x --;
			checkpoint_y = m;
		}
		else checkpoint_y = k%m;
		
		count_path(1, 1, checkpoint_x, checkpoint_y);
		ans = count_path(checkpoint_x, checkpoint_y, n, m);
	}

	cout << ans << endl;

	return 0;
}

long long count_path(int sx, int sy, int ex, int ey) {
	for (int x = sx; x <= ex; x++) {
		for (int y = sy; y <= ey; y++) {
			if (x == sx && y == sy) 
				continue;
			path[x][y] = path[x - 1][y] + path[x][y - 1];
		}
	}
	return path[ex][ey];
}