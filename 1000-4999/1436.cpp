//BaekJoon_1436
//영화감독 숌
/*
* 제한 시간 : 2s
* 정답 비율 : 46.170%
*/

#include <iostream>
using namespace std;

int main() {
	long long num = 666;
	long long ten = 100;
	int n;
	cin >> n;
	while (n != 0) {
		if (num >= ten * 10) ten *= 10;
		int flag = 0;
		int div = ten;
		int temp = num;
		while (div != 0) {
			if (temp / div == 6) flag++;
			else if(flag<3) flag = 0;
			else break;
			temp %= div;
			div /= 10;
		}
		if (flag >= 3) n--;

		num++;
	}
	cout << num - 1 << endl;

	return 0;
}