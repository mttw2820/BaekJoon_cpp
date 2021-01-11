//BaekJoon_1259
//팰린드롬수
/*
* 제한 시간 : 1s
* 정답 비율 : 67.679%
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	while (true) {
		cin >> str;
		if (str == "0") break;	// 종료 조건
		int len = str.length();
		
		int j = len - 1;
		bool flag = true;
		for (int i = 0; i < len / 2; i++) {
			if (str[i] != str[j]) {
				flag = false;
				break;
			}
			j--;
		}
		if (flag) cout << "yes" << endl;
		else cout << "no" << endl;

	}
	return 0;
}