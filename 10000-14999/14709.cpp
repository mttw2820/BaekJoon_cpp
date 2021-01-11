#include <iostream>
using namespace std;

int main() {
	int n, flag = 0;
	int x = 0, y = 0;
	int check[10][10] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		if (x == 2 || x == 5 || y == 2 || y == 2)
			flag = -1;
		check[x][y] = 1;
		check[y][x] = 1;
	}
	if (flag == -1) {
		printf("Woof-meow-tweet-squeek\n");
		return 0;
	}
	flag = check[1][3] + check[3][4] + check[1][4];
	if (flag == 3)
		printf("Wa-pa-pa-pa-pa-pa-pow!\n");
	else printf("Woof-meow-tweet-squeek\n");

	return 0;
}