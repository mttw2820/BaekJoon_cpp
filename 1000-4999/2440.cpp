//BaekJoon_2440
//����� - 3
/*
* ���� �ð� : 1s
* ���� ���� : 67.005%
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