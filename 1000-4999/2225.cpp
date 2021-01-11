//BaekJoon_2225
//합분해
/*
* 제한 시간 : 2s
* 정답 비율 : 42.071%
*/

#include <iostream>
using namespace std;

int dp[201][201] = { 0, }; // dp[i][j] = i개 숫자로 j만드는 경우의 수
int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		dp[1][i] = 1;
		dp[2][i] = i + 1;
	}

	for (int i = 3; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = 1;
			for (int k = 1; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 1000000000;
			}
		}
	}
	printf("%d\n", dp[k][n]);

	return 0;
}