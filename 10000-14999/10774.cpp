//BaekJoon_10774
//저지
/*
* 제한 시간 : 1s
* 정답 비율 : 46.465%
*/

#include <iostream>
using namespace std;

char Jsize[1000001];

int main() {
	int j, a, num, ans = 0;
	char s[3];
	scanf("%d %d", &j, &a);

	// 1부터 j 조심
	for (int i = 1; i <= j; i++) {
		scanf("%s", &Jsize[i]);
	}

	for (int i = 0; i < a; i++) {
		scanf("%s %d", &s[0], &num);
		
		if (Jsize[num] == 'X') // 해당 번호가 이미 없다
			continue;

		if (s[0] == 'S') {
			ans++;
			Jsize[num] = 'X';
		}
		else if (s[0] == 'M') {
			if (Jsize[num] != 'S') {
				ans++;
				Jsize[num] = 'X';
			}
		}
		else if (s[0] == 'L') {
			if (Jsize[num] == 'L') {
				ans++;
				Jsize[num] = 'X';
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}