//BaekJoon_2438
//별 찍기 - 1
/*
* 제한 시간 : 1s
* 정답 비율 : 62.351%
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string star = "*";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << star << endl;
		star += "*";
	}
	return 0;
}