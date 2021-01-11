//BaekJoon_1871
//좋은 자동차 번호판
/*
* 제한 시간 : 1s
* 정답 비율 : 65.651%
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase-- != 0) {
		int first = 0, second = 0;
		char input[50];
		scanf("%s", input);
		for (int i = 2, j = 1; i >= 0; i--) {
			first += (input[i] - 'A')*j;
			j *= 26;
		}
		for (int i = 7, j = 1; i >= 4; i--) {
			second += (input[i] - '0')*j;
			j *= 10;
		}
		if (abs(second - first) <100) {
			printf("nice\n");
		}
		else printf("not nice\n");
	}


	return 0;
}