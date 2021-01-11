//BaekJoon_11404
//�÷��̵�
/*
* ���� �ð� : 1s
* ���� ���� : 45.763%
*/

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 99999999	// ����� ũ�� ���

int n, m;
long long dist[110][110] = { 0, };

/* Floyd Warshall */
void FW() {
	for (int k = 1; k <= n; k++) {	// �����ϴ� ����
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// city(i)���� city(j)�� ���� �Ÿ�
				if (i == j) continue;

				// i -> k -> j �� i -> j �Ÿ� ��
				if (dist[i][k] != INF && dist[k][j] != INF) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	// ���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = INF;
	}
	
	int a, b, c;
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

	FW();

	return 0;
}