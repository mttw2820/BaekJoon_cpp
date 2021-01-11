//BaekJoon_10989
//수 정렬하기 3
/*
* 제한 시간 : 3s
* 정답 비율 : 22.916%
*/

#include <iostream>
using namespace std;

int nums[10001] = { 0, };
int main() {
	int n, in = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in);
		nums[in]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (nums[i] != 0) {
			for (int j = 0; j < nums[i]; j++)
				printf("%d\n", i);
		}
	}
	return 0;
}