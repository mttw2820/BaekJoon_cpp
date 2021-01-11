//BaekJoon_1181
//ž
/*
* ���� �ð� : 2s
* ���� ���� : 38.872%
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool sort_by_length(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	else {
		return s1 < s2;
	}
}
int main() {
	int n;
	cin >> n;
	vector<string> dict(n);
	
	for (int i = 0; i < n; i++) {
		cin >> dict[i];
	}

	sort(dict.begin(), dict.end(), sort_by_length);
	// �ߺ� ����
	for (int i = 0; i < dict.size() - 1; i++) {
		if (dict[i] == dict[i + 1]) {
			dict.erase(dict.begin() + i, dict.begin() + i + 1);
			i--;
		}
	}

	for (int i = 0; i < dict.size(); i++) {
		cout << dict[i] << endl;
	}

	return 0;
}