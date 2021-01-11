//BaekJoon_2869
//달팽이는 올라가고 싶다
/*
* 제한 시간 : 0.15s
* 정답 비율 : 30.310%
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, v;
	int cnt = 0, height = 0;
	cin >> a >> b >> v;
	
	//처음부터 while문으로 들어가면 시간 초과
	//마지막 1, 2회 정도의 이동만 남긴 거리와 횟수를 미리 계산한다.
	cnt = (v-a) / (a - b);
	height = cnt * (a - b);

	while (true) {
		if ((height += a) >= v) {
			cnt++;
			break;
		}
		else {
			height -= b;
			cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}