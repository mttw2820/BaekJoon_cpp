//BaekJoon_1918
//후위 표기식
/*
* 제한 시간 : 2s
* 정답 비율 : 30.843%
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	char input[110] = "", output[110] = "";
	int in = 0, out = 0;
	stack<char> op;

	scanf("%s", input);
	for (; input[in]; in++) {
		if (input[in] == '+' || input[in] == '-') {
			while (!op.empty() && op.top() != '(') {
				output[out++] = op.top();
				op.pop();
			}
			op.push(input[in]);
		}
		else if (input[in] == '*' || input[in] == '/') {
			while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				output[out++] = op.top();
				op.pop();
			}
			op.push(input[in]);
		}
		else if (input[in] == '(') {
			op.push(input[in]);
		}
		else if (input[in] == ')') {
			while (!op.empty() && op.top() != '(') {
				output[out++] = op.top();
				op.pop();
			}
			op.pop();
		}
		else {
			output[out++] = input[in];
		}
	}
	while (!op.empty()) {
		output[out++] = op.top();
		op.pop();
	}
	printf("%s\n", output);
	return 0;
}