//BaekJoon_1722
//순열의 순서
/*
* 제한 시간 : 2s
* 정답 비율 : 30.611%
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int perm[22] = { 0, };
bool check_num[22] = { false, };

int find_small(int n, int cnt) {
	for (int i = 1; i <= n; i++) {
		if (!check_num[i]) {
			if (cnt == 0) return i;
			cnt--;
		}
	}
}
int find_pos(int pos) {
	// pos 보다 작은 숫자
	int cnt = 0;
	for (int i = 1; i <= pos; i++) {
		if (!check_num[i]) {
			cnt++;
		}
	}
	return cnt;
}
void make_perm(long long perm_num, int n) {
	for (int i = n; i > 0; i--) {
		long long punc = 1;
		for (long long j = 1; j < i; j++) punc *= j;
		for (long long k = i - 1; k >= 0; k--) {
			if (perm_num >= punc * k) {
				perm_num -= punc*k;
				perm[i] = find_small(n, k);
				check_num[perm[i]] = true;
				break;
			}
		}
	}
}
void print_perm(int n) {
	for (int i = n; i > 0; i--)
		printf("%d ", perm[i]);
	printf("\n");
}
long long cnt_perm(int n) {
	long long cnt = 0;
	for (int i = n; i > 0; i--) {
		long long punc = 1;
		for (long long j = 1; j < i; j++) punc *= j;
		int num = find_pos(perm[i]);
		check_num[perm[i]] = true;
		cnt += (num - 1) * punc;
	}
	return cnt + 1;
}
int main() {
	int n, prob_num;
	scanf("%d %d", &n, &prob_num);
	if (prob_num == 1) {
		long long perm_num;
		scanf("%lld", &perm_num);
		make_perm(perm_num-1, n);
		print_perm(n);
	}
	else {
		for (int i = n; i > 0; i--) {
			scanf("%d", &perm[i]);
		}
		printf("%lld\n", cnt_perm(n));
	}
	return 0;
}