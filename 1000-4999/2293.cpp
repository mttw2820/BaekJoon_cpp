//BaekJoon_2293
//���� 1
/*
* ���� �ð� : 2s
* ���� ���� : 41.811%
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
	//������ �ٸ� ��찡 �ߺ��ؼ� �������� �ʵ���
	//coins�� ������ �÷����鼭 ������ Ȯ���Ѵ�.
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