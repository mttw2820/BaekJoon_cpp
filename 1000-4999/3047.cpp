//BaekJoon_3047
//ABC
/*
 * 시간 제한 : 1s
 * 정답 비율 : 59.492%
 */


#include <iostream>
using namespace std;
#include <algorithm>

int main() {
	int num[4] = { 0, };
	char alpha[4];
	int order[4] = { 0, };
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}
	cin >> alpha;
	for (int i = 0; i < 3; i++) {
		order[i] = alpha[i] - 'A';
	}
	sort(num, num + 3);
	for (int i = 0; i < 3; i++) {
		cout << num[order[i]] << " ";
	}
	cout << endl;

	return 0;
}