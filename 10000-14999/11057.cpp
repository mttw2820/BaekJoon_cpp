#include <iostream>
using namespace std;

// 오르막 수
int uNum[1001][11];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++) uNum[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				uNum[i][j] += uNum[i - 1][k];
				uNum[i][j] %= 10007;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += uNum[n][i];
		ans %= 10007;
	}
	cout << ans << endl;
	return 0;
}