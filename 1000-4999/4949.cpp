//BaekJoon_4949
//균형잡힌 세상
/*
* 제한 시간 : 1s
* 정답 비율 : 33.185%
*/

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
	vector<string> ans;

	while (1) {
		int flag = 0;
		stack<char> s;
		char c[101];
		scanf("%[^.\n]s", c);
		if (c[0] == '.') break;
		for (int i = 0; i < 101; i++) {
			if (c[i] == '.') break;
			else if (c[i] == '(') s.push('(');
			else if (c[i] == ')') {
				if (s.empty() || s.top() != '(') {
					flag = 1;
					break;
				}
				else s.pop();
			}
			else if (c[i] == '[') s.push('[');
			else if (c[i] == ']') {
				if (s.empty() || s.top() != '[') {
					flag = 1;
					break;
				}
				else s.pop();
			}
		}
		if (flag == 0) ans.push_back("yes");
		else ans.push_back("no");
		while (!s.empty()) s.pop();
	}
	for (int i = 0; i<int(ans.size()); i++) {
		cout << ans[i] << endl;
	}
}
