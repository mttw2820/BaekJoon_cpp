//BaekJoon_10026
//적록색약
/*
* 제한 시간 : 1s
* 정답 비율 : 58.114%
*/

#include <iostream>
using namespace std;

int map_rgb[105][105] = { 0, };
int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, 1, -1 };
bool map_normal[105][105] = { 0, };
bool map_rg[105][105] = { 0, };

void count_area_rg(int x, int y, int n) {
	map_rg[x][y] = true;
	int color = map_rgb[x][y];
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + mx[i];
		ny = y + my[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map_rgb[nx][ny] < 3 && color < 3 && !map_rg[nx][ny]) {
			// 적록색약인 사람이 봤을 때 같은 영역
			count_area_rg(nx, ny, n);
		}
	}
}
void count_area(int x, int y, int n) {
	map_normal[x][y] = true;
	map_rg[x][y] = true;
	int color = map_rgb[x][y];
	int nx, ny;
	for (int i = 0; i < 4; i++) {
		nx = x + mx[i];
		ny = y + my[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (map_rgb[nx][ny] == color) {
			if (!map_normal[nx][ny]) {
				// 색이 같은 칸
				count_area(nx, ny, n);
			}
		}
		else if (map_rgb[nx][ny] < 3 && color < 3 && !map_rg[nx][ny]) {
			// 적록색약인 사람이 봤을 때 같은 영역
			count_area_rg(nx, ny, n);
		}
	}
}
int main() {
	int n;
	char input[105];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", input);
		for (int j = 0; j < n; j++) {
			switch (input[j]) {
			case 'R':
				map_rgb[i][j] = 1;
				break;
			case 'G':
				map_rgb[i][j] = 2;
				break;
			case 'B':
				map_rgb[i][j] = 3;
				break;
			}
		}
	}

	int count_normal = 0, count_rg = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!map_normal[i][j]) {
				count_normal++;
				if (!map_rg[i][j]) {
					count_rg++;
				}
				count_area(i, j, n);
			}
		}
	}

	printf("%d %d\n", count_normal, count_rg);
	return 0;
}