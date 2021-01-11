//BaekJoon_11812
//K진 트리
/*
* 제한 시간 : 1s
* 정답 비율 : 25.108%
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long N;
int K, Q;


int main() {
	scanf("%lld %d %d", &N, &K, &Q);

	long long x, y;
	for (int i = 0; i < Q; i++) {
		scanf("%lld %lld", &x, &y);
		if (K == 1) {
			printf("%lld\n", abs(x - y));
			continue;
		}

		long long dist = 0;
		while (x != y) {
			long long m = max(x, y);
			y = min(x, y);
			x = (m - 2) / K + 1;
			dist++;
		}

		printf("%lld\n", dist);
	}

	return 0;
}