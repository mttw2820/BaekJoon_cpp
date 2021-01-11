//BaekJoon_11050
//이항 계수 1
/*
* 제한 시간 : 1s
* 정답 비율 : 65.140%
*/

#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int up = 1, down = 1;
	for (int i = 1; i <= k; i++) {
		up *= (n - i + 1);
		down *= i;
	}
	cout << up / down << endl;

	return 0;
}