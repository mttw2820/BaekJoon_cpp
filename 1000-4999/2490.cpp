//BaekJoon_2490
//윷놀이
/*
* 제한 시간 : 1s
* 정답 비율 : 59.234%
*/

#include <iostream>
using namespace std;

int main() {
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 4; j++) {
			int temp = 0;
			scanf("%d", &temp);
			sum += temp;
		}
		char ans;
		if (sum == 0) ans = 'D';
		else if (sum == 1) ans = 'C';
		else if (sum == 2) ans = 'B';
		else if (sum == 3) ans = 'A';
		else ans = 'E';
		printf("%c\n", ans);
	}

	return 0;
}