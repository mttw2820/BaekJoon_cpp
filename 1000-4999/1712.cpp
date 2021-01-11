//BaekJoon_1712
//손익분기점
/*
* 제한 시간 : 0.35s
* 정답 비율 : 28.744%
*/

#include <iostream>
using namespace std;

int main() {
	long long a, b, c;
	long long breakP = 0;
	scanf("%lld %lld %lld", &a, &b, &c);
	if (c - b <= 0) {
		printf("-1\n");
		return 0;
	}
	breakP = a / (c - b);
	while (breakP*(c - b) <= a) breakP++;
	printf("%lld\n", breakP);
	return 0;
}