//BaekJoon_1735
//분수 합
/*
* 제한 시간 : 2s
* 정답 비율 : 45.747%
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}
int main() {
	int as, am, bs, bm;
	int s, m;
	scanf("%d %d %d %d", &as, &am, &bs, &bm);
	m = am*bm;
	s = as*bm + bs*am;
	int g = gcd(s, m);
	m /= g;
	s /= g;
	printf("%d %d\n", s, m);

	return 0;
}