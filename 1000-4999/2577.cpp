//BaekJoon_2577
//숫자의 개수
/*
* 제한 시간 : 1s
* 정답 비율 : 60.603%
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long multiply = a*b*c;
	int cnt[11] = { 0, };
	for (int i = 0; multiply >= pow(10, i); i++) {
		int temp = pow(10, i + 1);
		int now = multiply%temp / pow(10, i);
		cnt[now]++;
	}
	for (int i = 0; i < 10; i++)
		cout << cnt[i] << endl;

	return 0;
}