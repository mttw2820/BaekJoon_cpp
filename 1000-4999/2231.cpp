// BaekJoon_2231
// 분해합
/*
* 제한 시간 : 2s
* 정답 비율 : 50.884%
*/

#include <iostream>
#include <math.h>
using namespace std;

int makeM(int digit, int n, int m);

int main() {
	int n;
	cin >> n;

	int digit = 1;
	while (digit < n) 
		digit *= 10;

	int m = makeM(digit/10, n, 0);
	if (m < 0) cout << 0 << endl;
	else cout << m << endl;
	return 0;
}

int makeM(int digit, int n, int m) {
	if (digit <= 0) {
		if (n == 0) return m;
		else return -1;
	}
	int ans = 0, new_n = 0, new_m = 0;
	for (int i = 0; i <= n/(digit+1) && i<10; i++) {
		new_n = n - (digit + 1)*i;
		new_m = m + i*digit;
		ans = makeM(digit / 10, new_n, new_m);
		if (ans > 0) return ans;
	}
	return -1;
}