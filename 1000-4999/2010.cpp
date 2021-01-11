//BaekJoon_2010
//플러그
/*
* 제한 시간 : 2s
* 정답 비율 : 61.417%
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> plug;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		plug.push_back(temp);
	}

	sort(plug.begin(), plug.end());
	int empty = 1;
	for (int i = 0; i < n; i++) {
		if (empty == 0) break;
		empty--;
		empty += plug[i];
	}
	cout << empty << endl;

	return 0;
}