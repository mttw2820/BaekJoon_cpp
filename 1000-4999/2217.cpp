#include <iostream>
#include <algorithm>
using namespace std;

bool comp(int x, int y) {
	return x > y;
}

int main() {
	int n, w=0;
	int rope[100000] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}

	sort(rope, rope + n, comp);
	for (int i = 0; i < n; i++) {
		if (w <= rope[i] * (i+1))
			w = rope[i] * (i+1);
	}
	cout << w << endl;

	return 0;
}