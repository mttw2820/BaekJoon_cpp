//BaekJoon_5622
//다이얼
/*
* 제한 시간 : 1s
* 정답 비율 : 57.914%
*/
#include <iostream>
using namespace std;

int main() {
	char str[20];
	int dial = 0, time = 0;
	scanf("%s", str);
	for (int i = 0; str[i]; i++) {
		dial = str[i] - 'A';
		if (dial < 3)
			time += 3;
		else if (dial < 6)
			time += 4;
		else if (dial < 9)
			time += 5;
		else if (dial < 12)
			time += 6;
		else if (dial < 15)
			time += 7;
		else if (dial < 19)
			time += 8;
		else if (dial < 22)
			time += 9;
		else time += 10;
	}
	printf("%d\n", time);
	return 0;
}