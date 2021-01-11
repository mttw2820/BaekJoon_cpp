//BaekJoon_1149
//RGB거리
/*
* 제한 시간 : 0.5s
* 정답 비율 : 46.582%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int dp[1001][4] = { 0, };
int cost[1001][4] = { 0, };	//색칠하는 비용 R:[][0], G: [][1], B: [][2]
int main() {
	int n, result = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	result = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	printf("%d\n", result);

	return 0;
}