//BaekJoon_3085
//사탕 게임
/*
* 제한 시간 : 1s
* 정답 비율 : 31.201%
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int board[55][55] = { 0, };
int d_x[] = { 0, 1, 0, -1 };
int d_y[] = { 1, 0 , -1, 0 };

// 가로 세로에 가장 긴 연속 부분 찾기
int cnt_candy(int x, int y) {
	//가로
	int max_line = 0;
	int now = 1;
	for (int j = 0; j < n; j++) {
		now = 1;
		for (int i = 0; i < n - 1; i++) {
			if (board[j][i] == board[j][i + 1])
				now++;
			else {
				max_line = max(max_line, now);
				now = 1;
			}
		}
		max_line = max(max_line, now);
	}
	//세로
	for (int j = 0; j < n; j++) {
		now = 1;
		for (int i = 0; i < n - 1; i++) {
			if (board[i][j] == board[i + 1][j])
				now++;
			else {
				max_line = max(max_line, now);
				now = 1;
			}
		}
		max_line = max(max_line, now);
	}
	return max_line;
}

void swap(int x, int y, int n_x, int n_y) {
	int temp = board[x][y];
	board[x][y] = board[n_x][n_y];
	board[n_x][n_y] = temp;
	return;
}
int swap_candy(int x, int y) {
	int max_candy = 0;

	for (int i = 0; i < 2; i++) {
		int n_x = x + d_x[i];
		int n_y = y + d_y[i];
		if (n_x >= 0 && n_x < n && n_y >= 0 && n_y < n) {
			// 서로 다른 캔디
			if (board[x][y] == board[n_x][n_y]) continue;
			// 자리바꾸기
			swap(x, y, n_x, n_y);
			// 확인
			int first = cnt_candy(x, y);
			int second = cnt_candy(n_x, n_y);
			// 제자리
			swap(x, y, n_x, n_y);
			// 비교
			max_candy = max(max_candy, max(first, second));
		}
	}
	return max_candy;
}

int main() {
	cin >> n;
	string line;
	for (int i = 0; i < n; i++) {
		cin >> line;
		for (int j = 0; j < n; j++) {
			board[i][j] = line[j] - 'A';
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int test = swap_candy(i, j);
			if (ans < test) ans = test;
		}
	}

	cout << ans << endl;
	return 0;
}