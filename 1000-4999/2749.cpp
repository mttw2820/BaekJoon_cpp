//BaekJoon_2749
//탑
/*
* 제한 시간 : 1s
* 정답 비율 : 37.640%
*/

#include <iostream>
using namespace std;

long long fibo[1500010] = { 0, };
int main() {
	long long n;
	long long num = 1000000;
	long long cycle = num / 10 * 15;
	scanf("%lld", &n);
	n %= cycle;
	
	fibo[0] = 0, fibo[1] = 1;
	for (int i = 2; i <= n; i++)
		fibo[i] = (fibo[i - 2] + fibo[i - 1]) % num;

	printf("%lld\n", fibo[n] % num);
	return 0;
}