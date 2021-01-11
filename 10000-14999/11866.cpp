//BaekJoon_11866
//요세푸스 문제 0
/*
* 제한 시간 : 2s
* 정답 비율 : 58.736%
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> vec(n, 0);
	for (int i = 0; i < n; i++) {
		vec[i] = i + 1;
	}

	int now = 0;
	vector<int> ans;
	while (!vec.empty()) {
		now += (k - 1);
		now %= vec.size();
		
		ans.push_back(vec[now]);
		vec.erase(vec.begin() + now, vec.begin() + now + 1);
	}

	cout << "<";
	for (int i = 0; i < n - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[n - 1] << ">" << endl;

	return 0;
}