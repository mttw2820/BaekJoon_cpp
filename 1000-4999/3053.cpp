//BaekJoon_3053
//�ý� ������
/*
* ���� �ð� : 1s
* ���� ���� : 40.473%
*/

#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <math.h>

int main() {
	long double radius;
	cin >> radius;
	long double eu = radius * radius * M_PI;
	long double taxi = 4 * radius * radius / 2.0;
	
	// ��� ������ �׻� ����
	// long long �� %lld , long doubl�� %Lf
	printf("%.6Lf\n", eu);
	printf("%.6Lf\n", taxi);
	return 0;
}