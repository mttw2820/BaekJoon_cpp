//BaekJoon_9625
//BABBA
/*
* ���� �ð� : 1s
* ���� ���� : 64.882%
*/

#include <iostream>
using namespace std;

int main() {
	// ���� A -> B, B -> BA
	int a = 1, b = 0;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp = a;
		a = b;
		b = b + temp;
	}
	cout << a << " " << b << endl;

	return 0;
}