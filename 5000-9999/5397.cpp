//BaekJoon_5397
//키로거
/*
* 제한 시간 : 1s
* 정답 비율 : 23.425%
*/

#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;

char input[1000001];
int main() {
	int testcase;
	scanf("%d", &testcase);
	while (testcase-- != 0) {
		memset(input, ' ', sizeof(char) * 1000001);
		scanf("%s", input);
		stack<char> st_front;
		stack<char> st_back;

		for (int i = 0; input[i]; i++) {
			switch (input[i]) {
			case '>':
				if (st_back.empty()) break;
				st_front.push(st_back.top());
				st_back.pop();
				break;
			case '<':
				if (st_front.empty()) break;
				st_back.push(st_front.top());
				st_front.pop();
				break;
			case '-':
				if (st_front.empty()) break;
				st_front.pop();
				break;
			default:
				st_front.push(input[i]);
				break;
			}
		}
		while (!st_front.empty()) {
			st_back.push(st_front.top());
			st_front.pop();
		}

		while (!st_back.empty()) {
			printf("%c", st_back.top());
			st_back.pop();
		}
		cout << endl;
	}

	return 0;
}