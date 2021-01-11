#include <iostream>
#include <algorithm>
using namespace std;

long long t[100001] = { 0, };
int main() {
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> t[i];
	}
	sort(t, t + n);
	long long left = 0;
	long long right = t[n-1] * m;
	long long ans = right;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long ppl = 0;
		for (int i = 0; i < n; i++) {
			ppl += (mid / t[i]);
		}

		if (ppl < m) {
			left = mid + 1;
		}
		else {
			if (ans > mid) ans = mid;
			right = mid - 1;
		}
		
	}
	cout << ans << endl;
	return 0;
}