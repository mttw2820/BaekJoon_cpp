//BaekJoon_1065
//한수
/*
* 제한 시간 : 2s
* 정답 비율 : 51.739%
*/

#include <iostream>
using namespace std;
#include <cstring>
#include <stdlib.h>

int main() {

	int count = 0;
	int N = 0;
	cin >> N;	//N<1000

	if (N < 100) count = N;
	else {
		count = 99;
		for (int i = 100; i <= N; i++) {
			int first = (i - (i % 100))/100;
			int second = ((i % 100) - (i % 10))/10;
			int third = i % 10;
			if ((first - second) == (second - third)) count++;
		}
	}

	cout << count << endl;
	
	return 0;
}