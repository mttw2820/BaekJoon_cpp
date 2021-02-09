//BaekJoon_9461
//파도반 수열
/*
* 제한 시간 : 1s
* 정답 비율 : 40.198%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int ts, t[101] = { 0, };
	long long p[101] = { 0, 1, 1, 1, 2, 2 };
	cin >> ts;
	for (int i = 6; i <= 100; i++)
		p[i] = p[i - 5] + p[i - 1];
	for (int i = 0; i < ts; i++) {
		cin >> t[i];
		cout << p[t[i]] << endl;
	}

	return 0;
}