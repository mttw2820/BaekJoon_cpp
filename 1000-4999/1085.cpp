//BaekJoon_1085
//직사각형에서 탈출
/*
* 제한 시간 : 2s
* 정답 비율 : 56.887%
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	int len = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	len = x;
	len = min(len, min(y, min(w - x, h - y)));
	printf("%d\n", len);

	return 0;
}