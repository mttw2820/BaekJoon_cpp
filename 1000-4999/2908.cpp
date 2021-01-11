//BaekJoon_2908
//상수
/*
* 제한 시간 : 1s
* 정답 비율 : 69.180%
*/

#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int s_x = 0, s_y = 0;
	
	for (int i = 1, j=100; i <1000;) {
		s_x += (x / j * i);
		s_y += (y / j * i);
		x %= j; y %= j;
		i *= 10; j /= 10;
	}
	int result = (s_x > s_y) ? s_x : s_y;
	cout << result << endl;
	return 0;
}