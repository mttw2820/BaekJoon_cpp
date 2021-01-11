//BaekJoon_14754
//Pizza Boxes
/*
* 제한 시간 : 1s
* 정답 비율 : 39.905%
*/

#include <iostream>
#include <vector>
using namespace std;



int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> v;
	vector<int> max_side(n, 0);
	vector<int> max_front(m, 0);
	for (int i = 0; i < n; i++) {
		vector<int> temp;
		int scan;
		for (int j = 0; j < m; j++) {
			scanf("%d", &scan);
			temp.push_back(scan);
			if (scan > max_side[i]) max_side[i] = scan;
		}
		v.push_back(temp);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (v[j][i] > max_front[i])
				max_front[i] = v[j][i];
		}
	}

	long long remove = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == max_side[i] || v[i][j] == max_front[j])
				continue;
			remove += v[i][j];
		}
	}

	cout << remove << endl;
	return 0;
}