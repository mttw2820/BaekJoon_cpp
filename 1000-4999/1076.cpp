//BaekJoon_1076
//저항
/*
* 제한 시간 : 2s
* 정답 비율 : 39.852%
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string color[] = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };

int main() {
	string first, second, third;
	long long x, y, z;
	cin >> first >> second >> third;
	for (int i = 0; i < 10; i++) {
		if (first == color[i]) x = i;
		if (second == color[i]) y = i;
		if (third == color[i]) z = pow(10, i);
	}

	long long resist = (x * 10 + y) * z;
	cout << resist << endl;

	return 0;
}