#include <iostream>
#include <string>
using namespace std;

int main() {
	string s;
	int al[30] = { 0, };
	for (int i = 0; i < 26; i++) { al[i] = -1; }
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		int a = s[i] - 'a';
		if (al[a] == -1) {
			al[a] = i;
		}
	}
	
	for (int i = 0; i < 26; i++) {
		cout << al[i] << " ";
	}

	return 0;
}