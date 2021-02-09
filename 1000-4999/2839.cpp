//BaekJoon_2839
//설탕 배달
/*
* 제한 시간 : 1s
* 정답 비율 : 32.612%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int salt[5010] = { 0, };
	salt[0] = 0;
	salt[1] = salt[2] = -1;
	salt[3] = salt[5] = 1;
	salt[4] = -1;

	for (int i = 6; i <= n; i++) {
		if (salt[i - 3] < 0 && salt[i - 5] < 0)
			salt[i] = -1;
		else {
			if (salt[i - 3] < 0) salt[i] = salt[i - 5] + 1;
			else if (salt[i - 5] < 0) salt[i] = salt[i - 3] + 1;
			else {
				salt[i] = min(salt[i - 3], salt[i - 5]) + 1;
			}
		}
	}

	cout << salt[n] << endl;

	return 0;
}