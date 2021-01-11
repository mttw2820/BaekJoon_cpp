//BaekJoon_4949
//�������� ����
/*
* ���� �ð� : 1s
* ���� ���� : 33.936%
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	string str;

	while (true) {
		getline(cin, str);

		if ((str.length() == 1) && (str[0] = '.'))
			break;			// ���� ����

		int flag = 0;
		stack<char> bracket;
		for (int i = 0; i < str.length(); i++) {
			if ((str[i] == '(') || str[i] == '[')
				bracket.push(str[i]);
			else if ((str[i] == ')') || str[i] == ']') {
				if (bracket.empty()) {
					flag = -1;
					break;
				}
				if ((str[i] == ')') && (bracket.top() == '('))
					bracket.pop();
				else if ((str[i] == ']') && (bracket.top() == '['))
					bracket.pop();
				else {
					flag = -1;
					break;
				}
			}
			else continue;
		}
		if (!bracket.empty()) flag = -1;

		if (flag == -1) cout << "no" << endl;
		else cout << "yes" << endl;
	}

	return 0;
}