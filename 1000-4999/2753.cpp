//BaekJoon_2753
//윤년
/*
* 제한 시간 : 1s
* 정답 비율 : 64.075%
*/

#include <iostream>
using namespace std;

int main() {
	int y;
	scanf("%d", &y);

	if (y % 400 == 0) printf("1\n");
	else if (y % 4 == 0 && y % 100 != 0) printf("1\n");
	else printf("0\n");

	return 0;
}