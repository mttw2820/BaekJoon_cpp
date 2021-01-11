#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		char str[110];
		cin.getline(str, 110);
		int len = strlen(str);
		bool flag = false;
		for (int i = 0; i < len; i++) {
			if (!flag && str[i] == ' ') {
				printf("god");
				flag = true;
			}
			else if (!flag || (flag && str[i] == ' ')) continue;
			else printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}