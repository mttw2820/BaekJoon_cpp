//BaekJoon_6603
//�ζ�
/*
* ���� �ð� : 1s
* ���� ���� : 53.609%
*/

#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[]) {
	for (int i = 0; i < 6; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void makeLotto(vector<int> all, int now, int lotto[], int cnt) {
	// all�� ���� ����+cnt == 6 �� ��� ������ ���� ���θ� lotto�� �־���Ѵ�.
	if (all.size() - now == 6 - cnt) {
		for (int i = now; i < all.size(); i++, cnt++) {
			lotto[cnt] = all[i];
		}
	}
	// 6���� ���ڷ� �迭�� �ϼ��Ǹ� ����Ѵ�.
	if (cnt == 6) {
		printArray(lotto);
		return;
	}
	
	// all[now]�� �����ϴ� �迭
	lotto[cnt] = all[now];
	makeLotto(all, now + 1, lotto, cnt + 1);
	// all[now]�� �������� �ʴ� �迭
	makeLotto(all, now + 1, lotto, cnt);
	return;
}



int main() {
	while (true) {
		int k = 0;
		scanf("%d", &k);
		if (k == 0)	//��������
			break;
		vector<int> v(k,0);
		for (int i = 0; i < k; i++) {
			scanf("%d", &v[i]);
		}
		int lotto[7] = { 0, };
		makeLotto(v, 0, lotto, 0);
		printf("\n");
	}

	return 0;
}