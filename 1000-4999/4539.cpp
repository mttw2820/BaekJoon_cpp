//BaekJoon_4539
//반올림
/*
* 제한 시간 : 1s
* 정답 비율 : 72.790%
*/

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int n;
	long long num[100];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		int p = 1;
		while (num[i] >= p*10) {
			long long temp = num[i] % (p * 10) / p;
			if (temp >= 5) num[i] = (num[i] + (p * 10)) / (p * 10);
			else num[i] /= (p * 10);
			num[i] = num[i] * (p * 10);
			p *= 10;
		}
	}
	
	for (int i = 0; i < n; i++) cout << num[i] << endl;
	

	return 0;
}