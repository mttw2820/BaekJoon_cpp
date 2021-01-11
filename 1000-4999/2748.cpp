//BaekJoon_2748
//피보나치 수 2
/*
* 제한 시간 : 1s
* 정답 비율 : 39.646%
*/

#include <iostream>
using namespace std;

long long fibo[100] = { 0, };
int main() {
	int n;
	fibo[1] = fibo[2] = 1;
	cin >> n;
	for (int i = 3; i <= n; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	cout << fibo[n] << endl;
	return 0;
}