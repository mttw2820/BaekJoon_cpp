//BaekJoon_2864
//5와 6의 차이
/*
* 제한 시간 : 1s
* 정답 비율 : 73.011%
*/

#include <iostream>
using namespace std;

int makeMax(int num);
int makeMin(int num);

int main() {
	int a, b;
	cin >> a >> b;

	cout << makeMin(a) + makeMin(b) << " " << makeMax(a) + makeMax(b) << endl;

	return 0;
}

int makeMin(int num) {
	int minNum = 0;
	for (int i = 1; i <= num; i*=10) {
		int now = num % (i * 10) / i;
		if (now == 6) now = 5;
		minNum += now*i;
	}
	return minNum;
}

int makeMax(int num) {
	int maxNum = 0;
	for (int j = 1; j <= num; j *= 10) {
		int now = num % (j * 10) / j;
		if (now == 5) now = 6;
		maxNum += now*j;
	}
	return maxNum;
}