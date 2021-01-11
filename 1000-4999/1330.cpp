//BaekJoon_1330
//두 수 비교하기
/*
* 제한 시간 : 1s
* 정답 비율 : 66.451%
*/

#include <iostream>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	if (a > b) printf(">\n");
	else if (a < b) printf("<\n");
	else printf("==\n");

	return 0;
}