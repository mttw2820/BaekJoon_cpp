//BaekJoon_1018
//체스판 다시 칠하기
/*
* 제한 시간 : 2s
* 정답 비율 : 45.512%
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string B_first = "BWBWBWBW";
string W_first = "WBWBWBWB";
vector<string> chessMap;

int Black_first(int x, int y) {
	string now = "";
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) now = B_first;
		else now = W_first;
		for (int j = 0; j < 8; j++) {
			if (chessMap[x + i][y + j] != now[j])
				cnt++;
		}
	}
	return cnt;
}
int White_first(int x, int y) {
	string now;
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) now = W_first;
		else now = B_first;
		for (int j = 0; j < 8; j++) {
			if (chessMap[x + i][y + j] != now[j])
				cnt++;
		}
	}
	return cnt;
}

int main() {
	int n, m;
	cin >> n >> m;

	// 두 가지 경우를 모두 카운트 한다
	int bf = 100, wf = 100;
	string chess;
	for (int i = 0; i < n; i++) {
		cin >> chess;
		chessMap.push_back(chess);
	}
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int black = Black_first(i, j);
			int white = White_first(i, j);
			bf = black < bf ? black : bf;
			wf = white < wf ? white : wf;
		}
	}
	int ans = bf > wf ? wf : bf;
	cout << ans << endl;

	return 0;
}