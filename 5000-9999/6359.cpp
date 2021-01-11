// BaekJoon_6359
// 만취한 상범
/*
* 제한 시간 : 1s
* 정답 비율 : 69.990%
*/

#include <iostream>
#include <string.h>
using namespace std;

int count_door(int door[], int n);
int main() {
	int testcase, n;
	cin >> testcase;
	
	while (testcase--) {
		int door[110] = { 0, };
		cin >> n;
		for (int i = 2; i <= n; i++) {
			for (int j = 1; i*j < n+3; j++)
				door[i*j]++;
		}

		cout << count_door(door, n) << endl;
	}

	return 0;
}

int count_door(int door[], int n) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (door[i] % 2 == 0) cnt++;
	}
	return cnt;
}