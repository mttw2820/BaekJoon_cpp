//BaekJoon_1978
//소수 찾기
/*
* 제한 시간 : 2s
* 정답 비율 : 48.946%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int nums[1001] = { -1, -1, };
void del(int M) {
	//소수는 0, 소수가 아니면 -1을 저장한다.
	for (int i = 2; i <= M; i++) {
		for (int j = 2; i*j <= M; j++) {
			nums[i*j] = -1;
		}
	}
	
}
int main() {
	int n, num, cnt = 0;
	del(1000);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (nums[num] == 0) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}