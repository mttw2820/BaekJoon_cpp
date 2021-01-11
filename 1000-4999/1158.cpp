//BaekJoon_1158
//조세퍼스 문제
/*
* 제한 시간 : 2s
* 정답 비율 : 50.640%
*/
#include <iostream>
using namespace std;
#include <vector>

int main() {
	int n, k, now = 0;
	cin >> n >> k;
	vector<int> joseph;
	for (int i = 0; i < n; i++) {
		//자리 번호로 초기화
		joseph.push_back(i+1);
	}

	cout << "<";
	for (int i = 0; i < n-1; i++) {
		//현재 위치부터 1, 2, ... k 번째 위치니까 k-1만큼 더한다.
		now += k-1;
		//범위에서 벗어나면 1부터 다시 시작
		while (now >= joseph.size()) 
			now %= joseph.size();
		cout << joseph[now] << ", ";
		joseph.erase(joseph.begin() + now);
	}
	cout << joseph[0] << ">" << endl;

	return 0;
}