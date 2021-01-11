//BaekJoon_1212
//8진수 2진수
/*
* 제한 시간 : 1s
* 정답 비율 : 31.776%
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string twos = "", eights;
	cin >> eights;
	int len = eights.length() - 1;
	if (len == 0 && eights[0] == '0') twos += '0';
	for (; len >= 0;len--) {
		int n = eights[len] - '0';
		for (int i = 0; i < 3; i++) {
			if (n == 0) {
				if (len == 0) break;
				twos += '0';
			}
			else {
				twos += (n % 2 + '0');
				n /= 2;
			}
		}
	}
	reverse(twos.begin(), twos.end());
	cout << twos << "\n";
	return 0;
}