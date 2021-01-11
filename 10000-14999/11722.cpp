//BaekJoon_11722
//���� �� �����ϴ� �κ� ����
/*
* ���� �ð� : 1s
* ���� ���� : 64.720%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[1001] = { 0, };
int dp[1001] = { 0, };	//dp[i] = a[i]�� �����ϴ� �����ϴ� ������ �ִ� ����

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int min = -1;
		for (int j = 0; j < i; j++) {
			if (a[i] < a[j]) {
				if (min == -1)
					min = j;
				else if (dp[min] < dp[j])
					min = j;
			}
		}
		if (min == -1) dp[i] = 1;
		else dp[i] = dp[min] + 1;
	}
	sort(dp, dp + n);
	cout << dp[n - 1] << endl;

	return 0;
}