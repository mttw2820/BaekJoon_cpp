#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n, m;
	cin >> n;
	while (n--) {
		string key1[1001], key2[1001], res[1001];
		cin >> m;
		for (int i = 0; i < m; i++)
			cin >> key1[i];
		for (int i = 0; i < m; i++)
			cin >> key2[i];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				if (key1[j] == key2[i])
					cin >> res[j];
			}
		}
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}



/*
vector <string> key1;
vector <string> key2;
vector <string> ques(1000);
int main() {
	int testcase, len;
	string scan;
	cin >> testcase;
	while (testcase--) {
		cin >> len;
		for (int i = 0; i < len; i++) {
			cin >> scan;
			key1.push_back(scan);
		}
		for (int i = 0; i < len; i++) {
			cin >> scan;
			key2.push_back(scan);
		}
		for (int i = 0; i < len; i++) {
			cin >> scan;
			for (int j = 0; j < len; j++) {
				if (key2[i] == key1[j]) {
					ques[j] = scan;
				}
			}
		}

		for (int i = 0; i < len; i++)
			cout << ques[i] << " ";
		cout << endl;

		key1.clear();
		key2.clear();
	}

	return 0;
}
*/