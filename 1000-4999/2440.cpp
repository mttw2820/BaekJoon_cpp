//BaekJoon_2440
//별찍기 - 3
/*
* 제한 시간 : 1s
* 정답 비율 : 67.005%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = n; i >0; i--) {
		for (int j = 0; j < i; j++) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}