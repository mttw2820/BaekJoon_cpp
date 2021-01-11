//BaekJoon_1699
//제곱수의 합
/*
* 제한 시간 : 2s
* 정답 비율 : 41.054%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	int dp[100001] = { 0, };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			//현재 위치에서 제곱수를 뺐을 경우를 생각해본다.
			if ((dp[i] > dp[i - j*j] + 1) || (dp[i] == 0))
				dp[i] = dp[i - j*j] + 1;
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}