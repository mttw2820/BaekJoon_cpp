//BaekJoon_1890
//점프
/*
* 제한 시간 : 1s
* 정답 비율 : 26.843%
*/

#include <iostream>
using namespace std;

int n;							//게임판의 사이즈
int map[110][110] = { 0, };		//게임판
long cnt[110][110] = { 0, };	//횟수 체크

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//recursion으로 하면 시간초과 발생
	//-> 모든 이동 경우를 쫓아갈 수는 없음
	//DP로 풀이
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