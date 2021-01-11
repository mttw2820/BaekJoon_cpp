#include <iostream>
using namespace std;

int main() {
	int t, n, prev=4;
	int sum[20] = { 0, };
	sum[0] = 0; sum[1] = 1; sum[2] = 2; sum[3] = 4;
	cin >> t;
	while (true) {
		if (t <= 0) break;
		cin >> n;
		for (int i = prev; i <= n; i++) {
			sum[i] = sum[i - 1] + sum[i - 2] + sum[i - 3];
		}
		
		cout << sum[n]<<endl ;
		if (prev < n)prev = n;
		t--;
	}

	return 0;
}