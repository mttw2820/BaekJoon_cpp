//BaekJoon_15329
//Secret of Chocolate Poles
/*
* 제한 시간 : 1s
* 정답 비율 : 72.576%
*/

#include <iostream>
using namespace std;

int l, k;
long long white_end[101] = { 0, };
long long black_end[101] = { 0, };

int main() {
	scanf("%d %d", &l, &k);
	black_end[1] = 1;
	black_end[k] = 1;
	for (int i = 2; i <= l; i++) {
		if (black_end[i - 1] > 0)
			white_end[i] += black_end[i - 1];
		if (white_end[i - 1] > 0)
			black_end[i] += white_end[i-1];
		if (i - k > 0 && white_end[i-k]>0) {
			black_end[i] += white_end[i-k];
		}
	}

	long long sol = 0;
	for (int i = 1; i <= l; i++) {
		sol = sol += black_end[i];
	}
	printf("%ld\n", sol);
	return 0;
}