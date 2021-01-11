//BaekJoon_11650
//좌표 정렬하기
/*
* 제한 시간 : 1s
* 정답 비율 : 49.681%
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> loc;
bool sortLocation(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first < p2.first;
}
int main() {
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		loc.push_back(make_pair(x, y));
	}
	sort(loc.begin(), loc.end(), sortLocation);

	for (int i = 0; i < n; i++) {
		printf("%d %d\n", loc[i].first, loc[i].second);
	}

	return 0;
}