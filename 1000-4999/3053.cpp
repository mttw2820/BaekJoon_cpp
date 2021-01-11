//BaekJoon_3053
//택시 기하학
/*
* 제한 시간 : 1s
* 정답 비율 : 40.473%
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
	
	// 출력 형식은 항상 주의
	// long long 은 %lld , long doubl은 %Lf
	printf("%.6Lf\n", eu);
	printf("%.6Lf\n", taxi);
	return 0;
}