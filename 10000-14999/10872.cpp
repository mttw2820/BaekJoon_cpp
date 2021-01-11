//BaekJoon_10872
//팩토리얼
/*
* 제한 시간 : 1s
* 정답 비율 : 50.511%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	long long fac = 1;
	for (int i = 1; i <= n; i++) {
		fac *= i;
	}
	cout << fac << "\n";
	return 0;
}