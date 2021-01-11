//BaekJoon_11005
//���� ��ȯ 2
/*
* ���� �ð� : 1s
* ���� ���� : 52.394%
*/

#include <iostream>
using namespace std;

int main() {
	char number[50];
	long long n;
	int b, len = 0;
	scanf("%lld %d", &n, &b);

	int mod = 0;
	for (len = 0; n > 0; len++) {
		mod = n%b;
		if (mod >= 10) mod += 55;
		else mod += 48;
		number[len] = mod;
		n /= b;
	}
	len--;
	for (; len >= 0; len--) {
		printf("%c", number[len]);
	}
	printf("\n");

	return 0;
}