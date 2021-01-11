//BaekJoon_10950
//A+B - 3
/*
* 제한 시간 : 1s
* 정답 비율 : 60.484%
*/

#include <iostream>
using namespace std;

int main() {
	int testcase = 0;
	cin >> testcase;

	while (testcase != 0) {
		int a, b;
		cin >> a >> b;
		cout << a + b << endl;
		testcase--;
	}


	return 0;
}