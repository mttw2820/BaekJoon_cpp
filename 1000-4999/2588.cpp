//BaekJoon_2588
//곱셈
/*
* 제한 시간 : 1s
* 정답 비율 : 71.552%
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int x, y, result = 0;
	scanf("%d %d", &x, &y);
	result = x*y;

	for (int i = 0; i < 3; i++) {
		printf("%d\n", x*(y % 10));
		y /= 10;
	}
	printf("%d\n", result);
	return 0;
}