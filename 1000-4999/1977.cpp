//BaekJoon_1977
//완전제곱수
/*
* 제한 시간 : 2s
* 정답 비율 : 45.606%
*/

#include <iostream>
using namespace std;

int main() {
	int m, n;
	int minSq = 0, sq = 0;
	long long sum = 0;

	cin >> m >> n;
	for (int i = 1; i <= 100; i++) {
		sq = i*i;
		if (m <= sq && sq <= n) {
			if (minSq == 0) minSq = sq;
			sum += sq;
		}
	}
	if (sum == 0) cout << -1 << endl;
	else cout << sum << endl << minSq << endl;
	return 0;
}