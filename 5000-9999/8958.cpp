#include <iostream>
#include <string>
using namespace std;

int main() {
	int k;
	string s;
	cin >> k;
	while (k > 0) {
		k--;
		cin >> s;
		int score = 0, sum = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == 'O') {
				score++;
				sum += score;
			}
			else score = 0;
		}

		cout << sum << endl;
	}


	return 0;
}