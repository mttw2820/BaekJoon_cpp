#include <iostream>
using namespace std;
#include <algorithm>

int n;
int stairs[301] = { 0, };
int point[301][2];

int main() {
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}
	
	point[1][0] = stairs[1];
	point[2][0] = stairs[2];

	for (int i = 2; i <= n; i++) {
		point[i][1] = point[i - 1][0] + stairs[i];
		point[i][0] = max(point[i - 2][0], point[i - 2][1]) + stairs[i];
	}
	cout << max(point[n][0], point[n][1]) << endl;
	return 0;
}
