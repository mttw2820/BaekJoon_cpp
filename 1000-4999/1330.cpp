//BaekJoon_1330
//�� �� ���ϱ�
/*
* ���� �ð� : 1s
* ���� ���� : 66.451%
*/

#include <iostream>
using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	if (a > b) printf(">\n");
	else if (a < b) printf("<\n");
	else printf("==\n");

	return 0;
}