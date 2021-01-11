//BaekJoon_1003
//�Ǻ���ġ �Լ�
/*
* ���� �ð� : 0.25s
* ���� ���� : 29.102%
*/

#include <iostream>
using namespace std;

int fibo[50][2] = { 0, };
int main() {
	int n, ques;
	//��ó���� ���� �� ������ ���� ���⵵�� O(1)��
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