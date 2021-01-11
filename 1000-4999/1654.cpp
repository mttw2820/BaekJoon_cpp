//BaekJoon_1654
//���� �ڸ���
/*
* ���� �ð� : 2s
* ���� ���� : 19.117%
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
		// mid�� ��� �ڸ� �� �ִ� ������ ����
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += (lan[i] / mid);
		}

		// ������ ������ n�� �ѱ�� start = mid
		// �ϴ� �����صд�
		if (cnt >= n) {
			start = mid + 1;
			if (mid > ans) ans = mid;
		}
		// ������ ������ n���� ������ end = mid
		else if (cnt < n) {
			end = mid - 1;
		}
	}

	cout << ans << endl;

	return 0;
}