//BaekJoon_11403
//��� ã��
/*
* ���� �ð� : 1s
* ���� ���� : 51.867%
*/

#include <iostream>
#include <string.h>
using namespace std;

int n;
int graph[110][110] = { 0, };
int check[110] = { 0, };

void dfs(int start, int now) {
	// now���� �� �� �ִ� �� ã�� == start���� �� �� �ִ� ��
	for (int i = 0; i < n; i++) {
		if (graph[now][i] == 1 && check[i] == 0) {
			graph[start][i] = 1;
			check[i] = 1;
			dfs(start, i);
		}
	}
	return;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for(int j=0;j<n;j++)
			scanf("%d", &graph[i][j]);
	}

	for (int i = 0; i < n; i++) {
		// i���� ��� �� ������ �� �ִ� �� ��� ã��
		memset(check, 0, sizeof(check));
		dfs(i, i);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
	return 0;
}