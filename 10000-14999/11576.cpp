//BaekJoon_11576
//Base Conversion
/*
* 제한 시간 : 2s
* 정답 비율 : 58.273%
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int a, b, m;
	scanf("%d %d %d", &a, &b, &m);

	// a진법 -> 10진법
	int tens = 0, input;
	for (int i = 0; i < m; i++) {
		scanf("%d", &input);
		tens *= a;
		tens += input;
	}

	// 10진법 -> b진법
	stack<int> ans;
	if (tens == 0) ans.push(0);
	while (tens != 0) {
		ans.push(tens%b);
		tens /= b;
	}

	// 결과 출력
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}