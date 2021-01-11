//BaekJoon_2011
//암호코드
/*
* 제한 시간 : 2s
* 정답 비율 : 19.762%
*/

#include <iostream>
using namespace std;

char code[5001];
int dp[5001] = { 0, };
//dp[i]는 code[i-1]까지 나올 수 있는 최대 해석 경우의 수
int main() {
	scanf("%s", code);

	dp[0] = 1; dp[1] = 1;
	int prev = code[0] - '0';
	//첫 글자가 0이면 오류
	if (prev == 0) {
		cout << "0" << endl;
		return 0;
	}
	int i = 2;
	for (i = 2; code[i-1]; i++) {
		int now = code[i-1] - '0';
		//0이 두번이상 연속
		if (now == 0 && prev == 0) {
			cout << "0" << endl;
			return 0;
		}
		//한자리 수 암호일 경우
		if (now != 0) {
			dp[i] = dp[i - 1];
		}
		//두자리 수 암호일 경우
		if ((prev == 1)||(prev == 2 && now <= 6)) {	
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
		
		prev = now;
	}
	cout << dp[i-1] << endl;
	return 0;
}