//BaekJoon_1676
//���丮�� 0�� ����
/*
* ���� �ð� : 2s
* ���� ���� : 46.749%
*/

#include <iostream>
using namespace std;

int main() {
	int n, cnt = 0;
	scanf("%d", &n);

	for (int i = 1; i * 5 <= n; i++) {
		int num = i * 5;
		while (num % 5 == 0) {
			num /= 5;
			cnt++;
		}
	}
	cout << cnt << "\n";

	return 0;
}