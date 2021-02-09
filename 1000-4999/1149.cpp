//BaekJoon_1149
//RGB
/*
* 제한 시간 : 0.5s
* 정답 비율 : 48.007%
*/

#include <iostream>
using namespace std;
int n, c[3][1000] = { 0, };
int m = 1000000;

void color(int nei, int now, int cost) {
	if (now == n) {
		if (cost < m) m = cost;
	}
	else {
		int a = 0, b = 1000;
		for (int i = 0; i < 3; i++) {
			if (i == nei) continue;
			if (c[i][now] < b) {
				b = c[i][now];
				a = i;
			}
		}
		color(a, now + 1, cost + b);
	}
}
int main() {
	
	cin >> n;

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 3; i++)
			cin >> c[i][j];
	}

	color(-1, 0, 0);
	cout << m << endl;
	

	return 0;
}