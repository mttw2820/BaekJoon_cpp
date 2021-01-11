#include <iostream>
using namespace std;

int tri[1010][1010];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	if (k == n || k == 0) {
		cout << "1" << endl;
		return 0;
	}

	for (int i = 0; i <= n; i++) {
		tri[i][0] = 1;
		tri[i][i] = 1;
		for (int j = 1; j < i; j++) {
			tri[i][j] = (tri[i - 1][j - 1] + tri[i - 1][j]) % 10007;
		}
	}
	int ans = tri[n][k];
	cout << ans << endl;

	return 0;
}