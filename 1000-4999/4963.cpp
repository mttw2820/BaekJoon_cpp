//BaekJoon_4963
//���� ����
/*
* ���� �ð� : 1s
* ���� ���� : 48.564%
*/

#include <iostream>
#include <string.h>
using namespace std;

int w, h;
int map[55][55] = { 0, };
int d_x[9] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int d_y[9] = { -1, 0, 1, 1, 1, 0, -1, -1 };

void del(int x, int y) {
	map[x][y] = -1;
	for (int i = 0; i < 8; i++) {
		if (map[x + d_x[i]][y + d_y[i]] == 1)
			del(x + d_x[i], y + d_y[i]);
	}
	return;
}

int main() {
	while (true) {
		int cnt = 0;
		//�Է� �ޱ�
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (map[i][j] == 1) {
					del(i, j);
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
		//���� ������ ���� map �ʱ�ȭ
		memset(map, 0, (w + 1)*(h + 1));
	}

	return 0;
}