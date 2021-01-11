//BaekJoon_1010
//다리 놓기
/*
* 제한 시간 : 2s
* 정답 비율 : 47.505%
*/

#include <iostream>
#include <string.h>
using namespace std;

long long conn[32][32] = { 0, };
int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			conn[0][i] = 1;
		}
		for (int i = 1; i < n; i++) {
			for (int j = i; j < m - n + i + 1; j++) {
				conn[i][j] = 0;
				for (int k = i-1; k < j; k++) {
					conn[i][j] += conn[i - 1][k];
				}
			}
		}
		long long sum = 0;
		for (int i = 0; i < m; i++) 
			sum += conn[n - 1][i];
		printf("%lld\n", sum);
	}

	return 0;
}