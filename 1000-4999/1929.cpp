//BaekJoon_1929
//소수 구하기
/*
* 제한 시간 : 2s
* 정답 비율 : 27.812%
*/

#include <iostream>
#include <queue>
using namespace std;

bool prime[1000010];
queue<int> ans;
int main() {
	int from, to;
	scanf("%d %d", &from, &to);

	for (int i = 2; i <= to; i++) {
		if (prime[i] == false) {
			if (i >= from) ans.push(i);
			for (int j = 2; i*j <= to; j++) {
				prime[i*j] = true;
			}
		}
	}

	while (!ans.empty()) {
		printf("%d\n", ans.front());
		ans.pop();
	}
	return 0;
}