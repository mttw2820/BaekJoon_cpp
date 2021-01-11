#include <iostream>
using namespace std;

int tri[501][501];
int main() {
	int n, temp;
	cin >> n;
	cin >> tri[0][0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> temp;
			if (j < i) tri[i][j] = tri[i - 1][j] + temp;
			else tri[i][j] = tri[i - 1][j-1] + temp;
			if (j > 0 && j < i && (tri[i - 1][j] < tri[i - 1][j - 1])) {
				tri[i][j] = tri[i - 1][j - 1] + temp;
			}
		}
	}
	int m=0;
	for (int i = 1; i < n; i++) {
		if (tri[n - 1][i] > tri[n - 1][m]) m = i;
	}
	cout << tri[n - 1][m] << endl;
	return 0;
}