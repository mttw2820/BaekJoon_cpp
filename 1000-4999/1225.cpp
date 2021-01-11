//BaekJoon_1225
//이상한 곱셈
/*
* 제한 시간 : 2s
* 정답 비율 : 37.754%
*/

#include <iostream>
using namespace std;

int main() {
	char a[10001], b[10001];
	long long sum = 0;
	int x, y;
	scanf("%s %s", a, b);

	for (int i = 0; a[i]; i++) {
		x = a[i] - '0';
		for (int j = 0; b[j]; j++) {
			y = b[j] - '0';
			sum += (x*y);
		}
	}
	printf("%lld\n", sum);
	
	return 0;
}