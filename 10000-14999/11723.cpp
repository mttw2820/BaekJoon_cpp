//BaekJoon_11723
//집합
/*
* 제한 시간 : 1.5s
* 정답 비율 : 29.251%
*/

#include <iostream>
#include <cstring>
using namespace std;

int add(int S, int x) {	return S | (1 << x); }
int remove(int S, int x) { return S & ~(1 << x); }
bool check(int S, int x) {
	if (S & (1 << x)) return true;
	else return false;
}
int toggle(int S, int x) { return S ^ (1 << x); }

int main() {
	int S = 0, n, x;
	char order[10];
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", order);
		if (!strcmp(order, "add")) {
			scanf("%d", &x);
			S = add(S, x);
		}
		else if (!strcmp(order, "remove")) {
			scanf("%d", &x);
			S = remove(S, x);
		}
		else if (!strcmp(order, "check")) {
			scanf("%d", &x);
			if (check(S, x)) printf("1\n");
			else printf("0\n");
		}
		else if (!strcmp(order, "toggle")) {
			scanf("%d", &x);
			S = toggle(S, x);
		}
		else if (!strcmp(order, "all")) {
			for (int k = 1; k < 21; k++)
				S = add(S, k);
		}
		else {	// empty
			S = 0;
		}
	}

	return 0;
}