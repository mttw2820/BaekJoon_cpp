//BaekJoon_1915
//가장 큰 정사각형
/*
* 제한 시간 : 2s
* 정답 비율 : 28.870%
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1010][1010] = { 0, };
int main() {
	int n, m;
	string in;
	vector<string> map;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> in;
		map.push_back(in);
	}

	int MAX = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || j == 0) {
				if (map[i][j] == '0') dp[i][j] = 0;
				else dp[i][j] = 1;
			}
			else {
				if (map[i][j] == '0') {
					dp[i][j] = 0;
					continue;
				}
				// 현재 '1'인 경우
				if (map[i - 1][j - 1] * map[i][j - 1] * map[i - 1][j] != 0) {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i-1][j], dp[i][j-1])) + 1;
				}
				else map[i][j] = 1;
			}
			if (dp[i][j] > MAX) MAX = dp[i][j];
		}
	}

	cout << MAX * MAX << endl;
	return 0;
}