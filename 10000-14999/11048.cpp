#include <iostream>
using namespace std;
#include <algorithm>

int room[1001][1001];
int candy[1001][1001];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> room[i][j];
			candy[i][j] = room[i][j];
		}
	}

	for (int i = 2; i <= m; i++)
		candy[1][i] += candy[1][i - 1];
	for (int j = 2; j <= n; j++)
		candy[j][1] += candy[j - 1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			int prev_max = max(candy[i - 1][j - 1], candy[i - 1][j]);
			candy[i][j] += max(prev_max, candy[i][j - 1]);
		}
	}
	cout << candy[n][m] << endl;

	return 0;
}