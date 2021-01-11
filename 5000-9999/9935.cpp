//BaekJoon_9935
//문자열 폭발
/*
* 제한 시간 : 2s
* 정답 비율 : 20.531%
*/

#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

char input[1000001];
char explode[40];
int main() {
	stack<char> st_front;
	stack<char> st_back;
	bool flag = true;
	int exp_size = 0;

	scanf("%s", input);
	scanf("%s", explode);
	for (int i = strlen(input)-1; i>=0; i--) {
		st_back.push(input[i]);
	}
	exp_size = strlen(explode);
	

	int cnt_exp = 0;
	while (!st_back.empty()) {
		if (st_back.top() == explode[cnt_exp]) 
			cnt_exp++;
		else cnt_exp = 0;
		if (st_back.top() == explode[cnt_exp])
			cnt_exp++;
		st_front.push(st_back.top());
		st_back.pop();
			
		// explode
		if (cnt_exp == exp_size) {
			flag = true;
			cnt_exp = 0;
			for (int i = 0; i < exp_size; i++)
				st_front.pop();
			for (int i = 0; i < exp_size && !st_front.empty(); i++) {
				st_back.push(st_front.top());
				st_front.pop();
			}
		}
	}

	while (!st_front.empty()) {
		st_back.push(st_front.top());
		st_front.pop();
	}
	if (st_back.empty()) {
		printf("FRULA\n");
	}
	else {
		while (!st_back.empty()) {
			printf("%c", st_back.top());
			st_back.pop();
		}
		printf("\n");
	}
	return 0;
}