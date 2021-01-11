//BaekJoon_2293
//동전 1
/*
* 제한 시간 : 2s
* 정답 비율 : 41.811%
*/

#include <iostream>
#include <algorithm>
#include <algorithm>
using namespace std;

int coins[100];
long long dp[10001] = { 0, };
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coins[i]);
	sort(coins, coins + n);
	dp[0] = 1;
	//순서가 다른 경우가 중복해서 더해지지 않도록
	//coins의 범위를 늘려가면서 갯수를 확인한다.
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coins[i]) {
				if (dp[j - coins[i]] != 0) {
					dp[j] += dp[j - coins[i]];
				}
			}
		}
	}

	printf("%lld\n", dp[k]);
	return 0;
}