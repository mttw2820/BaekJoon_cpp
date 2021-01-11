//BaekJoon_9625
//BABBA
/*
* 제한 시간 : 1s
* 정답 비율 : 64.882%
*/

#include <iostream>
using namespace std;

int main() {
	// 이전 A -> B, B -> BA
	int a = 1, b = 0;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp = a;
		a = b;
		b = b + temp;
	}
	cout << a << " " << b << endl;

	return 0;
}