#include <iostream>
using namespace std;
#include <algorithm>

int pack[50] = { 0, };
int single[50] = { 0, };
int main() {
	int n, m, s = 0;
	int pack_min, single_min;
	int cost = 0;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		//입력받기
		cin >> pack[i] >> single[i];
	}

	pack_min = pack[0];
	for (int i = 0; i < m; i++) {
		if (pack_min > min(pack[i], single[i] * 6))
			pack_min = min(pack[i], single[i] * 6);
	}
	
	single_min = pack_min;
	s = n % 6;
	for (int i = 0; i < m; i++) {
		if (single_min > single[i] * s)
			single_min = single[i] * s;
	}

	cost = pack_min * (n / 6) + single_min;
	cout << cost << endl;

	return 0;
}