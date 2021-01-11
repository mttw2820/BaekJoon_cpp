//BaekJoon_11653
//소인수분해
/*
* 제한 시간 : 1s
* 정답 비율 : 53.894%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 2; i*i <= n; i++) {
		while (n % i == 0) {
			printf("%d\n", i);
			n /= i;
		}
	}
	if (n > 1) printf("%d\n", n);

	return 0;
}