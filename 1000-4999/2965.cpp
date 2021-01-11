//BaekJoon_2965
//캥거루 세마리
/*
* 제한 시간 : 1s
* 정답 비율 : 67.775%
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b - a < c - b) {
		cout << c - b - 1 << endl;
	}
	else {
		cout << b - a - 1 << endl;
	}

	return 0;
}