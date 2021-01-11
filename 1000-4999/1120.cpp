#include <iostream>
using namespace std;
#include <string>

int main() {
	string x, y;
	int a, b, m = 50;
	cin >> x >> y;
	a = x.length();
	b = y.length();

	for (int i = 0; i <= b - a; i++) {
		int cnt = 0;
		for (int j = 0; j < a; j++) {
			if (x[j] != y[j+i])cnt++;
		}
		if (cnt < m) m = cnt;
	}
	cout << m << endl;

	return 0;
}