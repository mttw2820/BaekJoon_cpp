//BaekJoon_9251
//LCS
/*
* 제한 시간 : 1s
* 정답 비율 : 41.493%
*/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s1[1000], s2[1000];
int LCS[1010][1010];
int main() {

	cin >> s1;
	cin >> s2;

	int prev = 0;
	for (int i = 0; i < strlen(s1); i++) {
		if (s1[i] == s2[0])	prev = 1;
		LCS[i][0] = prev;
	}
	prev = 0;
	for (int i = 0; i < strlen(s2); i++) {
		if (s1[0] == s2[i])	prev = 1;
		LCS[0][i] = prev;
	}
		
	for (int i = 1; i < strlen(s1); i++) {
		for (int j = 1; j < strlen(s2); j++) {
			if (s1[i] == s2[j])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}
	cout << LCS[strlen(s1) - 1][strlen(s2) - 1] << endl;
	return 0;
}