//BaekJoon_10799
//�踷���
/*
* ���� �ð� : 1s
* ���� ���� : 61.102%
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
			// �������� ���
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