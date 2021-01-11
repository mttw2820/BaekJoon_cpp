//BaekJoon_1672
//DNA 해독
/*
* 제한 시간 : 5s
* 정답 비율 : 57.030%
*/

#include <iostream>
using namespace std;

int main() {
	int N;
	char dna[1000010];
	scanf("%d %s", &N, dna);

	for (int i = N - 1; i > 0; i--) {
		int a1 = dna[i];
		int a2 = dna[i - 1];
		char next[2];
		if (a1 == 'A') {
			if (a2 == 'A' || a2 == 'C') next[0] = 'A';
			else if (a2 == 'G') next[0] = 'C';
			else next[0] = 'G';
		}
		else if (a1 == 'G') {
			if (a2 == 'A') next[0] = 'C';
			else if (a2 == 'G') next[0] = 'G';
			else if (a2 == 'C') next[0] = 'T';
			else next[0] = 'A';
		}
		else if (a1 == 'C') {
			if (a2 == 'A') next[0] = 'A';
			else if (a2 == 'G') next[0] = 'T';
			else if (a2 == 'C') next[0] = 'C';
			else next[0] = 'G';
		}
		else {
			if (a2 == 'A' || a2 == 'C') next[0] = 'G';
			else if (a2 == 'G') next[0] = 'A';
			else next[0] = 'T';
		}
		dna[i - 1] = next[0];
	}
	printf("%c\n", dna[0]);



	return 0;
}