//BaekJoon_2455
//지능형 기차
/*
 * 제한 시간 : 1s
 * 정답 비율 : 80.109%
 */

#include <iostream>
using namespace std;

int main() {
	int total = 0;
	int max_ppl = 0;
	for (int i = 0; i < 4; i++) {
		int off = 0, on = 0;
		cin >> off >> on;
		total = total - off + on;
		if (total > 10000) total = 10000;
		if (total > max_ppl) max_ppl = total;
	}
	cout << max_ppl << endl;
	return 0;
}