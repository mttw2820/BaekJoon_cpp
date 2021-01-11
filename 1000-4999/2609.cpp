//BaekJoon_2609
//최대공약수와 최소공배수
/*
* 제한 시간 : 1s
* 정답 비율 : 64.023%
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int a, b;
	long long g, l;
	scanf("%d %d", &a, &b);
	g = gcd(a, b);
 	l = (a*b) / g;

	printf("%lld\n%lld\n", g, l);

	return 0;
}