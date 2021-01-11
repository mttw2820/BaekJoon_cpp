//BaekJoon_1182
//부분수열의 합
/*
* 제한 시간 : 2s
* 정답 비율 : 44.397%
*/

#include <iostream>
#include <bitset>
using namespace std;

int cnt = 0;
void make_sum(int goal, int num_s, int pos, int sum, int number[]) {
	if (pos == num_s) {
		if (sum == goal) cnt++;
		return;
	}
	make_sum(goal, num_s, pos + 1, sum + number[pos], number);
	make_sum(goal, num_s, pos + 1, sum, number);

	return;
}
int main() {
	int n, s;
	int number[25] = { 0, };
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}

	make_sum(s, n, 0, 0, number);
	if (s == 0) cnt--;
	printf("%d\n", cnt);

	return 0;
}