//BaekJoon_11809
//YODA
/*
* 제한 시간 : 1s
* 정답 비율 : 66.265%
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
	int p1, p2;
	vector <int> a1, a2;
	cin >> p1 >> p2;
	for (int i = 0;; i++) {
		int temp = pow(10, i + 1);
		if (p1 < pow(10, i) && p2 < pow(10, i)) break;
		else if (p2 < pow(10, i)) {
			int x = (p1%temp) / pow(10, i);
			a1.push_back(x);
		}
		else if (p1 < pow(10, i)) {
			int y = (p2%temp) / pow(10, i);
			a2.push_back(y);
		}
		else {
			int x = (p1%temp) / pow(10, i);
			int y = (p2%temp) / pow(10, i);
			if (x == y) {
				a1.push_back(x);
				a2.push_back(y);
			}
			else if (x < y) {
				a2.push_back(y);
			}
			else if (x > y) {
				a1.push_back(x);
			}
		}
	}
	int sp = a1.size() - 1;
	while (sp > 0 && a1[sp] == 0) sp--;
	if (a1.size() == 0) printf("YODA");
	else {
		for (int i = sp; i >= 0; i--) {
			printf("%d", a1[i]);
		}
	}
	printf("\n");
	sp = a2.size() - 1;
	while (sp > 0 && a2[sp] == 0) sp--;
	if (a2.size() == 0) printf("YODA");
	else {
		for (int i = sp; i >= 0; i--) {
			printf("%d", a2[i]);
		}
	}
	printf("\n");
	return 0;
}