#include <iostream>
#include <algorithm>
using namespace std;

long long n, m, h=0, cut = 0;
long long trees[1000001] = { 0, };

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
	}
	sort(trees, trees + n);
	long long left = 0;
	long long right = trees[n - 1];
	
	while (left<=right) {
		int mid = (left + right) / 2;
		cut = 0;
		for (int i = n - 1; trees[i] > mid; i--) {
			cut += (trees[i] - mid);
		}

		if (cut < m) { right = mid - 1; }
		else {	
			if (h < mid) h = mid;
			left = mid + 1;
		}
	}
	cout << h << endl;

	return 0;
}