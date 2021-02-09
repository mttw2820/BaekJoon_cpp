//BaekJoon_11721
//열 개씩 끊어 출력하기
/*
* 제한 시간 : 1.5s
* 정답 비율 : 36.348%
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string word;
	cin >> word;
	for (int i = 0; i < word.size(); i++) {
		if ((i + 1) % 10 == 0) {
			cout << word[i] << endl;
		}
		else cout << word[i];
	}

	return 0;
}