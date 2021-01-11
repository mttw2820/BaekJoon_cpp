#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int alphabet[30] = { 0, };
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		alphabet[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		cout << alphabet[i] << " ";
	}

	return 0;
}