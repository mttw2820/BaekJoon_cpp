//BaekJoon_11502
//세 개의 소수 문제
/*
* 제한 시간 : 1.5s
* 정답 비율 : 36.348%
*/

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
int prime[1001] = { 0 };
int sum[3];

void goldBach(int n);
int main(void) {
	int i, j;
	for (i = 2; i < 1000; i++) {
		for (j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) break;
		}
		if (i % j != 0) prime[i] = 1;
	}
	prime[2] = 1;   //�Ҽ�ã��

	int T, K;
	cin >> T;
	while (T--) {
		cin >> K;
		int next;
		for (int i = K - 1; i > 0; i--) {
			if (prime[i] == 1) {
				next = i;
				if ((K - next) >= 4) break;
			}
		}
		sum[0] = next;
		goldBach(K - next);
		sort(sum, sum + 3);
		for (int i = 0; i < 3; i++) {
			cout << sum[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

void goldBach(int n) {
	int i, j, mid = n / 2;
	for (i = j = mid; i <= n; i--, j++) {
		if (prime[i] && prime[j]) {
			sum[1] = i;
			sum[2] = j;
			return;
		}
	}
}