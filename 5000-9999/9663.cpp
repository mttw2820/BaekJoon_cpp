//BaekJoon_9663
//N-Queen
/*
* ���� �ð� : 10s
* ���� ���� : 55.512%
*/

#include <iostream>
using namespace std;

long long ans = 0;
bool chessmap[20][20] = { 0, };	// ���� ���̸� true

bool check_map(int row, int col, int n) {
	for (int i = 0; i < row; i++) {
		// ����
		if (chessmap[i][col]) return false;
		// �밢��
		else if ((col - (row - i)) >= 0 && chessmap[i][col - row + i]) return false;
		else if ((col + (row - i)) < n && chessmap[i][col + row - i]) return false;
	}

	return true;
}
void chess(int row, int n) {
	if (row == n) {
		ans++;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (check_map(row, col, n)) {
			chessmap[row][col] = true;
			chess(row + 1, n);
			chessmap[row][col] = false;
		}
	}
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	chess(0, n);
	printf("%lld\n", ans);
	return 0;
}