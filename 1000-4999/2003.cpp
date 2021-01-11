//BaekJoon_2003
//수들의 합 2
/*
* 제한 시간 : 0.5s
* 정답 비율 : 50.582%
*/


#include <iostream>
using namespace std;

int arr[10001] = { 0, };
int main() {
	int n, cnt = 0;
	long long m;
	scanf("%d %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	int L = 0, R = 0;
	while (R < n) {
		long long sum = 0;
		//구간 합 구하기
		for (int i = L; i <= R; i++) 
			sum += arr[i];
		
		if (sum == m) {
			cnt++;
			R++;
			continue;
		}
		if (sum < m || L >= R) R++;
		else L++;
	}

	cout << cnt << endl;
	return 0;
}