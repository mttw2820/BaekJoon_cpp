//BaekJoon_1016
//���� ������
/*
* ���� �ð� : 2s
* ���� ���� : 19.149%
*/

#include <iostream>
#include <cmath>
#define MAX 1000005
using namespace std;

bool nono[MAX] = { false, };

int main() {
	long long min, max, cnt = 0;
	scanf("%lld %lld", &min, &max);

	long long sq_max = (long long)sqrt(max);
	for (long long i = 2; i <= sq_max; i++) {
		long long sq = i*i;

		// ������ ã��
		long long start = 0;
		if (min % sq == 0) { start = min; }
		else { start = sq * (min / sq + 1); }
		
		for (start; start <= max; start += sq) {
			long long index = start - min;
			if (!nono[index]) {
				nono[index] = true;
				cnt++;
			}
		}
	}

	printf("%lld\n", max - min - cnt + 1);

	return 0;
}