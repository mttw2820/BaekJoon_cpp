//BaekJoon_2011
//암호코드
/*
* 제한 시간 : 2s
* 정답 비율 : 19.449%
*/

#include <iostream>
#include <math.h>
using namespace std;

int x=0, cnt = 0;
long long num[5010];
void code(int p) {
	if (p <= 0) {
		cnt++;
		cnt %= 1000000;
	}
	else {
		code(p - 1);
		int temp = 10 * num[p] + num[p - 1];
		if (temp <= 26) code(p - 2);
	}
}

int main() {
	long long w;
	cin >> w;
	for (int i = 0; w > pow(10, i); i++) {
		long long temp = pow(10, i + 1);
		num[i] = (w % temp) / pow(10, i); 
		x++;
	}

	code(x-1);
	cout << cnt << endl;


	return 0;
}