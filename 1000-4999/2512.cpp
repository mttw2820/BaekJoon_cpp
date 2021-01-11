#include <iostream>
#include <algorithm>
using namespace std;

int money[10001] = { 0, };
int main() {
	int n; long long m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> money[i];
	}
	cin >> m;
	sort(money, money + n);

	long long mx = 0;
	long long left = 0;
	long long right = money[n-1];

	while (left <= right) {
		long long total = 0;
		long long mid = (left + right) / 2;
		for (int mn : money) {
			if (mn < mid) total += mn;
			else total += mid;
		}

		if (total > m) {
			right = mid - 1;
		}
		else {
			if (mx < mid) mx = mid;
			left = mid + 1;
		}
	}
	cout << mx << endl;
	return 0;
}