//BaekJoon_1059
//수2
/*
* 제한 시간 : 2s
* 정답 비율 : 31.556%
*/

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int main() {
	int lucky, unlucky, temp;
	vector<int> lucky_set;
	cin >> lucky;
	for (int i = 0; i < lucky; i++) {
		cin >> temp;
		lucky_set.push_back(temp);
	}
	cin >> unlucky;
	
	int un_Max = 0, un_Min = 0, total = 0;
	sort(lucky_set.begin(), lucky_set.end());
	int i = 0;
	for (i = 0; i < lucky; i++) {
		if (lucky_set[i] >= unlucky) break;
	}
	if (lucky_set[i] == unlucky) total = 0;
	else {
		un_Min = lucky_set[i - 1] + 1;
		un_Max = lucky_set[i] - 1;
		// 1. [unlucky보다 작은 거, unlucky보다 큰 거] 구간
		// 2. [unlucky보다 작은 거, unlucky] 구간
		// 3. [unlucky, unlucky보다 큰 거] 구간
		total = (unlucky - un_Min)*(un_Max - unlucky) + (un_Max - un_Min);
	}
	cout << total << endl;

	return 0;
}