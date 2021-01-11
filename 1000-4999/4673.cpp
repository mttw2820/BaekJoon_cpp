//BaekJoon_4673
//셀프 넘버
/*
* 제한 시간 : 1s
* 정답 비율 : 51.392%
*/

#include <iostream>
#define MAX 10000
using namespace std;

// selfNumber라면 false 아니면 true
bool selfNum[MAX + 5];
int next_number(int now) {
	int next = 0;
	next = now;
	for (int i = 0; now != 0; i++) {
		next += now % 10;
		now /= 10;
	}
	return next;
}

void check_selfNum(int now) {
	int next = next_number(now);
	if (next <= MAX && selfNum[next] == false) {
		selfNum[next] = true;
		check_selfNum(next);
	}
	return;
}

int main() {
	for (int i = 1; i <= MAX; i++) {
		if (selfNum[i] == false) {
			printf("%d\n", i);
			check_selfNum(i);
		}
	}


	return 0;
}