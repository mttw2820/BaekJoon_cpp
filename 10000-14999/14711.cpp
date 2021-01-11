#include <iostream>
using namespace std;

char fl[1001];
int map[1001][1001];
int test[1001][1001];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", fl);
	for (int i = 0; i < n; i++) {
		if (fl[i] == '#'){
			map[0][i] = 1;
			test[0][i] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (test[i][j])
		}
	}
	return 0;
}