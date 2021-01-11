//BaekJoon_9252
//LCS2
/*
* 제한 시간 : 1s
* 정답 비율 : 42.061%
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string LCS[1010][1010];

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	
	string prev="";
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] == s2[0]) prev = s2[0];
		LCS[i][0] = prev;
	}
	prev = "";
	for (int i = 0; i < s2.length(); i++) {
		if (s1[0] == s2[i]) prev = s1[0];
		LCS[0][i] = prev;
	}
	for (int i = 1; i < s1.length(); i++) {
		for (int j = 1; j < s2.length(); j++) {
			if (s1[i] == s2[j])
				LCS[i][j] = LCS[i - 1][j - 1] + s1[i];
			else {
				LCS[i][j] = LCS[i - 1][j];
				if (LCS[i][j].length() < LCS[i][j - 1].length())
					LCS[i][j] = LCS[i][j - 1];
			}
		}
	}

	string ans = LCS[s1.length() - 1][s2.length() - 1];
	cout << ans.length() << endl << ans << endl;

	return 0;
}