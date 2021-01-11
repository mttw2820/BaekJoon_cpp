//BaekJoon_10974
//모든 순열
/*
* 제한 시간 : 1s
* 정답 비율 : 58.563%
*/

#include <iostream>
using namespace std;

int perm[10] = { 0, };

void swap_perm(int x, int y) {
	int temp = perm[x];
	perm[x] = perm[y];
	perm[y] = temp;
}
bool next_perm(int n) {
	int ns = -1, ne = -1;
	for (int i = n - 2; i >= 0; i--) {
		if (perm[i] < perm[i + 1]) {
			ns = i;
			break;
		}
	}
	if (ns == -1) return false;
	for (int i = n - 1; i > ns; i--) {
		if (perm[i] > perm[ns]) {
			ne = i;
			break;
		}
	}
	if (ne == -1) return false;

	swap_perm(ns, ne);
	for (int i = 0; i < (n - ns) / 2; i++) {
		swap_perm(ns + i + 1, n - i - 1);
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
		perm[i] = i + 1;
	}

	do {
		print_perm(n);
	} while (next_perm(n));

	return 0;
}