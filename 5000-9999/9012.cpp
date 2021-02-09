//BaekJoon_9012
//괄호
/*
* 제한 시간 : 1s
* 정답 비율 : 41.725%
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <string> answer;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		string ps;
		cin >> ps;
		for (int j = 0; j < ps.length(); j++) {
			if (ps.at(j) == '(') cnt++;
			else if (ps.at(j) == ')')cnt--;
			if (cnt < 0) break;
		}
		if (cnt == 0) answer.push_back("YES");
		else answer.push_back("NO");
	}

	for (int i = 0; i < n; i++) {
		cout << answer[i] << endl;
	}

	return 0;
}