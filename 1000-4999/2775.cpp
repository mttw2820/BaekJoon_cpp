//BaekJoon_2775
//부녀회장이 될테야
/*
* 제한 시간 : 1s
* 정답 비율 : 57.615%
*/

#include <iostream>
using namespace std;

void cnt();
int ppl[100];
int apart[15][15];
int main() {
	int t, k, n;
	cin >> t;
	cnt();
	for (int i = 0; i < t; i++) {
		cin >> k;
		cin >> n;
		ppl[i] = apart[k][n];
	}

	for (int i = 0; i < t; i++) {
		cout << ppl[i] << endl;
	}

	return 0;
}

void cnt() {
	for (int i = 1; i < 15; i++) {
		apart[0][i] = i;
		apart[i][1] = 1;
	}
	for (int i = 1; i < 15; i++) {
		for (int j = 2; j < 15; j++) {
			apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
		}
	}
}