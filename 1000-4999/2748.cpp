//BaekJoon_2748
//�Ǻ���ġ �� 2
/*
* ���� �ð� : 1s
* ���� ���� : 39.646%
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