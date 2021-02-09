//BaekJoon_1157
//단어 공부
/*
* 제한 시간 : 2s
* 정답 비율 : 38.741%
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string word;
	long long cnt[30] = { 0, };
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		int temp = word[i];
		if (temp > 95) temp -= 97;
		else temp -= 65;
		cnt[temp]++;
	}
	int flag = 0;
	int max = 0;
	for (int i = 1; i <= 26; i++) {
		if (cnt[i] == 0) continue;
		if (cnt[i] == cnt[max]) flag = 1;
		if (cnt[i] > cnt[max]) {
			max = i;
			flag = 0;
		}
	}
	if (flag == 1) cout << "?" << endl;
	else {
		printf("%c\n", max + 65);
	}

	return 0;
}