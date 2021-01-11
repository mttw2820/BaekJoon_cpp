//BaekJoon_15954
//인형들
/*
* 제한 시간 : 1s
* 정답 비율 : 18.737%
*/

#include <iostream>
#include <math.h>
using namespace std;

long double calc(int sp, int j, int doll[]) {
	long double sum = 0, sqsum = 0;
	long double m = 0, sqm = 0;
	for (int i = sp; i < sp + j; i++) {
		sum += doll[i];
	}
	m = (long double)sum / (long double)j;

	for (int i = sp; i < sp + j; i++) {
		sqsum += (long double)(doll[i] - m)*(long double)(doll[i] - m);
	}
	sqm = (long double)sqsum / (long double)j;

	long double dev = sqrt(sqm);
	return dev;
}

int main() {
	int n, k;
	long double ans = -1;
	int doll[501] = { 0, };
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &doll[i]);
	}

	for (int j = k; j <= n; j++) {
		for (int i = 0; i <= n - j; i++) {
			long double temp = calc(i, j, doll);
			if (ans < 0 || temp < ans) ans = temp;
		}
	}
	printf("%.11Lf\n", ans);
	return 0;
}