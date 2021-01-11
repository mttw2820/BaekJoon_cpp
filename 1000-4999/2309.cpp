//BaekJoon_2309
//�ϰ� ������
/*
* ���� �ð� : 2s
* ���� ���� : 45.314%
*/

#include <iostream>
#include <algorithm>
using namespace std;

bool flag_end = false;

void print_seven(int height[], int a, int b) {
	for (int i = 0; i < 9; i++) {
		if (i == a || i == b) continue;
		printf("%d\n", height[i]);
	}
	return;
}

// �� �� ������ ����
void make_set(int total, int height[]) {
	for (int i = 0; i < 8; i++) {
		for (int j = i; j < 9; j++) {
			if (total - height[i] - height[j] == 100) {
				print_seven(height, i, j);
				return;
			}
		}
	}
	return;
}
int main() {
	int height[10] = { 0, };
	int total = 0;
	for (int i = 0; i < 9; i++) {
		scanf("%d", &height[i]);
		total += height[i];
	}
	sort(height, height + 9);
	make_set(total, height);


	return 0;
}