#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t[1001] = { 0, };
	int n, sum=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	sort(t, t + n);
	for (int i = 0; i < n; i++) {
		sum += (n-i)*t[i];
	}
	cout << sum << endl;
	return 0;
}