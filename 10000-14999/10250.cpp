//BaekJoon_10250
//ACM ȣ��
/*
* ���� �ð� : 1s
* ���� ���� : 35.572%
*/

#include <iostream>
using namespace std;

int main() {
	int testcase = 0;
	cin >> testcase;
	while (testcase != 0) {
		int h, w, n;
		cin >> h >> w >> n;

		int floor = 0, door = 1;
		floor = n % h;
		door += n / h;

		if (floor == 0) {
			floor = h;
			door--;
		}

		cout << floor * 100 + door << endl;

		testcase--;
	}

	return 0;
}