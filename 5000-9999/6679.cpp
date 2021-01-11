//BaekJoon_6679
//�̱��� ���ڸ� ����
/*
* ���� �ð� : 1s
* ���� ���� : 76.772%
*/

#include <iostream>
using namespace std;

int main() {
	
	for (int n = 1000; n < 10000; n++) {
		int ten = 0, two = 0, six = 0;
		int temp_ten = n, temp_two = n, temp_six = n;
		while (temp_ten >= 10) {
			ten += temp_ten % 10;
			temp_ten /= 10;
		}
		ten += temp_ten;
		while (temp_two >= 12) {
			two += temp_two % 12;
			temp_two /= 12;
		}
		two += temp_two;
		while (temp_six >=16) {
			six += temp_six % 16;
			temp_six /= 16;
		}
		six += temp_six;
		if (ten == two && two == six) cout << n << endl;
	}

	return 0;
}