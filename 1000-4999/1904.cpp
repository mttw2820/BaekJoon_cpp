//BaekJoon_1904
//01타일
/*
* 제한 시간 : 2s
* 정답 비율 : 46.336%
*/

#include <iostream>
using namespace std;

int dp[1000001] = { 0, };
int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 0; dp[1] = 1; dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	printf("%d\n", dp[n]);

	return 0;
}