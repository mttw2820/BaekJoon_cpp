//BaekJoon_2961
//도영이가 만든 맛있는 음식
/*
* 제한 시간 : 1s
* 정답 비율 : 41.947%
*/

#include <iostream>
#include <math.h>
using namespace std;

long long best_taste = -1;
void cook(int pos, long long s, long long b, int size, int cnt, int taste[12][2]) {
	if (pos == size) {
		if (cnt == 0) return;
		long long total = abs(s - b);
		if (best_taste < 0 || best_taste > total) {
			best_taste = total;
		}
		return;
	}

	cook(pos + 1, s*taste[pos][0], b + taste[pos][1], size, cnt + 1, taste);
	cook(pos + 1, s, b, size, cnt, taste);
	return;
}
int main() {
	int n;
	int taste[12][2] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &taste[i][0], &taste[i][1]);
	}

	cook(0, 1, 0, n, 0, taste);
	printf("%lld\n", best_taste);

	return 0;
}