//BaekJoon_2688
//줄어들지 않아
/*
* 제한 시간 : 1s
* 정답 비율 : 49.329%
*/

#include <iostream>
using namespace std;

long long upperNum[65][11];	//upperNum[i][j] : j로 끝나는 i자리의 수
int checkLevel[65];
int main() {
	int tc, n;
	for (int i = 0; i < 10; i++) 
		upperNum[1][i] = 1;
	checkLevel[1] = 1;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d", &n);
		// 이전 문제에서 저장된 최대 레벨을 구한다.
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