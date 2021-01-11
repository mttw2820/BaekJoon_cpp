#include <iostream>
using namespace std;

int main() {
	int x; 
	cin >> x;

	int i;
	for (i = 1;; i++) {
		if (x - i > 0) x -= i;
		else break;
	}
	if (i % 2 == 1) cout << (i - x + 1) << "/" << (x) << endl;
	else cout << (x) << "/" << (i - x + 1) << endl;

	return 0;
}