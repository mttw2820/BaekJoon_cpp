//BaekJoon_11399
//ATM
/*
* 제한 시간 : 1s
* 정답 비율 : 65.556%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, t = 0;
	cin >> n;
	int atm[1001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> atm[i];
	}
	sort(atm, atm+n);
	for (int i = 0; i < n; i++) {
		t += (atm[i] * (n - i));
	}
	cout << t << endl;
	return 0;
}