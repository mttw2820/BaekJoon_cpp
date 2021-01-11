//BaekJoon_9613
//GCD 합
/*
* 제한 시간 : 1s
* 정답 비율 : 36.401%
*/

#include <iostream>
using namespace std;

int num[110] = { 0, };

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	int testcase;
	scanf("%d", &testcase);
	
	while (testcase--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}

		long long total_gcd = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				total_gcd += gcd(num[i], num[j]);
			}
		}

		printf("%lld\n", total_gcd);
	}

	return 0;
}