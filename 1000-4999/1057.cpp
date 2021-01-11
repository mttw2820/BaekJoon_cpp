//BaekJoon_1057
//토너먼트
/*
* 제한 시간 : 1s
* 정답 비율 : 55.277%
*/

#include <iostream>
using namespace std;

int go_next_round(int now) {
	if (now % 2 == 0) return now / 2;
	else return now / 2 + 1;
}

bool next_to(int x, int y) {
	if (x > y) {
		//swap
		int temp = x;
		x = y; y = temp;
	}
	if (x % 2 == 1 && y - x == 1) return true;
	else return false;
}
int main() {
	int n;
	int kim, lim;
	cin >> n >> kim >> lim;

	int round = 1;
	int flag = 0; // flag = 1이면 중간에 break;
	while (n >= 2) {
		if (next_to(kim, lim)) {
			flag = 1;
			break;
		}
		kim = go_next_round(kim);
		lim = go_next_round(lim);
		round++;
	}
	if (flag == 0) cout << -1 << endl;
	else cout << round << endl;
	

	return 0;
}