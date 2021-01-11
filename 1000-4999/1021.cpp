//BaekJoon_1021
//회전하는 큐
/*
* 제한 시간 : 2s
* 정답 비율 : 47.990%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m, pos = 0, order, cnt = 0;
	vector<int> v;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		v.push_back(i);
	for (int i = 0; i < m; i++) {
		scanf("%d", &order);
		int left = 0, right = 0, tpos = pos;
		while (tpos >= 0 && v[tpos] != order) { tpos--; }
		if (tpos < 0) {
			// 벡터상에서 오른쪽에 위치
			tpos = pos;
			while (tpos < n && v[tpos] != order) tpos++;
			right = tpos - pos;
			left = n - right;
		}
		else {
			// 벡터 상 왼쪽에 위치
			left = pos - tpos;
			right = n - left;
		}
		cnt += min(left, right);
		v.erase(v.begin() + tpos, v.begin() + tpos + 1);
		if (tpos == n - 1) pos = 0;
		else pos = tpos;
		n--;
	}
	cout << cnt << endl;
	return 0;
}