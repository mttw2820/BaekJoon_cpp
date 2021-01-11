#include <iostream>
using namespace std;
#include <cmath>

int n, r, c;
long long cnt = 0;
int siz = 0;

/* z_loc�� �־��� �簢���� �� �������� ������ �� ������ �����ִ��� Ȯ���Ѵ�.
 * ������ ���� ��� �� ���� ��ŭ�� ���ڸ� ���ϰ�
 * ���� ��� ��������� ȣ��Ǿ� �ش� ��ġ�� ������ ������
 * Z������� Ž���� ����Ѵ�.
 */
void z_loc(int s_x, int s_y, int s) {
	if (s < 1) return;
	int line_x = s_x + s / 2;	//4����ϴ� x�� ����
	int line_y = s_y + s / 2;	//4����ϴ� y�� ����
	long long sq = pow(s/2, 2);		//4����� ������ ���Ե� ������ ����
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