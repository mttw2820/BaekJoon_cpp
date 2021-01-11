//BaekJoon_2292
//벌집
/*
* 제한 시간 : 2s
* 정답 비율 : 46.466%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int lineNum = 1;
	int cnt = 1;

	if (n > 1) {
		n--;
		cnt++;
		lineNum += 5;
	}
	for (int i = 0;; i++) {
		if (lineNum >= n) break;
		n -= lineNum;
		lineNum += 6;
		cnt++;
	}
	cout << cnt << endl;

	return 0;
}