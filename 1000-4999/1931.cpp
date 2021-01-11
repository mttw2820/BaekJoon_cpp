#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
	int n, start, end, cnt = 0;
	vector<pair<int, int>> m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		m.push_back({ start, end });
	}
	sort(m.begin(), m.end(), comp);

	vector<pair<int, int>>::iterator it = m.begin();
	int check = 0;
	for (it = m.begin(); it != m.end(); it++) {
		if (check <= (*it).first) {
			cnt++;
			check = (*it).second;
		}
	}
	cout << cnt << endl;
	return 0;
}