//BaekJoon_10799
//쇠막대기
/*
* 제한 시간 : 1s
* 정답 비율 : 61.102%
*/

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main() {
	char brac[100001];
	stack<int> st;
	int cnt = 0, total = 0;
	scanf("%s", brac);
	
	for (int i = 0; brac[i]; i++) {
		if (brac[i] == '(') {
			st.push(cnt);
		}
		else if (brac[i] == ')') {
			// 레이저인 경우
			if (st.top() == cnt) {
				cnt++;
				st.pop();
			}
			else {
				total += (cnt - st.top() + 1);
				st.pop();
			}
		}
	}
	printf("%d\n", total);

	return 0;
}