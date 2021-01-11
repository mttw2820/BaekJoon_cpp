//BaekJoon_2688
//�پ���� �ʾ�
/*
* ���� �ð� : 1s
* ���� ���� : 49.329%
*/

#include <iostream>
using namespace std;

long long upperNum[65][11];	//upperNum[i][j] : j�� ������ i�ڸ��� ��
int checkLevel[65];
int main() {
	int tc, n;
	for (int i = 0; i < 10; i++) 
		upperNum[1][i] = 1;
	checkLevel[1] = 1;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		// ���� �������� ����� �ִ� ������ ���Ѵ�.
		int level = 1;
		while (checkLevel[level] != 0) level++;
		
		for (; level <= n; level++) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j <= i; j++) {
					upperNum[level][i] += upperNum[level - 1][j];
				}
			}
			checkLevel[level] = 1;
		}

		long long ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += upperNum[n][i];
		}
		cout << ans << endl;
	}

	return 0;
}