//BaekJoon_10952
//A+B - 5
/*
* 제한 시간 : 1s
* 정답 비율 : 56.192%
*/

#include <iostream>
using namespace std;

int main() {
	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0) break;
		cout << a + b << endl;
	}

	return 0;
}