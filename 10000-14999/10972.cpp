//BaekJoon_10972
//다음 순열
/*
* 제한 시간 : 1s
* 정답 비율 : 44.502%
*/

#include <iostream>
using namespace std;

int perm[10010] = { 0, };
void print_perm(int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", perm[i]);
	}
	printf("\n");
}

void swap_perm(int index1, int index2){
	int temp = perm[index1];
	perm[index1] = perm[index2];
	perm[index2] = temp;
}

bool next_perm(int n) {
	int n_start = -1, n_end = -1;
	for (int i = n - 2; i >= 0; i--) {
		if (perm[i] < perm[i + 1]) {
			n_start = i;
			break;
		}
	}
	if (n_start == -1) return false;
	for (int j = n - 1; j > n_start; j--) {
		if (perm[j] > perm[n_start]) {
			n_end = j;
			break;
		}
	}
	if (n_end == -1) return false;

	// swap
	swap_perm(n_start, n_end);

	// swap from end
	for (int i = 0; i<(n - n_start)/2; i++) {
		swap_perm(n_start + i + 1, n - i - 1);
	}
	return true;
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &perm[i]);
	if (!next_perm(n)) printf("-1\n");
	else print_perm(n);

	return 0;
}