//BaekJoon_11055
//가장 큰 증가 부분 수열
/*
* 제한 시간 : 1s
* 정답 비율 : 47.075%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[1001] = { 0, };
int dp[1001] = { 0, };	//dp[i] = a[i]를 포함하는 가장 큰 증가 부분 수열의 합
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		int max = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {	//증가 조건
				if (max == -1)
					max = j;
				else if (dp[max] < dp[j])	//합의 최대 조건
					max = j;
			}
		}
		if (max == -1) dp[i] = a[i];
		else dp[i] = dp[max] + a[i];
	}
	sort(dp, dp + n);
	cout << dp[n - 1] << endl;
	return 0;
}