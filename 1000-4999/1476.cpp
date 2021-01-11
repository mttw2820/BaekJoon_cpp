//BaekJoon_1476
//날짜 계산
/*
* 제한 시간 : 2s
* 정답 비율 : 67.221%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int year = 0, max_num = 0;
	while (!(a == 0 && b == 0 && c == 0)) {
		max_num = max(a, max(b, c));
		a -= max_num;
		b -= max_num;
		c -= max_num;
		while (a < 0) a += 15;
		while (b < 0) b += 28;
		while (c < 0) c += 19;
		year += max_num;
	}
	cout << year << endl;
	return 0;
}