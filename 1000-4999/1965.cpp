//BaekJoon_1965
//���ڳֱ�
/*
* ���� �ð� : 2s
* ���� ���� : 46.189%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int box[1001] = { 0, };
int dp[1001] = { 1, };
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &box[i]);
	}
	for (int i = 1; i < n; i++) {
		int in_box = 1;
		for (int j = 0; j < i; j++) {
			if ((box[i] > box[j]) && (in_box < dp[j] + 1)) {
				in_box = dp[j] + 1;
			}
		}
		dp[i] = in_box;
	}
	sort(dp, dp + n);
	int result = dp[n - 1];
	cout << result << endl;
	return 0;
}