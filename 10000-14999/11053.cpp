//BaekJoon_11053
//가장 긴 증가하는 부분 수열
/*
* 제한 시간 : 1s
* 정답 비율 : 36.956%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[1001] = { 0, };
int dp[1001] = { 0, };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int max = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				if (max == -1)
					max = j;
				else if (dp[max] < dp[j]) 
					max = j;
			}
			if (max == -1) dp[i] = 1;
			else dp[i] = dp[max] + 1;
		}
	}
	sort(dp, dp + n);
	cout << dp[n - 1] << endl;
	return 0;
}