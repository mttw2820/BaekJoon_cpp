//BaekJoon_1730
//판화
/*
* 제한 시간 : 2s
* 정답 비율 : 37.092%
*/

#include <iostream>
#include <bitset>
using namespace std;


int main() {
	int n;
	char move[1001];
	bitset<100> hori[100];
	bitset<100> vert[100];
	scanf("%d %s", &n, move);
	
	int x = 0, y = 0;
	for (int i = 0; move[i]; i++) {
		switch (move[i]) {
		case 'D':
			if (x + 1 >= n) continue;
			vert[x++][y] = 1;
			vert[x][y] = 1;
			break;
		case 'U':
			if (x - 1 < 0) continue;
			vert[x--][y] = 1;
			vert[x][y] = 1;
			break;
		case 'L':
			if (y - 1 < 0) continue;
			hori[x][y--] = 1;
			hori[x][y] = 1;
			break;
		case 'R':
			if (y + 1 >= n) continue;
			hori[x][y++] = 1;
			hori[x][y] = 1;
			break;
		}
	}

	// 결과 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (hori[i][j] & vert[i][j] & 1) printf("+");
			else if (hori[i][j] & 1) printf("-");
			else if (vert[i][j] & 1) printf("|");
			else printf(".");
		}
		printf("\n");
	}

	return 0;
}