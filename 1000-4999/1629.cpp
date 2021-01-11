//BaekJoon_1629
//°ö¼À
/*
* Á¦ÇÑ ½Ã°£ : 2s
* Á¤´ä ºñÀ² : 25.761%
*/

// solution in 2020.07.12
#include <iostream>
using namespace std;

long long calc(long long a, long long b, long long c) {
	if (b == 0) return 1;
	else if (b == 1) return a % c;
	else if (b % 2 == 0) {
		long long temp = calc(a, b / 2, c) % c;
		return (temp * temp) % c;
	}
	else {
		return (a % c) * (calc(a, b - 1, c) % c);
	}
}
int main() {
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	long long ans = calc(a, b, c) % c;
	printf("%lld\n", ans);
	return 0;
}

/*
 * prev solution
#include <iostream>
using namespace std;

long long calc(long long x, long long y, long long z) {
	if (y == 0) return 1;
	if (y == 1) return x;
	if (y % 2 == 1)
		return calc(x, y - 1, z) * x % z;
	else {
		long long temp = calc(x, y / 2, z);
		return temp*temp%z;
	}
}
int main() {
	long long a, b, c;
	scanf("%lld %lld %lld", &a, &b, &c);
	cout << calc(a, b, c) % c << endl;

	return 0;
}
*/