//BaekJoon_11576
//Base Conversion
/*
* ���� �ð� : 2s
* ���� ���� : 58.273%
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int a, b, m;
	scanf("%d %d %d", &a, &b, &m);

	// a���� -> 10����
	int tens = 0, input;
	for (int i = 0; i < m; i++) {
		scanf("%d", &input);
		tens *= a;
		tens += input;
	}

	// 10���� -> b����
	stack<int> ans;
	if (tens == 0) ans.push(0);
	while (tens != 0) {
		ans.push(tens%b);
		tens /= b;
	}

	// ��� ���
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	printf("\n");
	return 0;
}