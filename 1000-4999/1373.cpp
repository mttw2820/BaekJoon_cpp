//BaekJoon_1373
//2진수 8진수
/*
* 제한 시간 : 1s
* 정답 비율 : 38.118%
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string twos, eights = "";
	cin >> twos;
	int len = twos.length() - 1;
	for (; len >= 0;) {
		int temp = 0;
		for (int i = 1; i <= 4; i *= 2) {
			if (len < 0) break;
			temp += (twos[len--]-'0') * i;
		}
		eights += temp + '0';
	}

	reverse(eights.begin(), eights.end());
	cout << eights << "\n";


	return 0;
}