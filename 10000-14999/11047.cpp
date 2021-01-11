#include <iostream>
using namespace std;

int main() {
	int n, k, cnt = 0;
	int coins[11] = { 0, };
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		while (k - coins[i] >= 0) {
			k -= coins[i];
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}