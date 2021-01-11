//BaekJoon_2884
//알람 시계
/*
* 제한 시간 : 1s
* 정답 비율 : 51.648%
*/

#include <iostream>
using namespace std;

int main() {
	int h, m;
	scanf("%d %d", &h, &m);
	if (m < 45) {
		h--;
		m = 60 - (45 - m);
	}
	else m -= 45;
	if (h < 0) h += 24;

	printf("%d %d\n", h, m);

	return 0;
}