//BaekJoon_13251
//조약돌 꺼내기
/*
* 제한 시간 : 2s
* 정답 비율 : 39.003%
*/

#include <iostream>
using namespace std;

int main() {
	long double m, k;
	long double color[60] = { 0, };
	long double total = 0;
	scanf("%Lf", &m);
	for (int i = 0; i < m; i++) {
		scanf("%Lf", &color[i]);
		total += color[i];
	}
	scanf("%Lf", &k);

	long double per = 0;
	for (int i = 0; i < m; i++) {
		if (color[i] < k) continue;
		long double temp = 1;
		for (int j = 0; j < k; j++) {
			temp *= (color[i] - j) / (total - j);
		}
		per += (temp);
	}

	printf("%.10Lf\n", per);
	return 0;
}