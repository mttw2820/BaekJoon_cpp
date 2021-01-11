
#include <iostream>
using namespace std;

long long cnt[95][2] = { 0,0 };

int main() {
	int n;
	cin >> n;

	cnt[0][0] = 0;
	cnt[0][1] = 1;
	for (int i = 0; i < n; i++) {
		cnt[i + 1][1] = cnt[i][0];
		cnt[i + 1][0] = cnt[i][0] + cnt[i][1];
	}

	long long result = cnt[n - 1][0] + cnt[n - 1][1];
	cout << result << endl;

	return 0;
}