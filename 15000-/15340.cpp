//BaekJoon_15340
//Sim Card
/*
* 제한 시간 : 2s
* 정답 비율 : 94.366%
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int call[3] = { 30, 35, 40 };
	int data[3] = { 40, 30, 20 };

	while (1) {
		int c, d;
		int cost[3] = { 0,0,0 };
		cin >> c >> d;
		if (c == 0 && d == 0) break;
		
		for (int i = 0; i < 3; i++) {
			cost[i] = call[i] * c + data[i] * d;
		}
		sort(cost, cost + 3);
		cout << cost[0] << endl;
	}

	return 0;
}