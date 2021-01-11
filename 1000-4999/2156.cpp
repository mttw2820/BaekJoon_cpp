//BaekJoon_2156
//포도주 시식
/*
* 제한 시간 : 2s
* 정답 비율 : 34.440%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int dp[10001] = { 0, };
int drink[10001] = { 0, };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &drink[i]);

	dp[0] = 0;
	dp[1] = drink[1];
	dp[2] = drink[1] + drink[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (dp[i] < dp[i - 2] + drink[i])
			dp[i] = dp[i - 2] + drink[i];
		if (dp[i] < dp[i - 3] + drink[i - 1] + drink[i])
			dp[i] = dp[i - 3] + drink[i - 1] + drink[i];
	}
	cout << dp[n] << endl;

	return 0;
}