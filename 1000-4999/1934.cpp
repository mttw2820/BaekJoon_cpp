//BaekJoon_1934
//최소공배수
/*
* 제한 시간 : 1s
* 정답 비율 : 59.245%
*/

#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	int testcase, a, b, g, ans = 0;
	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%d %d", &a, &b);
		g = gcd(a, b);
		ans = a*b / g;
		cout << ans << "\n";
	}

	return 0;
}