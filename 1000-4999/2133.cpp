//BaekJoon_2133
//타일 채우기
/*
* 제한 시간 : 2s
* 정답 비율 : 35.425%
*/

#include <iostream>
using namespace std;

long long dp[40] = { 0, };
int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		// n이 홀수일 때는 가능한 경우가 없다
		cout << 0 << endl;
		return 0;
	}
	dp[0] = 1;
	dp[1] = 3;
	for (int i = 2; i * 2 <= n; i++) {
		dp[i] = 2 + dp[i - 1] * 3;
		for (int j = i-2; j >=1; j--)
			dp[i] += dp[j] * 2;
	}
	cout << dp[n / 2] << endl;
	return 0;
}