//BaekJoon_10973
//
/*
* 제한 시간 : 1s
* 정답 비율 : 66.382%
*/

#include <iostream>
using namespace std;

int perm[10010] = { 0, };

void swap_perm(int index1, int index2) {
	int temp = perm[index1];
	perm[index1] = perm[index2];
	perm[index2] = temp;
}

bool prev_perm(int n) {
	int prev_s = -1, prev_e = -1;
	for (int i = n - 2; i >= 0; i--) {
		if (perm[i] > perm[i + 1]) {
			prev_s = i;
			break;
		}
	}
	if (prev_s == -1) return false;
	for (int i = n - 1; i > prev_s; i--) {
		if (perm[i] < perm[prev_s]) {
			prev_e = i;
			break;
		}
	}
	if (prev_e == -1) return false;
	
	swap_perm(prev_s, prev_e);
	for (int i = 0; i < (n - prev_s) / 2; i++) {
		swap_perm(prev_s + i + 1, n - i - 1);
	}
	return true;
}

void print_perm(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", perm[i]);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &perm[i]);
	}

	if (!prev_perm(n))
		printf("-1\n");
	else print_perm(n);

	return 0;
}