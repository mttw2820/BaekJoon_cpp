//BaekJoon_2841
//외계인의 기타 연주
/*
* 제한 시간 : 1s
* 정답 비율 : 40.754%
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n, p, line, plet;
	long long cnt_move = 0;
	scanf("%d %d", &n, &p);
	stack<int> lines[10];

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &line, &plet);
		while (!lines[line].empty() && lines[line].top() > plet) {
			lines[line].pop();
			cnt_move++;
		}
		if (lines[line].empty() || lines[line].top() != plet) {
			lines[line].push(plet);
			cnt_move++;
		}
	}
	cout << cnt_move << endl;


	return 0;
}