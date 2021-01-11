//BaekJoon_11055
//���� ū ���� �κ� ����
/*
* ���� �ð� : 1s
* ���� ���� : 47.075%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[1001] = { 0, };
int dp[1001] = { 0, };	//dp[i] = a[i]�� �����ϴ� ���� ū ���� �κ� ������ ��
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	dp[0] = a[0];
	for (int i = 1; i < n; i++) {
		int max = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {	//���� ����
				if (max == -1)
					max = j;
				else if (dp[max] < dp[j])	//���� �ִ� ����
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