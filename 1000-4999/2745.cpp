//BaekJoon_2745
//진법 변환
/*
* 제한 시간 : 1s
* 정답 비율 : 56.892%
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string number = "";
	long long ans = 0;
	int b, len = 0;
	cin >> number >> b;
	
	len = number.length() - 1;
	int temp = 0;
	for (int bk = 1; len >= 0; len--) {
		if (number[len] >= 'A') temp = number[len] - 'A' + 10;
		else temp = number[len] - '0';
		ans += temp * bk;
		bk *= b;
	}
	printf("%lld\n", ans);
	return 0;
}