//BaekJoon_1463
//1�� �����
/*
* ���� �ð� : 2s
* ���� ���� : 32.0%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int cnt[1000000];
	cnt[1] = 0;

	// n-1 �Ǵ� n/2 �Ǵ� n/3
	for (int i = 2; i <= n; i++) {
		cnt[i] = cnt[i - 1] + 1;
		if (i % 2 == 0 && cnt[i] > cnt[i / 2] + 1)
			cnt[i] = cnt[i / 2] + 1;
		if (i % 3 == 0 && cnt[i] > cnt[i / 3] + 1)
			cnt[i] = cnt[i / 3] + 1;
	}

	cout << cnt[n] << endl;

	return 0;
}