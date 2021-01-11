//BaekJoon_1935
//후위 표기식2
/*
* 제한 시간 : 2s
* 정답 비율 : 44.234%
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	stack<double> alpha;
	char input[100];
	int real_number[30] = { 0, };
	int n;
	double a = 0, b = 0;
	scanf("%d", &n);
	scanf("%s", input);

	for (int i = 0; i < n; i++) {
		scanf("%d", &real_number[i]);
	}

	for (int i = 0; input[i]; i++) {
		switch (input[i]) {
		case '+':
			if (!alpha.empty()) {
				b = alpha.top(); alpha.pop();
				a = alpha.top(); alpha.pop();
			}
			alpha.push(a + b);
			break;
		case '-':
			if (!alpha.empty()) {
				b = alpha.top(); alpha.pop();
				a = alpha.top(); alpha.pop();
			}
			alpha.push(a - b);
			break;
		case '/':
			if (!alpha.empty()) {
				b = alpha.top(); alpha.pop();
				a = alpha.top(); alpha.pop();
			}
			alpha.push(a / b);
			break;
		case '*':
			if (!alpha.empty()) {
				b = alpha.top(); alpha.pop();
				a = alpha.top(); alpha.pop();
			}
			alpha.push(a * b);
			break;
		default:
			alpha.push(real_number[input[i] - 'A']);
			break;
		}
	}

	if (!alpha.empty()) {
		double result = alpha.top();
		printf("%.2lf\n", result);
	}

	return 0;
}