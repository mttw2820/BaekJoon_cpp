#include <iostream>
#include <string>
using namespace std;

string rd[65];
string str;

void quad(int r, int c, int size) {
	if (size == 1) {
		cout << rd[r].at(c);
		return;
	}

	int check = 0;
	for (int k = 0; k < size; k++) {
		str = rd[r + k].substr(c, size);
		if (str.find("1") == string::npos) check++;		//1이 없으면
		if (str.find("0") == string::npos)check--;		//0이 없으면
	}

	if (check == size) {
		cout << 0;
		return;
	}
	else if (check == -size) {
		cout << 1;
		return;
	}
	else {
		cout << "(";
		int s = size / 2;
		quad(r, c, s);
		quad(r, c + s, s);
		quad(r + s, c, s);
		quad(r + s, c + s, s);
		cout << ")";
	}
	return;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rd[i];
	}
	quad(0, 0, n);
	return 0;
}