//BaekJoon_9465
//��ƼĿ
/*
* ���� �ð� : 1s
* ���� ���� : 47.863%
*/

#include <iostream>
using namespace std;
#include <algorithm>

int dp[3][100001];
int st[2][100001];
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) 
			scanf("%d", &st[0][i]);
		for (int i = 0; i < n; i++)
			scanf("%d", &st[1][i]);
		
		//dp[0] : ���� ��ƼĿ�� ������ ���
		//dp[1] : �Ʒ��� ��ƼĿ�� ������ ���
		//dp[2] : ���ʿ��� ��ƼĿ�� �ϳ��� ���� ���� ���
		dp[0][0] = st[0][0];
		dp[1][0] = st[1][0];
		dp[2][0] = 0;
		for (int i = 1; i < n; i++) {
			dp[2][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
			dp[1][i] = st[1][i] + max(dp[0][i - 1], dp[2][i - 1]);
			dp[0][i] = st[0][i] + max(dp[1][i - 1], dp[2][i - 1]);
		}
		int result = max(dp[0][n - 1], max(dp[1][n - 1], dp[2][n - 1]));
		printf("%d\n", result);
	}

	return 0;
}