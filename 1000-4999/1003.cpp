//BaekJoon_1003
//피보나치 함수
/*
* 제한 시간 : 0.25s
* 정답 비율 : 29.102%
*/

#include <iostream>
using namespace std;

int fibo[50][2] = { 0, };
int main() {
	int n, ques;
	//선처리를 통해 각 질문에 대한 복잡도를 O(1)로
	fibo[0][0] = fibo[1][1] = 1;
	fibo[0][1] = fibo[1][0] = 0;
	for (int i = 2; i < 41; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
	}

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &ques);
		printf("%d %d\n", fibo[ques][0], fibo[ques][1]);
	}

	return 0;
}