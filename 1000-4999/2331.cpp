//BaekJoon_2331
//반복수열
/*
* 제한 시간 : 2s
* 정답 비율 : 42.448%
*/

#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int seq[1000001] = { 0, };
bool comp(int a, int b) {
	return a > b;
}

int main() {
	int a, p;
	cin >> a >> p;
	
	int prev = a;
	int cnt = 1;
	while (seq[prev] == 0) {
		seq[prev] = cnt++;
		
		int now = 0;
		for (int i = 1; i <= prev; i*=10) {
			now += pow(prev % (i * 10) / i, p);
		}
		prev = now;
	}

	int cut_line = seq[prev];
	int ans = 0;
	sort(seq, seq + 1000000, comp);
	for (int i = 0; seq[i] != 0; i++) {
		if (seq[i] < cut_line) ans++;
	}
	cout << ans << endl;

	return 0;
}