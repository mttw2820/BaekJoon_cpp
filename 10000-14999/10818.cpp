//BaekJoon_10818
//최소, 최대
/*
* 제한 시간 : 1s
* 정답 비율 : 52.874%
*/

#include <iostream>
using namespace std;

int arr[1000001] = { 0, };

int main() {
	int n, min, max;
	scanf("%d", &n);
	scanf("%d", &arr[0]);
	min = arr[0]; max = arr[0];
	for (int i = 1; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] < min) min = arr[i];
		if (arr[i] > max) max = arr[i];
	}

	printf("%d %d\n", min, max);

	return 0;
}