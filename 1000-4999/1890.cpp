//BaekJoon_1890
//����
/*
* ���� �ð� : 1s
* ���� ���� : 26.843%
*/

#include <iostream>
using namespace std;

int n;							//�������� ������
int map[110][110] = { 0, };		//������
long cnt[110][110] = { 0, };	//Ƚ�� üũ

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//recursion���� �ϸ� �ð��ʰ� �߻�
	//-> ��� �̵� ��츦 �Ѿư� ���� ����
	//DP�� Ǯ��
	cnt[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cnt[i][j] == 0 || (i == n - 1 && j == n - 1))
				continue;
			
			int now = map[i][j];
			//down
			if (i + now < n)
				cnt[i + now][j] += cnt[i][j];
			//right
			if (j + now < n)
				cnt[i][j + now] += cnt[i][j];
		}
	}

	cout << cnt[n-1][n-1] << endl;
	return 0;
}