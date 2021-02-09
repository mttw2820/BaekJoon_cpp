//BaekJoon_11501
//주식
/*
* 제한 시간 : 5s
* 정답 비율 : 34.504%
*/

#include <iostream>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int* st = new int[n+1];

		for (int i = 0; i < n; i++)
			cin >> st[i];

		long long ans = 0;
		int max = 0;
		for(int i = n - 1; i >= 0; i--) {
			if (st[i] > max)
				max = st[i];
			else
				ans += (max - st[i]);
		}

		cout << ans << endl;
	}


	return 0;
}