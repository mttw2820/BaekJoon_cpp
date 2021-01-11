#include <iostream>
using namespace std;

int main() {
	int coin[] = { 500, 100, 50, 10, 5, 1 };
	int pay, cnt = 0;
	cin >> pay;
	pay = 1000 - pay;
	for (int i = 0; i < 6; i++) {
		cnt += (pay / coin[i]);
		pay %= coin[i];
	}
	cout << cnt << endl;

	return 0;
}