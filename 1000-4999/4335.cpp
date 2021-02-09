//BaekJoon_4335
//숫자 맞추기
/*
* 제한 시간 : 1s
* 정답 비율 : 31.728%
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int check(int);
vector <int> A;		// honest = 0, dishonest = 1
int up[10], down[10], u = 0, d = 0;
int main() {
	
	while (1) {
		string temp, ans;
		int qst;
		cin >> qst;
		if (qst == 0) break;
		cin >> temp >> ans;
		if (ans == "high") {
			up[u++] = qst;
		}
		else if (ans == "low") {
			down[d++] = qst;
		}
		else if (ans == "on") { 
			int flag = check(qst);
			A.push_back(flag);
			u = d = 0;
		}
	}
	int s = A.size();
	for (int i = 0; i < s; i++) {
		if (A[i] == 1) cout << "Stan is dishonest" << endl;
		else if (A[i] == 0) cout << "Stan may be honest" << endl;
	}

	return 0;
}

int check(int x) {
	int a = 10, b = 0;		// a= max; b=min;
	if (u != 0) {
		a = up[0];
		for (int i = 1; i < u; i++) {
			if (up[i] > up[i - 1]) a = up[i];
		}
	}
	if (d != 0) {
		b = down[0];
		for (int i = 1; i < d; i++) {
			if (down[i] < down[i - 1]) b = down[i];
		}
	}
	
	if (b < x && x < a) return 0;
	else return 1;
}

