//BaekJoon_2579
//계단 오르기
/*
* 제한 시간 : 1s
* 정답 비율 : 35.975%
*/

#include <iostream>
using namespace std;

int main() {
	int n, s[310] = {0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i+1];
	}
	
	int p[310] = { 0, };
	p[1] = s[1];
	p[2] = s[1] + s[2];
	for (int i = 3; i <= n; i++) {


	}
	
	return 0;
}