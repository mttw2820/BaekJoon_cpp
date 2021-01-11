#include <iostream>
using namespace std;

int num[300][300];

int main() {
	int n, m, k;
	cin >> n >> m;

	//입력 받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num[i][j];
		}
	}

	cin >> k;

	while (k--) {
		int i, j, x, y, sum = 0;
		cin >> i >> j >> x >> y;

		for (int a = i-1; a < x; a++) {
			for (int b = j-1; b < y; b++) {
				sum += num[a][b];
			}
		}

		cout << sum << endl;
	}

	return 0;
}