//BaekJoon_2869
//�����̴� �ö󰡰� �ʹ�
/*
* ���� �ð� : 0.15s
* ���� ���� : 30.310%
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, v;
	int cnt = 0, height = 0;
	cin >> a >> b >> v;
	
	//ó������ while������ ���� �ð� �ʰ�
	//������ 1, 2ȸ ������ �̵��� ���� �Ÿ��� Ƚ���� �̸� ����Ѵ�.
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