//BaekJoon_1138
//한 줄로 서기
/*
* 제한 시간 : 2s
* 정답 비율 : 56.756%
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

int n;
int count_upper[15] = { 0, };

void lineup(int start) {
	int cnt = 0;

	int now = start;
	while (cnt < n) {
		printf("%d ", now); cnt++;
		count_upper[now] = -1;

		bool flag = true;
		int next = 0;
		for (int i = 1; i < now; i++) {
			if (count_upper[i] == 0 && flag) {
				next = i;
				flag = false;
			}
			else if (count_upper[i] > 0) {
				count_upper[i]--;
				if (count_upper[i] == 0 && flag) {
					next = i;
					flag = false;
				}
			}
		}
		if (flag) {
			for (int i = now + 1; i <= n; i++) {
				if (count_upper[i] == 0) {
					next = i;
					break;
				}
			}
		}
		now = next;
	}

	printf("\n");
	return;
}

int main() {
	int check_left = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &count_upper[i]);
		if (count_upper[i] == 0 && check_left == 0)
			check_left = i;
	}

	lineup(check_left);

	return 0;
}
