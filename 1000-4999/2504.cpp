//BaekJoon_2504
//괄호의 값
/*
* 제한 시간 : 1s
* 정답 비율 : 28.134%
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<char> brac;
	stack<int> cal;
	char input[50] = "";
	int total = 0;
	scanf("%s", input);

	bool flag = true;
	for (int i = 0; input[i]; i++) {
		if (input[i] == '(' || input[i] == '[') {
			brac.push(input[i]);
			cal.push(0);
		}
		else if (input[i] == ')') {
			if (brac.empty() || brac.top() != '(') {
				flag = false;
				break;
			}
			brac.pop();
			if (cal.top() == 0) {
				cal.pop();
				cal.push(2);
			}
			else {
				int in = 0;
				while (cal.top() != 0) {
					in += cal.top();
					cal.pop();
				}
				cal.pop();
				cal.push(in*2);
			}
		}
		else if (input[i] == ']') {
			if (brac.empty() || brac.top() != '[') {
				flag = false;
				break;
			}
			brac.pop();
			if (cal.top() == 0) {
				cal.pop();
				cal.push(3);
			}
			else {
				int in = 0;
				while (cal.top() != 0) {
					in += cal.top();
					cal.pop();
				}
				cal.pop();
				cal.push(in*3);
			}
		}
		if (brac.empty()) {
			// 한 묶음 끝
			while (!cal.empty()) {
				total += cal.top();
				cal.pop();
			}
		}
	}
	if (flag) printf("%d\n", total);
	else printf("0\n");

	return 0;
}