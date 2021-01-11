#include <iostream>
using namespace std;
#include <cmath>

int n, r, c;
long long cnt = 0;
int siz = 0;

/* z_loc은 주어진 사각형을 네 구간으로 나누어 각 구간에 속해있는지 확인한다.
 * 속하지 않을 경우 그 공간 만큼의 숫자를 더하고
 * 속할 경우 재귀적으로 호출되어 해당 위치에 도달할 때까지
 * Z모양으로 탐색을 계속한다.
 */
void z_loc(int s_x, int s_y, int s) {
	if (s < 1) return;
	int line_x = s_x + s / 2;	//4등분하는 x의 기준
	int line_y = s_y + s / 2;	//4등분하는 y의 기준
	long long sq = pow(s/2, 2);		//4등분한 구간에 포함된 숫자의 갯수
	if ((c < line_x) && (r < line_y)) {
		z_loc(s_x, s_y, s / 2);
		return;
	}
	else cnt += sq;
	if ((c >= line_x) && (r < line_y)) {
		z_loc(line_x, s_y, s/2);
		return;
	}
	else cnt += sq;
	if ((c < line_x) && (r >= line_y)) {
		z_loc(s_x, line_y, s / 2);
		return;
	}
	else cnt += sq;
	if ((c >= line_x) && (r >= line_y)) {
		z_loc(line_x, line_y, s / 2);
		return;
	}
}

int main() {
	cin >> n >> r >> c;
	siz = pow(2, n);
	z_loc(0, 0, siz);

	cout << cnt << endl;
	return 0;
}