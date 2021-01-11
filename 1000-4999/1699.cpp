//BaekJoon_1699
//�������� ��
/*
* ���� �ð� : 2s
* ���� ���� : 41.054%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	int dp[100001] = { 0, };
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j*j <= i; j++) {
			//���� ��ġ���� �������� ���� ��츦 �����غ���.
			if ((dp[i] > dp[i - j*j] + 1) || (dp[i] == 0))
				dp[i] = dp[i - j*j] + 1;
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}