//BaekJoon_11497
//통나무 건너뛰기
/*
* 제한 시간 : 1s
* 정답 비율 : 59.306%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n;
	int tong[10001] = { 0, };
	int ans[10001] = { 0, };
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> tong[i];
		sort(tong, tong + n);
		for (int i = 0; i < n; i++) {
			int temp = i / 2;
			if (i % 2 == 0) 
				ans[temp] = tong[n - i - 1];
			else
				ans[n - temp -1] = tong[n - i - 1];
		}
		int level = 0;
		for (int i = 0; i < n - 1; i++) {
			int temp = ans[i] - ans[i + 1];
			if (temp < 0) temp = -temp;
			if (temp >= level) level = temp;
		}
		cout << level <<endl;
	}

	return 0;
}