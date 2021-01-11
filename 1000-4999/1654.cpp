//BaekJoon_1654
//랜선 자르기
/*
* 제한 시간 : 2s
* 정답 비율 : 19.117%
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<long long> lan;
int main() {

	int k, n;
	long long temp;
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> temp;
		lan.push_back(temp);
	}
	sort(lan.begin(), lan.begin() + k);
	long long start = 1, end = lan[k - 1];
	long long ans = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		// mid의 경우 자를 수 있는 랜선의 개수
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (lan[i] / mid);
		}

		// 랜선의 개수가 n을 넘기면 start = mid
		// 일단 저장해둔다
		if (cnt >= n) {
			start = mid + 1;
			if (mid > ans) ans = mid;
		}
		// 랜선의 개수가 n보다 작으면 end = mid
		else if (cnt < n) {
			end = mid - 1;
		}
	}

	cout << ans << endl;

	return 0;
}