//BaekJoon_1085
//���簢������ Ż��
/*
* ���� �ð� : 2s
* ���� ���� : 56.887%
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	int len = 0;
	scanf("%d %d %d %d", &x, &y, &w, &h);
	len = x;
	len = min(len, min(y, min(w - x, h - y)));
	printf("%d\n", len);

	return 0;
}