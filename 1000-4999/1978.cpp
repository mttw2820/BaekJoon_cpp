//BaekJoon_1978
//�Ҽ� ã��
/*
* ���� �ð� : 2s
* ���� ���� : 48.946%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int nums[1001] = { -1, -1, };
void del(int M) {
	//�Ҽ��� 0, �Ҽ��� �ƴϸ� -1�� �����Ѵ�.
	for (int i = 2; i <= M; i++) {
		for (int j = 2; i*j <= M; j++) {
			nums[i*j] = -1;
		}
	}
	
}
int main() {
	int n, num, cnt = 0;
	del(1000);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		if (nums[num] == 0) cnt++;
	}
	printf("%d\n", cnt);

	return 0;
}