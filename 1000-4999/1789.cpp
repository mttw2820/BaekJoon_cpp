//BaekJoon_1789
//������ ��
/*
* ���� �ð� : 2s
* ���� ���� : 42.343%
*/

#include <iostream>
using namespace std;

int main() {
	long long sum = 0;
	cin >> sum;

	long long plus = 1;
	while (true) {
		sum -= plus;
		if (sum < 0) {
			plus--;
			break;
		}
		plus++;
	}

	cout << plus << endl;

	return 0;
}