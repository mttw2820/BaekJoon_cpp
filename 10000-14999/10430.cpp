//BaekJoon_10430
//������
/*
* ���� �ð� : 1s
* ���� ���� : 59.718%
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int plus = (a + b) % c;
	int mult = (a*b) % c;
	printf("%d\n%d\n%d\n%d\n", plus, plus, mult, mult);

	return 0;
}