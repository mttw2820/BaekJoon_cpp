//BaekJoon_14501
//퇴사
/*
* 제한 시간 : 2s
* 정답 비율 : 46.533%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int k, x, y;
	vector<pair<int, int>> schedule;
	//dp[i].first = i번째날 상담을 포함하는, 최대의 금액
	//dp[i].second = i번째날 상담을 포함하지 않는, 최대의 금액
	vector<pair<int, int>> dp;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &x, &y);
		schedule.push_back(make_pair(x, y));
		dp.push_back({ 0,0 });
	}
	for (int i = k - 1; i >= 0; i--) {
		int index = 0;
		index = i + schedule[i].first;
		if (i + schedule[i].first < k) {
			dp[i].first = max(dp[index].first, dp[index].second);
		}
		else if (index - 1 < k) {
			dp[i].first = max(dp[i].first, dp[index - 1].second);
		}
		else dp[i].first = -1;
		if (dp[i].first >= 0) dp[i].first += schedule[i].second;

		if (i + 1 < k) {
			dp[i].second = max(dp[i + 1].first, dp[i + 1].second);
		}
		else dp[i].second = 0;
	}
	int result = 0;
	for (int i = 0; i < k; i++) {
		result = max(result, max(dp[i].first, dp[i].second));
	}

	printf("%d\n", result);
	return 0;
}