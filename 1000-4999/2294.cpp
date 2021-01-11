//BaekJoon_2294
//���� 2
/*
* ���� �ð� : 2s
* ���� ���� : 27.366%
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

vector<int> coins;
int dp[100010] = { 0, };
int main() {
	memset(dp, -1, sizeof(dp));
	int n, k, temp;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		coins.push_back(temp);
	}
	sort(coins.begin(), coins.end());

	dp[0] = 0;
	//ũ�Ⱑ ���� �������� �ϳ��� ��� ������ ���� ����.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - coins[i] >= 0) {
				if (dp[j - coins[i]] != -1) {
					if (dp[j] == -1)
						dp[j] = dp[j - coins[i]] + 1;
					else
						dp[j] = min(dp[j], dp[j - coins[i]] + 1);
				}
			}
		}
	}

	printf("%d\n", dp[k]);

	return 0;
}