//BaekJoon_11052
//카드 구매하기
/*
* 제한 시간 : 1s
* 정답 비율 : 60.610%
*/

#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int fish[1010] = { 0 };
	for (int i = 1; i <= n; i++)
		cin >> fish[i];

	int profit[1010] = { 0 };
	for (int i = 1; i <= n; i++) {
		profit[i] = fish[i];
	}
	
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i <= j) break;
			if (i > j && profit[i] < profit[i - j] + fish[j])
				profit[i] = profit[i - j] + fish[j];
		}
	}

	cout << profit[n] << endl;

	return 0;
}