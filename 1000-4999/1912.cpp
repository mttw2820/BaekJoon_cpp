//BaekJoon_1912
//연속합
/*
* 제한 시간 : 1s
* 정답 비율 : 29.893%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	int nums[100001] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i];
	int m = -2000;
	for (int i = 0; i < n-1; i++) {
		int temp = nums[i] + nums[i + 1];
		if (temp > m) m = temp;
	}
	cout << m << endl;
	return 0;
}