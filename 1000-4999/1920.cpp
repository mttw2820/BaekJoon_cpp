//BaekJoon_1920
//수 찾기
/*
* 제한 시간 : 2s
* 정답 비율 : 27.880%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100001] = { 0, };
int b[100001] = { 0, };

int find(int x) {
	int left = 0;	int right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x) {
			return 1;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		printf("%d\n", find(b[i]));
	}

	return 0;
}