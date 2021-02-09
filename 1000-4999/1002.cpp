//BaekJoon_1002
//�ͷ�
/*
* ���� �ð� : 2s
* ���� ���� : 18.782%
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	long long x1, y1, x2, y2, r1, r2;
	long long d = 0;
	int T = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);
		d = pow(x1 - x2, 2) + pow(y1 - y2, 2);
		if (d == 0) {
			if (r1 == r2)
				printf("-1\n");
			else printf("0\n");
			continue;
		}
		//r1 >= r2�� �ǵ��� ����
		if (r1 < r2) {	//SWAP
			int temp = r1;
			r1 = r2;
			r2 = temp;
		}
		long long in_range = pow(r1 - r2, 2);	//�����ϴ� ����� d ��
		long long out_range = pow(r1 + r2, 2); //�����ϴ� ����� d��
		if (d > out_range || d < in_range)
			printf("0\n");
		else if (d < out_range && d > in_range)
			printf("2\n");
		else printf("1\n");
	}
	return 0;
}