//BaekJoon_1874
//스택 수열
/*
* 제한 시간 : 2s
* 정답 비율 : 31.384%
*/

#include <iostream>
#include <stack>
using namespace std;

char ans[200010] = { ' ', };
int num[100010] = { 0, };

int main() {
	int n, cnt = 0;
	stack<int> st;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	for (int i = 0, j = 1; i < n && j <= n + 1; i++) {
		for (; j <= num[i]; j++) {
			st.push(j);
			ans[cnt++] = '+';
		}
		if (!st.empty() && st.top() == num[i]) {
			st.pop();
			ans[cnt++] = '-';
		}
		else break;
	}

	if (cnt == 2 * n) {
		for (int i = 0; i < cnt; i++) {
			printf("%c\n", ans[i]);
		}
	}
	else {
		printf("NO\n");
	}
	return 0;
}