//BaekJoon_1789
//수들의 합
/*
* 제한 시간 : 2s
* 정답 비율 : 42.343%
*/

#include <iostream>
using namespace std;

int main() {
	long long sum = 0;
	cin >> sum;

	long long plus = 1;
	while (true) {
		sum -= plus;
		if (sum < 0) {
			plus--;
			break;
		}
		plus++;
	}

	cout << plus << endl;

	return 0;
}