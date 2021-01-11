//BaekJoon_2089
//-2진수
/*
* 제한 시간 : 2s
* 정답 비율 : 46.127%
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	long long n;
	stack<int> ans;
	scanf("%lld", &n);

	if (n == 0) ans.push(0);
	while (n != 0) {
		if (n < 0 && n % 2 == -1) {
			n = n / -2 + 1;
			ans.push(1);
		}
		else {
			ans.push(n%-2);
			n /= -2;
		}
	}

	while (!ans.empty()) {
		printf("%d", ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}